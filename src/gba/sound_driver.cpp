#include "gba/sound_driver.hpp"
#include "gba/hal.hpp"
#include "gba/interrupts.hpp"
#include "gba/timer.hpp"
#include "gba/util.hpp"

void sound_driver_vblank_intr();

/*
Possible configs:
=================
Timer: 62610, Rate:  5734, Buffer Size: 96,  Max Channel Count: 13
TImer: 63940, Rate: 10512, Buffer Size: 176, Max Channel Count: 7
TImer: 64282, Rate: 13379, Buffer Size: 224, Max Channel Count: 5
TImer: 64612, Rate: 18157, Buffer Size: 304, Max Channel Count: 4
TImer: 64738, Rate: 21024, Buffer Size: 352, Max Channel Count: 3
TImer: 64909, Rate: 26758, Buffer Size: 448, Max Channel Count: 2
*/

#define SOUND_TIMER_RELOAD 64282
#define SOUND_RATE 13379
#define SOUND_BUFFER_SIZE 224
#define SOUND_DRIVER_CHANNEL_COUNT 5

static sound_channel_t channels[SOUND_DRIVER_CHANNEL_COUNT];
int current_buffer_num;

sound_channel_t * alloc_sound_channel() {
	for (int i = 0; i < SOUND_DRIVER_CHANNEL_COUNT; i ++) {
		if (channels[i].status == SoundChannelStatus::Free) {
			return & channels[i];
		}
	}
	return nullptr;
}

static void channel_auto_free(sound_channel_t * channel, void * data) {
	(void) data;
	channel->status = SoundChannelStatus::Free;
}

bool play_sound_auto(sound_asset_t * asset, uint8_t volume, int32_t loop_count, int32_t restart_sample, int32_t end_sample) {
	sound_channel_t * channel = alloc_sound_channel();
	if (channel == nullptr) {
		return false;
	}
	channel -> status = SoundChannelStatus::Playing;
	channel -> callback_data = nullptr;
	channel -> on_end = & channel_auto_free;
	channel -> on_loop = nullptr;
	channel -> source_type = SoundSourceType::SoundAsset;
	channel -> restart_sample = restart_sample;
	channel -> end_sample = (end_sample <= -1) ? asset -> length : end_sample;
	channel -> loop_count = (loop_count <= -1) ? -1 : loop_count;
	channel -> next_sample = restart_sample;
	channel -> volume = volume;
	channel -> source.asset = asset;
	return true;
}

int8_t IWRAM ALIGN_4 sound_buffer[SOUND_BUFFER_SIZE * 2];
int IWRAM mix_buffer[SOUND_BUFFER_SIZE];

#define DMA_CONTROL_VALUE (( \
	GBA_DMA_CONTROL_DEST_ADJUST_FIXED | \
	GBA_DMA_CONTROL_CHUNK_SIZE_32 | \
	GBA_DMA_CONTROL_REPEATE | \
	GBA_DMA_CONTROL_TIMING_FIFO | \
	GBA_DMA_CONTROL_ENABLE \
))

void sound_driver_init(bool vblank_intr_master) {
	for (int i = 0; i < SOUND_BUFFER_SIZE * 2; i ++) {
		sound_buffer[i] = 0;
	}
	
	bool int_block = block_interrups();
	if (vblank_intr_master) {
		set_handler(Interrupt::VBlank, & sound_driver_vblank_intr);
	}
	
	GBA_SOUND_CONTROL_C = GBA_SOUND_CONTROL_C_MASTER_EN;
	GBA_SOUND_CONTROL_B = 
		GBA_SOUND_CONTROL_B_PCM_A_VOLUME_100 |
		GBA_SOUND_CONTROL_B_PCM_A_LEFT_EN |
		GBA_SOUND_CONTROL_B_PCM_A_RIGHT_EN;
	GBA_SOUND_FIFO_A = 0;
	
	GBA_DMA1_CONTROL = 0;
	GBA_DMA1_SOURCE = reinterpret_cast<uint32_t>(sound_buffer);
	GBA_DMA1_DESTINATION = reinterpret_cast<uint32_t>(& GBA_SOUND_FIFO_A);
	GBA_DMA1_CONTROL = DMA_CONTROL_VALUE;
	
	GBA_SOUND_CONTROL_B |= GBA_SOUND_CONTROL_B_PCM_A_DMA_RESET_FIFO;
	
	GBA_TIMER0_DATA = SOUND_TIMER_RELOAD;
	GBA_TIMER0_CONTROL = GBA_TIMER_CONTROL_EN;
	
	current_buffer_num = 0;
	restore_interrupts(int_block);
}

