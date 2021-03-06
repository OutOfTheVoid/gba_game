#ifndef GAME_SCENE_TEST_HPP
#define GAME_SCENE_TEST_HPP

#include "gba/sprite_manager.hpp"
#include "gba/hal.hpp"
#include "gba/scrolling_background.hpp"

#include "game/scene.hpp"

#include "game/collision/player_walk.hpp"
#include "game/collision/walk_area.hpp"

class TestScene: public virtual Scene {
public:
	TestScene();
	
	virtual void start(scene_events_t & events);
	virtual void stop(scene_events_t & events);
	
private:
	static void update_listener(void * this_ptr);
	uint32_t update_listener_id;
	void update();
	
	Sprite player_sprite;
	Sprite cat_sprite;
	
	Vec2 camera_pos;
	
	Vec2 cat_pos;
	
	ScrollingBackground bg;
	
	RectangleWalkArea walk_area1;
	RectangleWalkArea walk_area2;
	RectangleWalkArea walk_area3;
	const WalkArea * test_walk_areas[3];
	WalkAreaGroup test_walk_group;
	
	PlayerWalk player_walk;
};

#endif
