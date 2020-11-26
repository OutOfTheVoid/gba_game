#include "drawing/bitmap_font.hpp"
#include "drawing/basic_ranges.hpp"

const uint8_t basic_0_bitmap[] {
	0b01100000,
	0b10010000,
	0b11010000,
	0b10110000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_1_bitmap[] {
	0b01000000,
	0b11000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b11100000,
};

const uint8_t basic_2_bitmap[] {
	0b01100000,
	0b10010000,
	0b00010000,
	0b00100000,
	0b01000000,
	0b11110000,
};

const uint8_t basic_3_bitmap[] {
	0b01100000,
	0b10010000,
	0b00100000,
	0b00010000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_4_bitmap[] {
	0b10010000,
	0b10010000,
	0b11110000,
	0b00010000,
	0b00010000,
	0b00010000,
};

const uint8_t basic_5_bitmap[] {
	0b11110000,
	0b10000000,
	0b11100000,
	0b00010000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_6_bitmap[] {
	0b01100000,
	0b10000000,
	0b11100000,
	0b10010000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_7_bitmap[] {
	0b11110000,
	0b10010000,
	0b00100000,
	0b00100000,
	0b01000000,
	0b01000000,
};

const uint8_t basic_8_bitmap[] {
	0b01100000,
	0b10010000,
	0b01100000,
	0b10010000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_9_bitmap[] {
	0b01100000,
	0b10010000,
	0b10010000,
	0b01110000,
	0b00010000,
	0b01100000,
};

static const bitmap_char_t basic_numeric_chars[] { {
		5,
		6,
		1,
		basic_0_bitmap
	}, {
		4,
		6,
		1,
		basic_1_bitmap
	}, {
		5,
		6,
		1,
		basic_2_bitmap
	}, {
		5,
		6,
		1,
		basic_3_bitmap
	}, {
		5,
		6,
		1,
		basic_4_bitmap
	}, {
		5,
		6,
		1,
		basic_5_bitmap
	}, {
		5,
		6,
		1,
		basic_6_bitmap
	}, {
		5,
		6,
		1,
		basic_7_bitmap
	}, {
		5,
		6,
		1,
		basic_8_bitmap
	}, {
		5,
		6,
		1,
		basic_9_bitmap
	}
};

const bitmap_font_range_t basic_numeric_range {
	'0',
	sizeof(basic_numeric_chars)/sizeof(bitmap_char_t),
	basic_numeric_chars
};
