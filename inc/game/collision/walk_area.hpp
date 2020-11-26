#ifndef GAME_COLLISION_WALK_AREA_HPP
#define GAME_COLLISION_WALK_AREA_HPP

#include "math/fx16.hpp"
#include "math/vec2.hpp"

enum class WalkAreaType {
	Rectangle,
	TriangleList,
};

class WalkArea {
public:
	virtual bool test_area(Vec2 walk_position) const = 0;
	virtual WalkAreaType type() const = 0;
};

class RectangleWalkArea: public virtual WalkArea {
public:
	RectangleWalkArea(Vec2 position, Vec2 size);
	
	virtual bool test_area(Vec2 walk_position) const;
	virtual WalkAreaType type() const;
	
private:
	Vec2 position;
	Vec2 size;
};

struct triangle_t {
	Vec2 a;
	Vec2 b;
	Vec2 c;
};

/*
class TriangleMeshWalkArea: public virtual WalkArea {
public:
	RectangleWalkArea(const triangle_t * triangles, uint32_t tri_count);
	
	virtual bool test_area(Vec2 walk_position) const;
	virtual WalkAreaType type() const;
	
private:
	Vec2 position;
	const triangle_t * triangles;
	uint32_t tri_count;
};
*/

#endif
