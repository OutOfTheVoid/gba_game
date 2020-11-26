#ifndef ANIMATION_SPRITE_TWEEN_HPP
#define ANIMATION_SPRITE_TWEEN_HPP

#include "math/fx16.hpp"
#include "math/vec2.hpp"
#include "gba/sprite_manager.hpp"

struct sprite_position_tween_data_t {
	Vec2 p0;
	Vec2 p1;
	Sprite * sprite;
};

void sprite_position_tween_fn(fx16_t t, void * data);

#endif
