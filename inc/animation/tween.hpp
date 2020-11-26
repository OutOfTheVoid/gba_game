#ifndef ANIMATION_TWEEN_HPP
#define ANIMATION_TWEEN_HPP

#include "math/fx16.hpp"

#define TWEEN_LOOP_FOREVER ((-1))

typedef fx16_t (* tween_easing_fn_t)(fx16_t);

class Tween {
public:
	Tween(fx16_t period, fx16_t (* const easing_fns[])(fx16_t x), void (* update_callback)(fx16_t x, void * data), void * data, int32_t loop_count = 0);
	
	void reset();
	void start();
	void restart();
	void pause();
	void update(fx16_t dt);
	
	int32_t loops_remaining();
	bool finished();
	
private:
	fx16_t period;
	fx16_t (* const * easing_fns)(fx16_t x);
	void (* update_callback)(fx16_t x, void * data);
	void * data;
	int32_t loop_count;
	int32_t loop_count_remaining;
	bool running;
	fx16_t t;
};

void tween_update_event_handler_fn(void * data);

#endif
