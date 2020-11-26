#include "drawing/bitmap_font.hpp"
#include "drawing/basic_ranges.hpp"

const uint8_t basic_a_bitmap[] {
	0b01100000,
	0b00010000,
	0b01110000,
	0b10010000,
	0b01110000,
};

const uint8_t basic_b_bitmap[] {
	0b10000000,
	0b10000000,
	0b11100000,
	0b10010000,
	0b10010000,
	0b11100000,
};

const uint8_t basic_c_bitmap[] {
	0b01100000,
	0b10000000,
	0b10000000,
	0b01100000,
};

const uint8_t basic_d_bitmap[] {
	0b00010000,
	0b00010000,
	0b01110000,
	0b10010000,
	0b10010000,
	0b01110000,
};

const uint8_t basic_e_bitmap[] {
	0b01100000,
	0b10010000,
	0b11110000,
	0b10000000,
	0b01100000,
};

const uint8_t basic_f_bitmap[] {
	0b00100000,
	0b01000000,
	0b01000000,
	0b11100000,
	0b01000000,
	0b01000000,
};

const uint8_t basic_g_bitmap[] {
	0b01100000,
	0b10010000,
	0b10010000,
	0b01110000,
	0b00010000,
	0b01100000,
};

const uint8_t basic_h_bitmap[] {
	0b10000000,
	0b10000000,
	0b11100000,
	0b10010000,
	0b10010000,
	0b10010000,
};

const uint8_t basic_i_bitmap[] {
	0b10000000,
	0b00000000,
	0b10000000,
	0b10000000,
	0b10000000,
};

const uint8_t basic_j_bitmap[] {
	0b01000000,
	0b00000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b10000000,
};

const uint8_t basic_k_bitmap[] {
	0b10000000,
	0b10000000,
	0b10100000,
	0b11000000,
	0b10100000,
	0b10010000,
};

const uint8_t basic_l_bitmap[] {
	0b10000000,
	0b10000000,
	0b10000000,
	0b10000000,
	0b10000000,
	0b01000000,
};

const uint8_t basic_m_bitmap[] {
	0b10101000,
	0b01010100,
	0b01010100,
	0b01010100,
};

const uint8_t basic_n_bitmap[] {
	0b10100000,
	0b01010000,
	0b01010000,
	0b01010000,
};

