#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "events/event.hpp"

struct scene_events_t {
	Event & update_event;
	Event & render_event;
};

class Scene {
public:
	virtual void start(scene_events_t & events) = 0;
	virtual void stop(scene_events_t & events) = 0;
};

void scene_update(scene_events_t & events);
void set_active_scene(Scene * scene);

#endif
