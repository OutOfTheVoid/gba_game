#ifndef BITMAP_FONT_HPP
#define BITMAP_FONT_HPP

#include <cstdint>

struct bitmap_char_t {
	int8_t w;
	int8_t h;
	int8_t y_off;
	const uint8_t * bitmap;
};

struct bitmap_font_range_t {
	char start_char;
	uint8_t count;
	const bitmap_char_t * chars;
};

struct bitmap_font_t {
	bool case_sensetive;
	int8_t line_height;
	const bitmap_font_range_t ** ranges;
	uint32_t range_count;
};

#endif
