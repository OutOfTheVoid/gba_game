#include "math/fx16.hpp"

fx16_t sqrt_fx16(fx16_t x) {
	if (x <= fx16_t(0)) {
		return fx16_t(0);
	}
	int32_t value_repr = 0;
	int32_t bit = 23;
	while(bit >= 0) {
		fx16_t new_fixed(fx16_t::_Repr::Repr, value_repr | (1 << bit));
		if ((new_fixed * new_fixed) <= x) {
			value_repr |= (1 << bit);
		}
		bit --;
	}
	return fx16_t(fx16_t::_Repr::Repr, value_repr);
}

fx16_t log2_fx16(fx16_t x) {
	if (x <= fx16_t::ZERO) {
		return fx16_t::MIN;
	}
	fx16_t m = x;
	
	fx16_t accumulator = fx16_t::ZERO;
	while(m >= fx16_t(2)) {
		accumulator += fx16_t::ONE;
		m = m / fx16_t(2);
	}
	
	while (m < fx16_t::ONE) {
		accumulator -= fx16_t::ONE;
		m = m * fx16_t(2);
	}
	
	int32_t y = 0;
	for (int i = 0; i < 16; i ++) {
		y <<= 1;
		m = m * m;
		if (m >= fx16_t(2)) {
			m = m / fx16_t(2);
			y ++;
		}
	}
	return fx16_t(fx16_t::_Repr::Repr, y) + accumulator;
}

fx16_t ln_fx16(fx16_t x) {
	// log2(x) * ln(2) = ln(x)
	return log2_fx16(x) * fx16_t(fx16_t::_Repr::Repr, 45426);
}

fx16_t pow_fx16(fx16_t x, fx16_t e) {
	return exp_fx16(e * ln_fx16(x));
}

const fx16_t fx16_t::TAU(fx16_t::_Repr::Repr, 411774);
const fx16_t fx16_t::PI(fx16_t::_Repr::Repr, 205887);
const fx16_t fx16_t::PI_OVER_2(fx16_t::_Repr::Repr, 102943);
const fx16_t fx16_t::SMALLEST_POSITIVE(fx16_t::_Repr::Repr, 1);
const fx16_t fx16_t::SMALLEST_NEGATIVE(fx16_t::_Repr::Repr, -1);
const fx16_t fx16_t::ZERO(fx16_t::_Repr::Repr, 0);
const fx16_t fx16_t::ONE(fx16_t::_Repr::Repr, 0x10000);
const fx16_t fx16_t::NEG_ONE(-ONE);
const fx16_t fx16_t::MAX(fx16_t::_Repr::Repr, 0x7FFFFFFF);
const fx16_t fx16_t::MIN(fx16_t::_Repr::Repr, 0x80000000);
