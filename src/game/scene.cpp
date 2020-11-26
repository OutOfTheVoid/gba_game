#include "game/scene.hpp"

static Scene * active_scene = nullptr;
static Scene * next_active_scene = nullptr;

void scene_update(scene_events_t & events) {
	if (next_active_scene != active_scene) {
		if (active_scene != nullptr) {
			active_scene->stop(events);
		}
		active_scene = next_active_scene;
		if (active_scene != nullptr) {
			active_scene->start(events);
		}
	}
}

void set_active_scene(Scene * scene) {
	next_active_scene = scene;
}
