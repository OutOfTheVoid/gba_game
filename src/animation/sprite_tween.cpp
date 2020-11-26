#include "animation/sprite_tween.hpp"

void sprite_position_tween_fn(fx16_t t, void * data) {
	const sprite_position_tween_data_t & tween_data = * reinterpret_cast<const sprite_position_tween_data_t *>(data);
	Vec2 position = Vec2::lerp(tween_data.p0, tween_data.p1, t);
	tween_data.sprite->set_position(position.x.int_part(), position.y.int_part());
}
