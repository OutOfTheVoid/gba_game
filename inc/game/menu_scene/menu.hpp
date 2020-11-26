#ifndef GAME_SCENES_MENU_HPP
#define GAME_SCENES_MENU_HPP

#include "game/scene.hpp"

#include "gba/keys.hpp"
#include "gba/sprite_manager.hpp"
#include "gba/tile_manager.hpp"

#include "drawing/sprite_bitmap.hpp"

class MenuScene: public virtual Scene {
public:
	MenuScene();
	
	virtual void start(scene_events_t & events);
	virtual void stop(scene_events_t & events);
	
private:
	static void update_callback(void * scene);
	void update();
	
	uint32_t update_event;
	
	KeyMonitor key_monitor;
	
	Sprite test_sprite;
	SpriteBitmap test_bitmap;
};

#endif
