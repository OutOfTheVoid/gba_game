#include "game/test_scene/test.hpp"
#include "main.hpp"

#include "gba/keys.hpp"

#include "game/collision/player_walk.hpp"
#include "game/collision/walk_area.hpp"

#include "gba/color.hpp"

#include "game/assets/boy1.hpp"
#include "game/assets/cat1.hpp"
#include "game/assets/bridge.hpp"

int boy_frame = 0;
int boy_walk_step = 0;

int cat_frame = 0;

enum class WalkDirection: int {
	Up = 0,
	UpStopped = 1,
	Down = 2,
	DownStopped = 3,
	Left = 4,
	LeftStopped = 5,
	Right = 6,
	RightStopped = 7,
};

bool walk_is_stopped(WalkDirection walk_dir) {
	return (static_cast<int>(walk_dir) & 1) != 0;
}

WalkDirection stop_walk_direction(WalkDirection walk_dir) {
	switch (walk_dir) {
		case WalkDirection::Up: return WalkDirection::UpStopped;
		case WalkDirection::Down: return WalkDirection::DownStopped;
		case WalkDirection::Left: return WalkDirection::LeftStopped;
		case WalkDirection::Right: return WalkDirection::RightStopped;
		default: break;
	}
	return walk_dir;
}

WalkDirection walk_direction;

TestScene::TestScene():
	Scene(),
	player_sprite(),
	cat_sprite(),
	camera_pos(),
	cat_pos(),
	bg(),
	walk_area1(Vec2(-1, 18), Vec2(308, 84)),
	walk_area2(Vec2(0, 0), Vec2(0, 0)),
	walk_area3(Vec2(0, 0), Vec2(0, 0)),
	test_walk_areas {
		& walk_area1,
		& walk_area2,
		& walk_area3,
	},
	test_walk_group(test_walk_areas, 3, 0),
	player_walk(Vec2(20, 20)) {
	player_walk.add_area_group(& test_walk_group);
	bg.add_area(& bridge_area_def, IVec2(-1, -10), true);
}

void TestScene::start(scene_events_t & events) {
	// boy 1 assets
	tile_manager.stage_asset(boy1_tile_asset, VramZone::Sprite);
	pal_manager.stage_asset(boy1_palette_asset, VramZone::Sprite);
	
	update_listener_id = events.update_event.add_listener(& update_listener, (void *) this);
	
	player_sprite.set_color_mode(false);
	player_sprite.set_palette(boy1_palette_asset.pal_num);
	player_sprite.set_start_tile(boy1_tile_asset.tile_offset);
	player_sprite.set_size(SpriteSize::Size_16x32);
	player_sprite.set_mode(SpriteMode::Regular);
	player_sprite.set_position(116, 65);
	sprite_manager.add_sprite(& player_sprite);
	
	tile_manager.stage_asset(cat1_tile_asset, VramZone::Sprite);
	pal_manager.stage_asset(cat1_palette_asset, VramZone::Sprite);
	
	cat_sprite.set_color_mode(false);
	cat_sprite.set_palette(cat1_palette_asset.pal_num);
	cat_sprite.set_start_tile(cat1_tile_asset.tile_offset);
	cat_sprite.set_size(SpriteSize::Size_16x16);
	cat_sprite.set_mode(SpriteMode::Regular);
	cat_sprite.set_position(80, 80);
	sprite_manager.add_sprite(& cat_sprite);
	
	bg.set_enabled(true);
	walk_direction = WalkDirection::DownStopped;
	
	GBA_DISPLAY_CONTROL = GBA_DSPCNT_MODE_0 | GBA_DSPCNT_TILE_MAP_1D | GBA_DSPCNT_ENABLE_SPRITE | GBA_DSPCNT_ENABLE_BG0;
}

void TestScene::stop(scene_events_t & events) {
	events.update_event.remove_listener(update_listener_id);
	
	sprite_manager.remove_sprite(& player_sprite);
	tile_manager.unstage_asset(boy1_tile_asset);
	pal_manager.unstage_asset(boy1_palette_asset);
	
	sprite_manager.remove_sprite(& cat_sprite);
	tile_manager.unstage_asset(cat1_tile_asset);
	pal_manager.unstage_asset(cat1_palette_asset);
	
	bg.set_enabled(false);
}

