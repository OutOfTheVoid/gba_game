#include "game/collision/walk_area.hpp"

RectangleWalkArea::RectangleWalkArea(Vec2 position, Vec2 size):
	position(position),
	size(size) {
}

bool RectangleWalkArea::test_area(Vec2 walk_position) const {
	return (walk_position.x >= position.x) &&
		(walk_position.y >= position.y) &&
		(walk_position.x < position.x + size.x) &&
		(walk_position.y < position.y + size.y);
}

WalkAreaType RectangleWalkArea::type() const {
	return WalkAreaType::Rectangle;
}