void sound_driver_vblank_intr() {
	if (current_buffer_num == 0) {
		GBA_DMA1_CONTROL = 0;
		GBA_DMA1_SOURCE = reinterpret_cast<uint32_t>(sound_buffer);
		GBA_DMA1_DESTINATION = reinterpret_cast<uint32_t>(& GBA_SOUND_FIFO_A);
		GBA_DMA1_CONTROL = DMA_CONTROL_VALUE;
		current_buffer_num = 1;
	} else {
		current_buffer_num = 0;
	}
}


void THUMB_CODE sound_driver_frame() {
	int8_t * target_buffer = & sound_buffer[(current_buffer_num) * SOUND_BUFFER_SIZE];
	static volatile uint32_t zero = 0;
	GBA_DMA3_CONTROL = 0;
	GBA_DMA3_DESTINATION = reinterpret_cast<uint32_t>(target_buffer);
	GBA_DMA3_SOURCE = reinterpret_cast<uint32_t>(& zero);
	GBA_DMA3_CONTROL = GBA_DMA_CONTROL_CHUNK_SIZE_32 | GBA_DMA_CONTROL_SOURCE_ADJUST_FIXED | GBA_DMA_CONTROL_ENABLE | (SOUND_BUFFER_SIZE >> 2);
	
	for (int i = 0; i < SOUND_DRIVER_CHANNEL_COUNT; i ++) {
		sound_channel_t & channel = channels[i];
		if (channel.status == SoundChannelStatus::Playing) {
			switch (channel.source_type) {
				case SoundSourceType::SoundAsset: {
					const sound_asset_t & asset = * channel.source.asset;
					int s = 0;
					while((s < SOUND_BUFFER_SIZE) && (channel.status == SoundChannelStatus::Playing)) {
						int mix_remaining = SOUND_BUFFER_SIZE - s;
						int asset_remaining = channel.end_sample - channel.next_sample;
						int read_size = (mix_remaining > asset_remaining) ? asset_remaining : mix_remaining;
						for (int i = 0; i < read_size; i += 2) {
							uint16_t bytes = * reinterpret_cast<const uint16_t *>(& asset.buffer[channel.next_sample + i]);
							target_buffer[s + i] += (static_cast<int8_t>(bytes) * channel.volume) >> 7;
							target_buffer[s + i + 1] += (static_cast<int8_t>(bytes >> 8) * channel.volume) >> 7;
						}
						channel.next_sample += read_size;
						s += read_size;
						if (channel.next_sample >= channel.end_sample) {
							if (channel.loop_count != 0) {
								if (channel.loop_count > 0) {
									channel.loop_count --;
								}
								channel.next_sample = channel.restart_sample;
								if (channel.on_loop != nullptr) {
									channel.on_loop(& channel, channel.callback_data);
								}
							} else {
								channel.status = SoundChannelStatus::Ended;
								if (channel.on_end != nullptr) {
									channel.on_end(& channel, channel.callback_data);
								}
								break;
							}
						}
					}
				} break;
				default: break;
			}
		}
	}
}

void sound_driver_stop() {
	GBA_DMA3_CONTROL = 0;
	GBA_SOUND_CONTROL_C = 0;
}
