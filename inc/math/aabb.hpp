#ifndef MATH_AABB_HPP
#define MATH_AABB_HPP

#include <cstdint>

#include "util.hpp"
#include "vec2.hpp"

struct IAABB {
	int32_t x_low;
	int32_t x_high;
	int32_t y_low;
	int32_t y_high;
	
	static IAABB make_invalid() {
		return IAABB(INT32_MAX, INT32_MIN, INT32_MAX, INT32_MIN);
	}
	
	inline IAABB(int32_t x_low = 0, int32_t x_high = 0, int32_t y_low = 0, int32_t y_high = 0):
		x_low(x_low),
		x_high(x_high),
		y_low(y_low),
		y_high(y_high) {
	}
	
	bool valid() const {
		return x_low <= x_high && y_low <= y_high;
	}
	
	bool contains(const IVec2 & t) const {
		return t.x >= x_low && t.x <= x_high && t.y >= y_low && t.y <= y_high;
	}
	
	inline static bool intersection(const IAABB & a, const IAABB & b, IAABB & out) {
		if (! a.valid() || ! b.valid()) {
			return false;
		}
		out.x_low = IMAX(a.x_low, b.x_low);
		out.y_low = IMAX(a.y_low, b.y_low);
		out.x_high = IMIN(a.x_high, b.x_high);
		out.y_high = IMIN(a.y_high, b.y_high);
		return out.valid();
	}
};

inline bool operator==(const IAABB & a, const IAABB & b) {
	return
		(a.x_low == b.x_low) &&
		(a.x_high == b.x_high) &&
		(a.y_low == b.y_low) &&
		(a.y_high == b.y_high);
}

#endif
