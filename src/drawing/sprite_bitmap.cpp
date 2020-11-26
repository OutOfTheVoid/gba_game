#include "drawing/sprite_bitmap.hpp"
#include "gba/tile.hpp"
#include "gba/hal.hpp"
#include "gba/cpp_rt.hpp"

SpriteBitmap::SpriteBitmap(SpriteSize size, bool ram_buffer):
	w(0),
	h(0),
	is_vram_type(true),
	sprite_size(size),
	tile_asset(0) {
	switch(size) {
		case SpriteSize::Size_8x8: {
			w = 8;
			h = 8;
			tile_asset = dynamic_tile_asset_4bpp_t(1);
		} break;
		case SpriteSize::Size_16x16: {
			w = 16;
			h = 16;
			tile_asset = dynamic_tile_asset_4bpp_t(4);
		} break;
		case SpriteSize::Size_32x32: {
			w = 32;
			h = 32;
			tile_asset = dynamic_tile_asset_4bpp_t(16);
		} break;
		case SpriteSize::Size_64x64: {
			w = 64;
			h = 64;
			tile_asset = dynamic_tile_asset_4bpp_t(64);
		} break;
		case SpriteSize::Size_8x16: {
			w = 8;
			h = 16;
			tile_asset = dynamic_tile_asset_4bpp_t(2);
		} break;
		case SpriteSize::Size_16x8: {
			w = 16;
			h = 8;
			tile_asset = dynamic_tile_asset_4bpp_t(2);
		} break;
		case SpriteSize::Size_8x32: {
			w = 8;
			h = 32;
			tile_asset = dynamic_tile_asset_4bpp_t(4);
		} break;
		case SpriteSize::Size_32x8: {
			w = 32;
			h = 8;
			tile_asset = dynamic_tile_asset_4bpp_t(4);
		} break;
		case SpriteSize::Size_16x32: {
			w = 16;
			h = 32;
			tile_asset = dynamic_tile_asset_4bpp_t(8);
		} break;
		case SpriteSize::Size_32x16: {
			w = 32;
			h = 16;
			tile_asset = dynamic_tile_asset_4bpp_t(8);
		} break;
		case SpriteSize::Size_32x64: {
			w = 32;
			h = 64;
			tile_asset = dynamic_tile_asset_4bpp_t(32);
		} break;
		case SpriteSize::Size_64x32: {
			w = 32;
			h = 64;
			tile_asset = dynamic_tile_asset_4bpp_t(32);
		} break;
	}
	vram_back_buffer = nullptr;
	set_buffer_state(ram_buffer);
}

SpriteBitmap::~SpriteBitmap() {
	set_buffer_state(false);
}

void SpriteBitmap::set_buffer_state(bool is_buffered) {
	if (is_buffered) {
		if (is_vram_type) {
			if (vram_back_buffer == nullptr) {
				vram_back_buffer = new tile_4bpp_t[tile_asset.tile_count];
			}
		} else {
			if (ram_back_buffer == nullptr) {
				ram_back_buffer = new uint8_t[(w * h + 1) & ~1];
			}
		}
	} else {
		if (is_vram_type) {
			if (vram_back_buffer != nullptr) {
				delete[] vram_back_buffer;
			}
		} else {
			if (ram_back_buffer != nullptr) {
				delete[] ram_back_buffer;
			}
		}
	}
}

bool SpriteBitmap::stage(TileManager & tile_manager) {
	return tile_manager.stage_asset(tile_asset, VramZone::Sprite);
}

void SpriteBitmap::unstage(TileManager & tile_manager) {
	tile_manager.unstage_asset(tile_asset);
}

void SpriteBitmap::clear(int color_num) {
	if (is_vram_type) {
		if (vram_back_buffer != nullptr) {
			for (int tile = 0; tile < tile_asset.tile_count; tile ++) {
				fill_tile_4bpp(vram_back_buffer[tile], color_num);
			}
		} else {
			if (tile_asset.ref_count != 0) {
				tile_4bpp_t fill_tile;
				fill_tile_4bpp(fill_tile, color_num);
				for (int tile = 0; tile < tile_asset.tile_count; tile ++) {
					copy_tile_4bpp(GBA_TILE_BLOCK_4BPP(tile_asset.block_num), tile_asset.tile_offset + tile, fill_tile);
				}
			}
		}
	} else {
		uint8_t color_value_2px = (color_num & 0x0F) | (color_num << 4);
		int buffer_size = (w * h + 1) & ~1;
		for (int i = 0; i < buffer_size; i ++) {
			ram_back_buffer[i] = color_value_2px;
		}
	}
}

