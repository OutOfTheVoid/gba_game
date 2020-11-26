#include "game/menu_scene/menu.hpp"
#include "game/menu_scene/assets.hpp"
#include "main.hpp"

#include "drawing/fonts.hpp"

#include "gba/str.hpp"

MenuScene::MenuScene():
	update_event(Event::InvalidEventID),
	test_sprite(),
	test_bitmap(SpriteSize::Size_64x64, false) {
}

static int frame;

void MenuScene::start(scene_events_t & events) {
	frame = 0;
	
	update_event = events.update_event.add_listener(& update_callback, reinterpret_cast<void *>(this));
	
	pal_manager.stage_asset(menu_button_palette_asset, VramZone::Sprite);
	
	test_bitmap.set_buffer_state(true);
	test_bitmap.stage(tile_manager);
	test_bitmap.clear(0);
	test_bitmap.copy_to_vram();
	
	test_sprite.set_color_mode(false);
	test_sprite.set_mode(SpriteMode::Regular);
	test_sprite.set_size(SpriteSize::Size_64x64);
	test_sprite.set_start_tile(test_bitmap.get_start_tile());
	test_sprite.set_palette(menu_button_palette_asset.pal_num);
	test_sprite.set_position(0, 0);
	test_sprite.set_flipping(false, false);
	sprite_manager.add_sprite(& test_sprite);
	
	GBA_DISPLAY_CONTROL = GBA_DSPCNT_MODE_0 | GBA_DSPCNT_TILE_MAP_1D | GBA_DSPCNT_ENABLE_SPRITE;
}
void MenuScene::stop(scene_events_t & events) {
	events.update_event.remove_listener(update_event);
	update_event = Event::InvalidEventID;
	
	pal_manager.unstage_asset(menu_button_palette_asset);
	test_bitmap.unstage(tile_manager);
	sprite_manager.remove_sprite(& test_sprite);
}

void MenuScene::update() {
	key_monitor.update();
	
	char num[40] {
		'F', 'r', 'a', 'm', 'e', ':', ' '
	};
	to_str_n(& num[7], 32, frame);
	
	test_bitmap.clear(0);
	test_bitmap.draw_text(num, font_basic, 1, 0, 0, 64, 7);
	test_bitmap.copy_to_vram();
	
	frame ++;
}

void MenuScene::update_callback(void * scene) {
	reinterpret_cast<MenuScene *>(scene)->update();
}