const uint8_t basic_o_bitmap[] {
	0b01100000,
	0b10010000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_p_bitmap[] {
	0b01100000,
	0b10010000,
	0b10010000,
	0b11100000,
	0b10000000,
	0b10000000,
};

const uint8_t basic_q_bitmap[] {
	0b01100000,
	0b10010000,
	0b10010000,
	0b01110000,
	0b00010000,
	0b00010000,
};

const uint8_t basic_r_bitmap[] {
	0b10100000,
	0b11000000,
	0b10000000,
	0b10000000,
};

const uint8_t basic_s_bitmap[] {
	0b01110000,
	0b10000000,
	0b01100000,
	0b00010000,
	0b11100000,
};

const uint8_t basic_t_bitmap[] {
	0b01000000,
	0b01000000,
	0b11100000,
	0b01000000,
	0b01000000,
	0b00100000,
};

const uint8_t basic_u_bitmap[] {
	0b10100000,
	0b10100000,
	0b10100000,
	0b01010000,
};

const uint8_t basic_v_bitmap[] {
	0b10100000,
	0b10100000,
	0b01000000,
	0b01000000,
};

const uint8_t basic_w_bitmap[] {
	0b10101000,
	0b10101000,
	0b01010000,
	0b01010000,
};

const uint8_t basic_x_bitmap[] {
	0b10100000,
	0b01000000,
	0b01000000,
	0b10100000,
};

const uint8_t basic_y_bitmap[] {
	0b10010000,
	0b10010000,
	0b10010000,
	0b01110000,
	0b00010000,
	0b01100000,
};

const uint8_t basic_z_bitmap[] {
	0b11110000,
	0b00100000,
	0b01000000,
	0b11110000,
};

static const bitmap_char_t basic_alpha_chars[] { {
		5, // w
		5, // h
		2, // y offset
		basic_a_bitmap
	}, {
		5, // w
		6, // h
		1, // y offset
		basic_b_bitmap
	}, {
		4, // w
		4, // h
		3, // y offset
		basic_c_bitmap
	}, {
		5, // w
		6, // h
		1, // y offset
		basic_d_bitmap
	}, {
		5, // w
		5, // h
		2, // y offset
		basic_e_bitmap
	}, {
		4, // w
		6, // h
		1, // y offset
		basic_f_bitmap
	}, {
		5, // w
		6, // h
		3, // y offset
		basic_g_bitmap
	}, {
		5, // w
		6, // h
		1, // y offset
		basic_h_bitmap
	}, {
		2, // w
		5, // h
		2, // y offset
		basic_i_bitmap
	}, {
		3, // w
		7, // h
		2, // y offset
		basic_j_bitmap
	}, {
		5, // w
		6, // h
		1, // y offset
		basic_k_bitmap
	}, {
		3, // w
		6, // h
		1, // y offset
		basic_l_bitmap
	}, {
		7, // w
		4, // h
		3, // y offset
		basic_m_bitmap
	}, {
		5, // w
		4, // h
		3, // y offset
		basic_n_bitmap
	}, {
		5, // w
		4, // h
		3, // y offset
		basic_o_bitmap
	}, {
		5, // w
		6, // h
		3, // y offset
		basic_p_bitmap
	}, {
		5, // w
		6, // h
		3, // y offset
		basic_q_bitmap
	}, {
		4, // w
		4, // h
		3, // y offset
		basic_r_bitmap
	}, {
		5, // w
		5, // h
		2, // y offset
		basic_s_bitmap
	}, {
		4, // w
		6, // h
		1, // y offset
		basic_t_bitmap
	}, {
		5, // w
		4, // h
		3, // y offset
		basic_u_bitmap
	}, {
		4, // w
		4, // h
		3, // y offset
		basic_v_bitmap
	}, {
		6, // w
		4, // h
		3, // y offset
		basic_w_bitmap
	}, {
		4, // w
		4, // h
		3, // y offset
		basic_x_bitmap
	}, {
		5, // w
		6, // h
		3, // y offset
		basic_y_bitmap
	}, {
		5, // w
		4, // h
		3, // y offset
		basic_z_bitmap
	},
};

const bitmap_font_range_t basic_alpha_range {
	'a',
	sizeof(basic_alpha_chars) / sizeof(bitmap_char_t),
	basic_alpha_chars
};

const uint8_t basic_A_bitmap[] {
	0b01100000,
	0b10010000,
	0b10010000,
	0b11110000,
	0b10010000,
	0b10010000,
};

const uint8_t basic_B_bitmap[] {
	0b11100000,
	0b10010000,
	0b11100000,
	0b10010000,
	0b10010000,
	0b11100000,
};

const uint8_t basic_C_bitmap[] {
	0b01100000,
	0b10010000,
	0b10000000,
	0b10000000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_D_bitmap[] {
	0b11100000,
	0b10010000,
	0b10010000,
	0b10010000,
	0b10010000,
	0b11100000,
};

const uint8_t basic_E_bitmap[] {
	0b11110000,
	0b10000000,
	0b11110000,
	0b10000000,
	0b10000000,
	0b11110000,
};

const uint8_t basic_F_bitmap[] {
	0b11110000,
	0b10000000,
	0b11110000,
	0b10000000,
	0b10000000,
	0b10000000,
};

const uint8_t basic_G_bitmap[] {
	0b01100000,
	0b10010000,
	0b10000000,
	0b10110000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_H_bitmap[] {
	0b10010000,
	0b10010000,
	0b11110000,
	0b10010000,
	0b10010000,
	0b10010000,
};

const uint8_t basic_I_bitmap[] {
	0b11100000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b11100000,
};

const uint8_t basic_J_bitmap[] {
	0b01110000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b11000000,
};

const uint8_t basic_K_bitmap[] {
	0b10010000,
	0b10100000,
	0b11000000,
	0b11100000,
	0b10010000,
	0b10010000,
};

const uint8_t basic_L_bitmap[] {
	0b10000000,
	0b10000000,
	0b10000000,
	0b10000000,
	0b10000000,
	0b11100000,
};

const uint8_t basic_M_bitmap[] {
	0b10001000,
	0b11011000,
	0b10101000,
	0b10001000,
	0b10001000,
	0b10001000,
};

const uint8_t basic_N_bitmap[] {
	0b10001000,
	0b11001000,
	0b10101000,
	0b10101000,
	0b10011000,
	0b10001000,
};

const uint8_t basic_O_bitmap[] {
	0b01100000,
	0b10010000,
	0b10010000,
	0b10010000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_P_bitmap[] {
	0b11100000,
	0b10010000,
	0b10010000,
	0b11100000,
	0b10000000,
	0b10000000,
};

const uint8_t basic_Q_bitmap[] {
	0b01100000,
	0b10010000,
	0b10010000,
	0b10110000,
	0b10010000,
	0b01101000,
};

const uint8_t basic_R_bitmap[] {
	0b11100000,
	0b10010000,
	0b10010000,
	0b11100000,
	0b10100000,
	0b10010000,
};

const uint8_t basic_S_bitmap[] {
	0b01110000,
	0b10000000,
	0b01100000,
	0b00010000,
	0b00010000,
	0b11100000,
};

const uint8_t basic_T_bitmap[] {
	0b11100000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
};

const uint8_t basic_U_bitmap[] {
	0b10010000,
	0b10010000,
	0b10010000,
	0b10010000,
	0b10010000,
	0b01100000,
};

const uint8_t basic_V_bitmap[] {
	0b10100000,
	0b10100000,
	0b10100000,
	0b10100000,
	0b01000000,
	0b01000000,
};

const uint8_t basic_W_bitmap[] {
	0b10001000,
	0b10001000,
	0b10001000,
	0b10101000,
	0b01010000,
	0b01010000,
};

const uint8_t basic_X_bitmap[] {
	0b10100000,
	0b10100000,
	0b01000000,
	0b01000000,
	0b10100000,
	0b10100000,
};

const uint8_t basic_Y_bitmap[] {
	0b10010000,
	0b10010000,
	0b01100000,
	0b00100000,
	0b01000000,
	0b01000000,
};

const uint8_t basic_Z_bitmap[] {
	0b11110000,
	0b00010000,
	0b00100000,
	0b01000000,
	0b10000000,
	0b11110000,
};

static const bitmap_char_t basic_caps_alpha_chars[] { {
		5,
		6,
		1,
		basic_A_bitmap
	}, {
		5,
		6,
		1,
		basic_B_bitmap
	}, {
		5,
		6,
		1,
		basic_C_bitmap
	}, {
		5,
		6,
		1,
		basic_D_bitmap
	}, {
		5,
		6,
		1,
		basic_E_bitmap
	}, {
		5,
		6,
		1,
		basic_F_bitmap
	}, {
		5,
		6,
		1,
		basic_G_bitmap
	}, {
		5,
		6,
		1,
		basic_H_bitmap
	}, {
		4,
		6,
		1,
		basic_I_bitmap
	}, {
		5,
		6,
		1,
		basic_J_bitmap
	}, {
		5,
		6,
		1,
		basic_K_bitmap
	}, {
		5,
		6,
		1,
		basic_L_bitmap
	}, {
		6,
		6,
		1,
		basic_M_bitmap
	}, {
		6,
		6,
		1,
		basic_N_bitmap
	}, {
		5,
		6,
		1,
		basic_O_bitmap
	}, {
		5,
		6,
		1,
		basic_P_bitmap
	}, {
		6,
		6,
		1,
		basic_Q_bitmap
	}, {
		5,
		6,
		1,
		basic_R_bitmap
	}, {
		5,
		6,
		1,
		basic_S_bitmap
	}, {
		4,
		6,
		1,
		basic_T_bitmap
	}, {
		5,
		6,
		1,
		basic_U_bitmap
	}, {
		4,
		6,
		1,
		basic_V_bitmap
	}, {
		6,
		6,
		1,
		basic_W_bitmap
	}, {
		4,
		6,
		1,
		basic_X_bitmap
	}, {
		5,
		6,
		1,
		basic_Y_bitmap
	}, {
		5,
		6,
		1,
		basic_Z_bitmap
	}
};

const bitmap_font_range_t basic_caps_alpha_range {
	'A',
	sizeof(basic_caps_alpha_chars) / sizeof(bitmap_char_t),
	basic_caps_alpha_chars
};