void SpriteBitmap::draw_rect(int x, int y, int w, int h, int color) {
	if (x < 0) {
		w += x;
		x = 0;
	}
	if (y < 0) {
		h += y;
		y = 0;
	}
	if (x + w >= this->w) {
		w = this->w - x;
	}
	if (y + h >= this->h) {
		y = this->h - y;
	}
	if (h == 0 || w == 0) {
		return;
	}
	for (int i = x; i < x + w; i ++) {
		set_pixel(i, y, color);
		set_pixel(i, y + h - 1, color);
	}
	for (int j = y + 1; j < y + h - 1; j ++) {
		set_pixel(x, j, color);
		set_pixel(x + w - 1, j, color);
	}
}

void SpriteBitmap::draw_rect_filled(int x, int y, int w, int h, int color) {
	if (x < 0) {
		w += x;
		x = 0;
	}
	if (y < 0) {
		h += y;
		y = 0;
	}
	if (x + w >= this->w) {
		w = this->w - x;
	}
	if (y + h >= this->h) {
		y = this->h - y;
	}
	for (int j = y; j < y + h; j ++) {
		for (int i = x; i < x + w; i ++) {
			set_pixel(i, j, color);
		}
	}
}

void SpriteBitmap::set_pixel(int x, int y, int color) {
	if (x < 0 || x >= w || y < 0 || y >= h) {
		return;
	}
	if (is_vram_type) {
		if (vram_back_buffer != nullptr) {
			int w_tiles = w >> 3;
			int tile_x = x >> 3;
			int tile_y = y >> 3;
			blit_tile_4bpp(vram_back_buffer[tile_x + tile_y * w_tiles], x & 7, y & 7, color);
		} else if (tile_asset.ref_count != 0) {
			int tile = (x >> 3) + (y >> 3) * (w >> 3);
			int word = ((x & 7) >> 2) + ((y & 7) << 1);
			int nibble_shift = ((x & 3)) << 2;
			uint16_t word_copy = GBA_TILE_BLOCK_4BPP(tile_asset.block_num)[tile_asset.tile_offset + tile][word];
			word_copy &= ~(0x000F << nibble_shift);
			word_copy |= (color & 0x000F) << nibble_shift;
			GBA_TILE_BLOCK_4BPP(tile_asset.block_num)[tile_asset.tile_offset + tile][word] = word_copy;
		}
	} else if (ram_back_buffer != nullptr) {
		int pixel = x + y * w;
		ram_back_buffer[pixel >> 1] &= 0x0F << (((pixel & 1) ^ 1) << 2);
		ram_back_buffer[pixel >> 1] |= (color & 0x0F) << ((pixel & 1) << 2);
	}
}

void SpriteBitmap::copy_to_vram() {
	if (tile_asset.ref_count == 0 || ! is_vram_type || vram_back_buffer == nullptr) {
		return;
	}
	for (int tile = 0; tile < tile_asset.tile_count; tile ++) {
		copy_tile_4bpp(GBA_TILE_BLOCK_4BPP(tile_asset.block_num + 4), tile_asset.tile_offset + tile, vram_back_buffer[tile]);
	}
}

int SpriteBitmap::get_start_tile() {
	if (tile_asset.ref_count == 0) {
		return -1;
	}
	return tile_asset.tile_offset;// + (tile_asset.block_num == 5) ? 512 : 0;
}

void SpriteBitmap::draw_text(const char * text, const bitmap_font_t & font, int color, int x, int y, int text_w, int max_lines) {
	// bitmap font rendering
	int line = 0;
	int x_off = 0;
	int c = 0;
	// c-string traversal of text
	while (text[c] != '\0') {
		// search font for a character range containing the char in c
		int range = -1;
		for (uint32_t i = 0; i < font.range_count; i ++) {
			if ((font.ranges[i]->start_char <= text[c]) && 
				((font.ranges[i]->start_char + font.ranges[i]->count) > text[c])) {
				range = i;
				break;
			}
		}
		// if we found a range, render text!
		if (range != -1) {
			const bitmap_char_t & character_data = font.ranges[range]->chars[text[c] - font.ranges[range]->start_char];
			// text wrapping
			if (x_off + character_data.w >= text_w) {
				x_off = 0;
				line ++;
			}
			int char_y = y + line * font.line_height + character_data.y_off;
			int char_x = x + x_off;
			for (int i = 0; i < character_data.w; i ++) {
				for (int j = 0; j < character_data.h; j ++) {
					int bit = 7 - (i & 7);
					if (character_data.bitmap[j] & (1 << bit)) {
						set_pixel(char_x + i, char_y + j, color);
					}
				}
			}
			x_off += character_data.w;
		}
		if (text[c] == '\n') {
			x_off = 0;
			line ++;
			if (line >= max_lines) {
				return;
			}
		}
		c ++;
	}
}

