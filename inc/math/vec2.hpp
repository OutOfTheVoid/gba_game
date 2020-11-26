#ifndef MATH_VEC2_HPP
#define MATH_VEC2_HPP

#include "fx16.hpp"

class Vec2;

inline Vec2 operator*(const Vec2 & lhs, fx16_t rhs);

class Vec2 {
public:
	fx16_t x;
	fx16_t y;
	
	inline Vec2(fx16_t x = 0, fx16_t y = 0):
		x(x),
		y(y) {
	}
	
	inline static Vec2 lerp(const Vec2 & a, const Vec2 & b, fx16_t t) {
		fx16_t t_compl = 1 - t;
		return Vec2(a.x * t_compl + b.x * t, a.y * t_compl + b.y * t);
	}
	
	inline static fx16_t length(Vec2 v) {
		return sqrt_fx16(v.x * v.x + v.y * v.y);
	}
	
	inline static Vec2 normalize(Vec2 v) {
		return v * (fx16_t(1) / length(v));
	}
	
	inline static fx16_t dot(const Vec2 & a, const Vec2 & b) {
		return a.x * b.x + a.y * b.y;
	}
};

inline Vec2 operator+(const Vec2 & lhs, const Vec2 & rhs) {
	return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vec2 operator-(const Vec2 & lhs, const Vec2 & rhs) {
	return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vec2 operator*(const Vec2 & lhs, fx16_t rhs) {
	return Vec2(lhs.x * rhs, lhs.y * rhs);
}

class IVec2 {
public:
	int x;
	int y;
	
	inline IVec2(int x = 0, int y = 0):
		x(x),
		y(y) {
	}
};

inline IVec2 operator+(const IVec2 & lhs, const IVec2 & rhs) {
	return IVec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline IVec2 operator-(const IVec2 & lhs, const IVec2 & rhs) {
	return IVec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline IVec2 operator*(const IVec2 & lhs, int rhs) {
	return IVec2(lhs.x * rhs, lhs.y * rhs);
}

#endif
