#include "math/fx16.hpp"

#ifdef FX16_CONFIG_ENABLE_SIN_COS
const int32_t _fx16_t_sin_lut[128] = {
	0, 804, 1608, 2412, 3215, 4018, 4821, 5622, 6423, 7223, 8022, 8819, 9616, 
	10410, 11204, 11995, 12785, 13573, 14359, 15142, 15923, 16702, 17479,
	18253, 19024, 19792, 20557, 21319, 22078, 22833, 23586, 24334, 25079,
	25820, 26557, 27291, 28020, 28745, 29465, 30181, 30893, 31600, 32302,
	32999, 33692, 34379, 35061, 35738, 36409, 37075, 37736, 38390, 39039,
	39682, 40319, 40950, 41575, 42194, 42806, 43412, 44011, 44603, 45189,
	45768, 46340, 46906, 47464, 48015, 48558, 49095, 49624, 50146, 50660,
	51166, 51665, 52155, 52639, 53114, 53581, 54040, 54491, 54933, 55368,
	55794, 56212, 56621, 57022, 57414, 57797, 58172, 58538, 58895, 59243,
	59583, 59913, 60235, 60547, 60850, 61144, 61429, 61705, 61971, 62228,
	62475, 62714, 62942, 63162, 63371, 63571, 63762, 63943, 64115, 64276,
	64428, 64571, 64703, 64826, 64939, 65043, 65136, 65220, 65294, 65358,
	65412, 65457, 65491, 65516, 65531
};

const fx16_t _256_OVER_PI_FIX16(fx16_t::_Repr::Repr, 5340353);

fx16_t sin_fx16(fx16_t x) {
	bool negate = (x < fx16_t(fx16_t::_Repr::Repr, 0));
	if (negate) {
		x = -x;
	}
	fx16_t table_position = ((x % fx16_t::TAU) * _256_OVER_PI_FIX16);
	int32_t low_table_offset = table_position.int_part() & 511;
	bool negate_low = false;
	switch(low_table_offset >> 7) {
		case 0:
			break;
		case 1:
			low_table_offset = 127 - (low_table_offset - 128);
			break;
		case 2:
			low_table_offset -= 256;
			negate_low = true;
			break;
		case 3:
			low_table_offset = 127 - (low_table_offset - 384);
			negate_low = true;
			break;
	}
	fx16_t v_low(fx16_t::_Repr::Repr, negate_low ? - _fx16_t_sin_lut[low_table_offset] : _fx16_t_sin_lut[low_table_offset]);
	int32_t high_table_offset = (table_position.int_part() + 1) & 511;
	bool negate_high = false;
	switch(high_table_offset >> 7) {
		case 0:
			break;
		case 1:
			high_table_offset = 127 - (high_table_offset - 128);
			break;
		case 2:
			high_table_offset -= 256;
			negate_high = true;
			break;
		case 3:
			high_table_offset = 127 - (high_table_offset - 384);
			negate_high = true;
			break;
	}
	fx16_t v_high(fx16_t::_Repr::Repr, negate_high ? - _fx16_t_sin_lut[high_table_offset] : _fx16_t_sin_lut[high_table_offset]);
	fx16_t lerp_factor = table_position % fx16_t(1);
	fx16_t complement_lerp_factor = fx16_t(1) - lerp_factor;
	fx16_t lerped = complement_lerp_factor * v_low + lerp_factor * v_high;
	return negate ? - lerped : lerped;
}

fx16_t cos_fx16(fx16_t x) {
	return sin_fx16(x + fx16_t::PI_OVER_2);
}
#endif

const int32_t _fx16_t_exp_01_lut[128] = {                                                                     
	65536, 66050, 66568, 67090, 67616, 68146, 68681, 69219, 69762, 70309,
	70861, 71417, 71977, 72541, 73110, 73684, 74262, 74844, 75431, 76023,
	76619, 77220, 77825, 78436, 79051, 79671, 80296, 80926, 81560, 82200,
	82845, 83495, 84149, 84809, 85475, 86145, 86821, 87502, 88188, 88879,
	89577, 90279, 90987, 91701, 92420, 93145, 93875, 94612, 95354, 96102,
	96855, 97615, 98381, 99152, 99930, 100714, 101504, 102300, 103102,
	103911, 104726, 105547, 106375, 107209, 108050, 108898, 109752, 110612,
	111480, 112354, 113236, 114124, 115019, 115921, 116830, 117746, 118670,
	119601, 120539, 121484, 122437, 123397, 124365, 125340, 126323, 127314,
	128313, 129319, 130333, 131356, 132386, 133424, 134471, 135525, 136588,
	137660, 138739, 139827, 140924, 142029, 143143, 144266, 145397, 146538,
	147687, 148845, 150013, 151189, 152375, 153570, 154775, 155989, 157212,
	158445, 159688, 160940, 162203, 163475, 164757, 166049, 167352, 168664,
	169987, 171320, 172664, 174018, 175383, 176758
};

const int32_t _fx16_t_exp_pow2_lut[4] = {
	178145, 484249, 3578144, 195360062
};

fx16_t exp_fx16(fx16_t x) {
	bool negative = x < fx16_t::ZERO;
	if (negative) {
		x = - x;
	}
	if (x.repr >= 726794) {
		return negative ? fx16_t::MIN : fx16_t::MAX;
	}
	int32_t int_part = x.int_part();
	int32_t frac_part = x.frac_part();
	int32_t table_position_low = frac_part >> 9;
	int32_t table_position_high = table_position_low + 1;
	fx16_t v_low = fx16_t(fx16_t::_Repr::Repr, _fx16_t_exp_01_lut[table_position_low]);
	fx16_t v_high = fx16_t(fx16_t::_Repr::Repr, (table_position_high == 128) ? _fx16_t_exp_pow2_lut[0] : _fx16_t_exp_01_lut[table_position_high]);
	fx16_t lerp_factor = fx16_t(fx16_t::_Repr::Repr, (frac_part & 0x1FF) << 7);
	fx16_t fractional_power = (lerp_factor * v_high + (fx16_t::ONE - lerp_factor) * v_low);
	fx16_t int_power = fx16_t::ONE;
	for (int i = 0; i < 3; i ++) {
		if (int_part & (1 << i)) {
			int_power *= fx16_t(fx16_t::_Repr::Repr, _fx16_t_exp_pow2_lut[i]);
		}
	}
	fx16_t result = int_power * fractional_power;
	if (negative) {
		return fx16_t::ONE / result;
	} else {
		return result;
	}
}
