#ifndef GBA_AUDIO_HPP
#define GBA_AUDIO_HPP

#include <cstdint>

struct sound_asset_t {
	const int8_t * buffer;
	uint32_t length;
};

struct sound_buffer_t {
	int8_t * buffer;
	uint32_t length;
};

enum class SoundSourceFnResult {
	Success,
	End,
	FatalError,
};

typedef SoundSourceFnResult (* sound_source_fn_t)(sound_buffer_t * buffer_to_fill, uint32_t sample_index, void * data);

struct fn_sound_source_t {
	sound_source_fn_t * source_fn;
	void * data;
};

enum class SoundSourceType {
	SoundAsset,
	SoundBuffer,
	SourceFn,
};

enum class SoundChannelStatus {
	Free,
	Playing,
	Paused,
	Ended
};

struct sound_channel_t {
	SoundSourceType source_type;
	union {
		fn_sound_source_t source_fn;
		const sound_buffer_t * buffer;
		const sound_asset_t * asset;
	} source;
	
	int32_t loop_count;
	
	int32_t restart_sample;
	int32_t end_sample;
	int32_t next_sample;
	SoundChannelStatus status;
	
	uint8_t volume;
	
	void * callback_data;
	void (* on_loop)(sound_channel_t * channel, void * data);
	void (* on_end)(sound_channel_t * channel, void * data);
};

void sound_driver_init(bool vblank_intr_master);
void sound_driver_frame();
void sound_driver_vblank_intr();
void sound_driver_stop();

bool play_sound_auto(sound_asset_t * asset, uint8_t volume, int32_t loop_count = 0, int32_t restart_sample = 0, int32_t end_sample = -1);
// bool play_sound_auto(sound_buffer_t * buffer, int32_t volume, int32_t loop_count, int32_t restart_sample = 0, int32_t end_sample = -1);
// bool play_sound_auto(sound_source_fn_t * source, int32_t volume);

#endif /* GBA_AUDIO_HPP */
