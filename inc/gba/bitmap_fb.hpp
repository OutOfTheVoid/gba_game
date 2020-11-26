#ifndef BITMAP_FB_HPP
#define BITMAP_FB_HPP

#include "hal.hpp"

#include <cstdint>

inline static void plot_mode3(int x, int y, uint16_t color) {
	GBA_MODE3_FRAMEBUFFER[x + y * GBA_MODE3_FRAMEBUFFER_W] = color;
}

inline static void plot_mode4(volatile uint16_t * framebuffer, int x, int y, uint8_t color_num) {
	if (x & 1) {
		framebuffer[(x >> 1) + GBA_MODE4_FRAMEBUFFER_W * y] = (framebuffer[(x >> 1) + GBA_MODE4_FRAMEBUFFER_W * y] & 0x00FF) | (static_cast<uint16_t>(color_num) << 8);
	} else {
		framebuffer[(x >> 1) + GBA_MODE4_FRAMEBUFFER_W * y] = (framebuffer[(x >> 1) + GBA_MODE4_FRAMEBUFFER_W * y] & 0xFF00) | color_num;
	}
}

inline static void plot_mode4_fast(volatile uint16_t * framebuffer, int half_x, int y, uint8_t left, uint8_t right) {
	framebuffer[half_x + y * GBA_MODE4_FRAMEBUFFER_W] = static_cast<uint16_t>(right) << 8 | left;
}

inline static void plot_mode5(volatile uint16_t * framebuffer, int x, int y, uint16_t color) {
	framebuffer[x + y * GBA_MODE5_FRAMEBUFFER_W] = color;
}

#endif
