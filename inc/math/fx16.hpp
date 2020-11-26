#ifndef MATH_FX16_HPP
#define MATH_FX16_HPP

#include <cstdint>

#include "fx16_config.hpp"

struct fx16_t;

fx16_t operator*(fx16_t lhs, fx16_t rhs);
fx16_t operator+(fx16_t lhs, fx16_t rhs);
fx16_t operator-(fx16_t lhs, fx16_t rhs);
fx16_t operator*(fx16_t lhs, fx16_t rhs);
fx16_t operator/(fx16_t lhs, fx16_t rhs);
int operator>(fx16_t lhs, fx16_t rhs);
int operator>=(fx16_t lhs, fx16_t rhs);
int operator <(fx16_t lhs, fx16_t rhs);
int operator <=(fx16_t lhs, fx16_t rhs);
int operator==(fx16_t lhs, fx16_t rhs);
int operator!=(fx16_t lhs, fx16_t rhs);
fx16_t operator<<(fx16_t lhs, int rhs);
fx16_t operator>>(fx16_t lhs, int rhs);
fx16_t operator%(fx16_t lhs, fx16_t rhs);

struct fx16_t {
	int32_t repr;
	
	enum class _Repr {
		Repr
	};
	
	inline fx16_t (_Repr r, int32_t repr):
		repr(repr) {
		(void) r;
	}
	
	inline fx16_t(int integer):
		repr(integer * 0x10000) {
	}
	
	inline fx16_t():
		repr(0) {
	}
	
	inline fx16_t(const fx16_t & copy_from):
		repr(copy_from.repr) {
	}
	
	inline fx16_t(const volatile fx16_t & copy_from):
		repr(copy_from.repr) {
	}
	
	inline fx16_t(fx16_t && move_from):
		repr(move_from.repr) {
	}
	
	inline fx16_t & operator=(const fx16_t & copy_from) {
		repr = copy_from.repr;
		return *this;
	}
	
	inline fx16_t & operator=(fx16_t && move_from) {
		repr = move_from.repr;
		return *this;
	}
	
	inline volatile fx16_t & operator=(const fx16_t & copy_from) volatile {
		this->repr = copy_from.repr;
		return *this;
	}
	
	inline volatile fx16_t & operator=(fx16_t && move_from) volatile {
		this->repr = move_from.repr;
		return *this;
	}
	
	inline int16_t int_part() const volatile {
		return repr >> 16;
	}
	
	inline uint16_t frac_part() const volatile {
		return static_cast<uint32_t>(repr) & 0xFFFF;
	}
	
	inline int32_t s_frac() const volatile {
		if (repr < 0) {
			return 0xFFFF0000 | repr;
		} else {
			return repr & 0xFFFF;
		}
	}
	
	inline fx16_t abs() const volatile {
		if (repr < 0) {
			return fx16_t(fx16_t::_Repr::Repr, - repr);
		}
		return *this;
	}
	
	inline fx16_t & operator+=(fx16_t rhs) {
		repr += rhs.repr;
		return *this;
	}
	
	inline volatile fx16_t & operator+=(fx16_t rhs) volatile {
		repr += rhs.repr;
		return *this;
	}
	
	inline fx16_t & operator-=(fx16_t rhs) {
		repr -= rhs.repr;
		return *this;
	}
	
	inline volatile fx16_t & operator-=(fx16_t rhs) volatile {
		repr -= rhs.repr;
		return *this;
	}
	
	inline fx16_t & operator*=(fx16_t rhs) {
		*this = (*this * rhs);
		return *this;
	}
	
	inline volatile fx16_t & operator*=(fx16_t rhs) volatile {
		this->repr = (*this * rhs).repr;
		return *this;
	}
	
	inline fx16_t & operator/=(fx16_t rhs) {
		this->repr = (*this / rhs).repr;
		return *this;
	}
	
	inline volatile fx16_t & operator/=(fx16_t rhs) volatile {
		this->repr = (*this / rhs).repr;
		return *this;
	}
	
	inline fx16_t & operator%=(fx16_t rhs) {
		*this = (*this % rhs);
		return *this;
	}
	
	inline volatile fx16_t & operator%=(fx16_t rhs) volatile {
		this->repr = (*this % rhs).repr;
		return *this;
	}
	