void TestScene::update() {
	boy_frame ++;
	cat_frame ++;
	Vec2 walk_dir(0, 0);
	
	if (key_down(Key::Up)) {
		walk_dir.y -= fx16_t(1);
	}
	if (key_down(Key::Down)) {
		walk_dir.y += fx16_t(1);
	}
	if (key_down(Key::Right)) {
		walk_dir.x += fx16_t(1);
	}
	if (key_down(Key::Left)) {
		walk_dir.x -= fx16_t(1);
	}
	if (boy_frame % 6 < 3) {
		walk_dir = walk_dir * fx16_t(2);
	}
	
	player_walk.walk(walk_dir);
	Vec2 player_pos = player_walk.get_position();
	
	camera_pos = Vec2(player_pos.x.int_part() - 120, player_pos.y.int_part() - 80);
	
	bg.set_camera_position(camera_pos);
	bg.update();
	
	cat_sprite.set_start_tile(cat1_tile_asset.tile_offset + ((cat_frame >> 5) % 3) * 4);
	cat_sprite.set_position((cat_pos.x - camera_pos.x).int_part(), (cat_pos.y.int_part() - camera_pos.y).int_part());
	
	WalkDirection old_walk_direction = walk_direction;
	if (walk_dir.x != 0 || walk_dir.y != 0) {
		if (walk_dir.y > 0) {
			walk_direction = WalkDirection::Down;
		}
		if (walk_dir.y < 0) {
			walk_direction = WalkDirection::Up;
		}
		if (walk_dir.x > 0) {
			walk_direction = WalkDirection::Right;
		}
		if (walk_dir.x < 0) {
			walk_direction = WalkDirection::Left;
		}
	} else {
		walk_direction = stop_walk_direction(walk_direction);
	}
	
	bool was_stopped = walk_is_stopped(old_walk_direction);
	bool is_stopped = walk_is_stopped(walk_direction);
	
	if (was_stopped != is_stopped) {
		boy_frame -= boy_frame % 5;
	}
	
	if (boy_frame % 5 == 0) {
		switch (walk_direction) {
			case WalkDirection::Down: {
				boy_walk_step ++;
				boy_walk_step %= 4;
				const int down_walk_boy_frames[] = {
					1, 0, 1, 2
				};
				player_sprite.set_start_tile(boy1_tile_asset.tile_offset + down_walk_boy_frames[boy_walk_step] * 8);
			} break;
			case WalkDirection::DownStopped: {
				boy_walk_step = 0;
				player_sprite.set_start_tile(boy1_tile_asset.tile_offset + 8);
			} break;
			case WalkDirection::Left: {
				boy_walk_step ++;
				boy_walk_step %= 4;
				const int left_walk_boy_frames[] = {
					3, 4, 3, 5
				};
				player_sprite.set_start_tile(boy1_tile_asset.tile_offset + left_walk_boy_frames[boy_walk_step] * 8);
			} break;
			case WalkDirection::LeftStopped: {
				boy_walk_step = 0;
				player_sprite.set_start_tile(boy1_tile_asset.tile_offset + 24);
			} break;
			case WalkDirection::Right: {
				boy_walk_step ++;
				boy_walk_step %= 4;
				const int right_walk_boy_frames[] = {
					6, 7, 6, 8
				};
				player_sprite.set_start_tile(boy1_tile_asset.tile_offset + right_walk_boy_frames[boy_walk_step] * 8);
			} break;
			case WalkDirection::RightStopped: {
				boy_walk_step = 0;
				player_sprite.set_start_tile(boy1_tile_asset.tile_offset + 48);
			} break;
			case WalkDirection::Up: {
				boy_walk_step ++;
				boy_walk_step %= 4;
				const int down_walk_boy_frames[] = {
					9, 10, 9, 11
				};
				player_sprite.set_start_tile(boy1_tile_asset.tile_offset + down_walk_boy_frames[boy_walk_step] * 8);
			} break;
			case WalkDirection::UpStopped: {
				boy_walk_step = 0;
				player_sprite.set_start_tile(boy1_tile_asset.tile_offset + 72);
			} break;
			default: break;
		}
	}
}

void TestScene::update_listener(void * this_ptr) {
	reinterpret_cast<TestScene *>(this_ptr)->update();
}
