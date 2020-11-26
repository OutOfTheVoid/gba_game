#include "animation/tween.hpp"

Tween::Tween(fx16_t period, fx16_t (* const easing_fns[])(fx16_t x), void (* update_callback)(fx16_t x, void * data), void * data, int32_t loop_count):
	period(period),
	easing_fns(easing_fns),
	update_callback(update_callback),
	data(data),
	loop_count(loop_count),
	loop_count_remaining(loop_count),
	running(false),
	t(fx16_t::ZERO) {
}

void Tween::reset() {
	t = fx16_t::ZERO;
	loop_count_remaining = loop_count;
}

void Tween::start() {
	running = true;
	fx16_t x = t;
	int e = 0;
	while(easing_fns[e] != nullptr) {
		x = easing_fns[e](x);
		e ++;
	}
	update_callback(x, data);
}

void Tween::restart() {
	t = fx16_t::ZERO;
	start();
}

void Tween::pause() {
	running = false;
}

void panic();

void Tween::update(fx16_t dt) {
	if (finished()) {
		return;
	}
	t += dt;
	
	fx16_t x = t;
	if (t >= 1) {
		t -= 1;
		x = 1;
		if (loop_count != -1) {
			loop_count_remaining --;
		}
	}
	int e = 0;
	while(easing_fns[e] != nullptr) {
		x = easing_fns[e](x);
		e ++;
	}
	update_callback(x, data);
}

int32_t Tween::loops_remaining() {
	return loop_count_remaining;
}

bool Tween::finished() {
	return loop_count != -1 && loop_count_remaining == -1;
}

void tween_update_event_handler_fn(void * data) {
	reinterpret_cast<Tween *>(data)->update(1 / fx16_t(60));
}