	inline fx16_t operator<<=(int32_t x) {
		*this = (*this << x);
		return *this;
	}
	
	inline volatile fx16_t operator<<=(int32_t x) volatile {
		this->repr = (*this << x).repr;
		return *this;
	}
	
	inline fx16_t operator>>=(int32_t x) {
		this->repr = (*this >> x).repr;
		return *this;
	}
	
	inline volatile fx16_t operator>>=(int32_t x) volatile {
		this->repr = (*this >> x).repr;
		return *this;
	}
	
	inline fx16_t operator-() const volatile {
		return fx16_t(fx16_t::_Repr::Repr, - repr);
	}
	
	static const fx16_t TAU;
	static const fx16_t PI;
	static const fx16_t PI_OVER_2;
	static const fx16_t SMALLEST_POSITIVE;
	static const fx16_t SMALLEST_NEGATIVE;
	static const fx16_t ZERO;
	static const fx16_t ONE;
	static const fx16_t NEG_ONE;
	static const fx16_t MAX;
	static const fx16_t MIN;
};

inline fx16_t operator +(fx16_t lhs, fx16_t rhs) {
	return fx16_t(fx16_t::_Repr::Repr, lhs.repr + rhs.repr);
}

inline fx16_t operator -(fx16_t lhs, fx16_t rhs) {
	return fx16_t(fx16_t::_Repr::Repr, lhs.repr - rhs.repr);
}

inline fx16_t operator *(fx16_t lhs, fx16_t rhs) {
	int64_t rep_lhs = lhs.repr;
	int64_t rep_rhs = rhs.repr;
	
	return fx16_t(fx16_t::_Repr::Repr, static_cast<int32_t>((rep_lhs * rep_rhs) >> 16));
}

inline fx16_t operator /(fx16_t lhs, fx16_t rhs) {
	int64_t rep_lhs = lhs.repr;
	int64_t rep_rhs = rhs.repr;
	
	return fx16_t(fx16_t::_Repr::Repr, static_cast<int32_t>((rep_lhs << 16) / rep_rhs));
}

inline int operator >(fx16_t lhs, fx16_t rhs) {
	return lhs.repr > rhs.repr;
}

inline int operator >=(fx16_t lhs, fx16_t rhs) {
	return lhs.repr >= rhs.repr;
}

inline fx16_t operator <<(fx16_t lhs, int rhs) {
	return fx16_t(fx16_t::_Repr::Repr, lhs.repr << rhs);
}

inline fx16_t operator >>(fx16_t lhs, int rhs) {
	return fx16_t(fx16_t::_Repr::Repr, lhs.repr >> rhs);
}

inline int operator <(fx16_t lhs, fx16_t rhs) {
	return (lhs.repr < rhs.repr);
}

inline int operator <=(fx16_t lhs, fx16_t rhs) {
	return lhs.repr <= rhs.repr;
}

inline int operator ==(fx16_t lhs, fx16_t rhs) {
	return lhs.repr == rhs.repr;
}

inline int operator !=(fx16_t lhs, fx16_t rhs) {
	return lhs.repr != rhs.repr;
}

inline fx16_t operator%(fx16_t lhs, fx16_t rhs) {
	return fx16_t(fx16_t::_Repr::Repr, lhs.repr % rhs.repr);
}

#ifdef FX16_CONFIG_ENABLE_SIN_COS
fx16_t sin_fx16(fx16_t x);
fx16_t cos_fx16(fx16_t x);
#endif

inline fx16_t max_fx16(fx16_t a, fx16_t b) {
	if (a > b) {
		return a;
	}
	return b;
}

inline fx16_t min_fx16(fx16_t a, fx16_t b) {
	if (a < b) {
		return a;
	}
	return b;
}

fx16_t sqrt_fx16(fx16_t x);
fx16_t exp_fx16(fx16_t x);
fx16_t log2_fx16(fx16_t x);
fx16_t ln_fx16(fx16_t x);
fx16_t pow_fx16(fx16_t x, fx16_t e);

const fx16_t TAU_FIX16;
const fx16_t PI_FIX16;
const fx16_t PI_OVER_2_FIX16;

#endif
