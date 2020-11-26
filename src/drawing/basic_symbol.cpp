#include "drawing/bitmap_font.hpp"
#include "drawing/basic_ranges.hpp"

const uint8_t basic_space_bitmap[] {
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
};

const uint8_t basic_bang_bitmap[] {
	0b10000000,
	0b10000000,
	0b10000000,
	0b00000000,
	0b10000000,
};

const uint8_t basic_quote_bitmap[] {
	0b10100000,
	0b10100000,
};

const uint8_t basic_pound_bitmap[] {
	0b01010000,
	0b11111000,
	0b01010000,
	0b11111000,
	0b01010000,
};

const uint8_t basic_dollar_sign_bitmap[] {
	0b00100000,
	0b01110000,
	0b10100000,
	0b01110000,
	0b00101000,
	0b01110000,
	0b00100000,
};

const uint8_t basic_percent_bitmap[] {
	0b01010000,
	0b00010000,
	0b00100000,
	0b01000000,
	0b01001000,
};

const uint8_t basic_ampersand_bitmap[] {
	0b01000000,
	0b10100000,
	0b01000000,
	0b10101000,
	0b10010000,
	0b01101000,
};

const uint8_t basic_apostrophe_bitmap[] {
	0b10000000,
	0b10000000,
};

const uint8_t basic_lparen_bitmap[] {
	0b01000000,
	0b10000000,
	0b10000000,
	0b10000000,
	0b10000000,
	0b01000000,
};

const uint8_t basic_rparen_bitmap[] {
	0b10000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b10000000,
};

const uint8_t basic_star_bitmap[] {
	0b10100000,
	0b01000000,
	0b10100000,
};

const uint8_t basic_plus_bitmap[] {
	0b01000000,
	0b11100000,
	0b01000000,
};

const uint8_t basic_comma_bitmap[] {
	0b01000000,
	0b01000000,
	0b10000000,
};

const uint8_t basic_dash_bitmap[] {
	0b11100000,
};

const uint8_t basic_dot_bitmap[] {
	0b10000000,
};

const uint8_t basic_fslash_bitmap[] {
	0b00100000,
	0b00100000,
	0b01000000,
	0b01000000,
	0b10000000,
	0b10000000,
};

static const bitmap_char_t basic_punct_1_chars[] { {
		2, // w
		0, // h
		0, // y offset
		basic_space_bitmap
	}, {
		2, // w
		5, // h
		2, // y offset
		basic_bang_bitmap
	}, {
		4, // w
		2, // h
		1, // y offset
		basic_quote_bitmap
	}, {
		6, // w
		5, // h
		1, // y offset
		basic_pound_bitmap
	}, {
		6, // w
		7, // h
		0, // y offset
		basic_dollar_sign_bitmap
	}, {
		6, // w
		5, // h
		1, // y offset
		basic_percent_bitmap
	}, {
		6,
		6,
		0,
		basic_ampersand_bitmap
	}, {
		2,
		2,
		1,
		basic_apostrophe_bitmap
	}, {
		3,
		6,
		1,
		basic_lparen_bitmap
	}, {
		3,
		6,
		1,
		basic_rparen_bitmap
	}, {
		4,
		3,
		1,
		basic_star_bitmap
	}, {
		4,
		3,
		2,
		basic_plus_bitmap
	}, {
		3,
		3,
		5,
		basic_comma_bitmap
	}, {
		4,
		1,
		3,
		basic_dash_bitmap
	}, {
		2,
		1,
		6,
		basic_dot_bitmap
	}, {
		4,
		6,
		1,
		basic_fslash_bitmap
	}
};

const bitmap_font_range_t basic_punct_1_range {
	' ',
	sizeof(basic_punct_1_chars) / sizeof(bitmap_char_t),
	basic_punct_1_chars
};

const uint8_t basic_colon_bitmap[] {
	0b10000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b10000000,
};

const uint8_t basic_semicolon_bitmap[] {
	0b01000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b01000000,
	0b10000000,
};

const uint8_t basic_l_triangle_bracket_bitmap[] {
	0b00010000,
	0b00100000,
	0b01000000,
	0b10000000,
	0b01000000,
	0b00100000,
	0b00010000,
};

const uint8_t basic_r_triangle_bracket_bitmap[] {
	0b10000000,
	0b01000000,
	0b00100000,
	0b00010000,
	0b00100000,
	0b01000000,
	0b10000000,
};

static const bitmap_char_t basic_punct_2_chars[] { {
		2,
		6,
		1,
		basic_colon_bitmap
	}, {
		3,
		6,
		2,
		basic_semicolon_bitmap
	}, {
		5,
		7,
		1,
		basic_l_triangle_bracket_bitmap
	}, {
		5,
		7,
		1,
		basic_r_triangle_bracket_bitmap
	}
};

const bitmap_font_range_t basic_punct_2_range {
	':',
	sizeof(basic_punct_2_chars) / sizeof(bitmap_char_t),
	basic_punct_2_chars
};
