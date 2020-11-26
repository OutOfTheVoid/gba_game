#include "drawing/fonts.hpp"
#include "drawing/basic_ranges.hpp"

static const bitmap_font_range_t * basic_ranges[] {
	& basic_alpha_range,
	& basic_caps_alpha_range,
	& basic_punct_1_range,
	& basic_numeric_range,
	& basic_punct_2_range
};

const bitmap_font_t font_basic {
	false,
	8,
	basic_ranges,
	sizeof(basic_ranges) / sizeof(bitmap_font_range_t *)
};
