#include "gba/hal.hpp"
#include "gba/interrupts.hpp"
#include "gba/bios.hpp"
#include "gba/sound_driver.hpp"
#include "gba/sprite.hpp"
#include "gba/pal_manager.hpp"
#include "gba/sprite_manager.hpp"
#include "gba/tile_manager.hpp"

#include "game/scene.hpp"
#include "util/vector.hpp"
#include "events/event.hpp"

#include "game/test_scene/test.hpp"

bool last_key_state;

Event update_event;
Event render_event;

SpriteManager sprite_manager;
TileManager tile_manager;
PalManager pal_manager;

extern "C" int main(void) {
	init_interrupts();
	init_vblank_intr_wait();
	
	sound_driver_init(true);
	
	init_oam();
	sprite_manager.init(0, 128);
	
	scene_events_t scene_events {
		update_event,
		render_event
	};
	
	set_active_scene(new TestScene());
	
	while (1){
		vblank_intr_wait();
		sound_driver_frame();
		render_event.dispatch();
		sprite_manager.update();
		update_event.dispatch();
		scene_update(scene_events);
	};
}

