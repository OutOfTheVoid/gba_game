#include "game/test_scene/test.hpp"
#include "game/test_scene/assets.hpp"
#include "main.hpp"

#include "gba/keys.hpp"

#include "game/collision/player_walk.hpp"
#include "game/collision/walk_area.hpp"

#include "gba/color.hpp"

const uint16_t test_dyn_bg_tilepatch_data[] {
	1,  1,  1,  1,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  20, 2,  2,  19, 6,  6,  20, 2,  2,  19, 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  21, 11, 11, 5,  6,  6,  21, 11, 11, 5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  21, 11, 11, 5,  6,  6,  21, 11, 11, 5,  6,  8,  2,  2,  9,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  16, 18, 18, 17, 6,  6,  16, 18, 18, 17, 6,  7,  14, 15, 5,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  7,  12, 13, 5,  6,  6,  6,  6,  6,
	1,  1,  1,  1,  3,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4,  10, 10, 3,  2,  2,  2,  2,  2,
	1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
};

const bg_tile_patch_t test_dyn_bg_tilepatch {
	test_dyn_bg_tilepatch_data,
	28,
	15
};

const palette_16_t test_dyn_pal_2 {
	RGB(0,   0,   0),
	RGB(20,  20,  20),
	RGB(16,  16,  16),
	RGB(4,   20,   4),
	RGB(14,  20,   0),
	RGB(14,  14,  14),
	RGB(27,  31,  14),
	RGB(23,  27,  10),
	RGB(6,   6,   6),
};

palette_16_asset_t test_dyn_pal_2_asset(& test_dyn_pal_2);

const bg_area_def_t test_bg_area {
	& test_bg_palette_asset,
	& test_dyn_bg_tilepatch,
	& test_bg_tile_pack	
};

const bg_area_def_t test_bg_area2 {
	& test_dyn_pal_2_asset,
	& test_dyn_bg_tilepatch,
	& test_bg_tile_pack	
};

TestScene::TestScene():
	Scene(),
	player_sprite(),
	bg_scene(),
	walk_area1(Vec2(5, 6), Vec2(23, 113)),
	walk_area2(Vec2(28, 97), Vec2(1190, 21)),
	walk_area3(Vec2(165, 92), Vec2(7, 5)),
	test_walk_areas {
		& walk_area1,
		& walk_area2,
		& walk_area3,
	},
	test_walk_group(test_walk_areas, 3, 0),
	player_walk(Vec2(20, 20)) {
	player_walk.add_area_group(& test_walk_group);
	bg_scene.add_area(& test_bg_area, IVec2(0, 0), true);
	bg_scene.add_area(& test_bg_area2, IVec2(-28, 0), true);
}

void TestScene::start(scene_events_t & events) {
	tile_manager.stage_asset(test_player_tile_asset, VramZone::Sprite);
	pal_manager.stage_asset(test_player_palette_asset, VramZone::Sprite);
	
	update_listener_id = events.update_event.add_listener(& update_listener, (void *) this);
	
	player_sprite.set_color_mode(false);
	player_sprite.set_palette(test_player_palette_asset.pal_num);
	player_sprite.set_start_tile(test_player_tile_asset.tile_offset);
	player_sprite.set_size(SpriteSize::Size_8x16);
	player_sprite.set_mode(SpriteMode::Regular);
	player_sprite.set_position(116, 65);
	sprite_manager.add_sprite(& player_sprite);
	
	bg_scene.set_enabled(true);
	
	pal_manager.stage_asset(test_bg_palette_asset, VramZone::Background);
	tile_manager.stage_asset(test_bg_tile_asset, VramZone::Background);
	tile_manager.stage_asset(test_bg_tilemap_asset, test_bg_tile_asset.tile_offset);
	
	GBA_BG0_CONTROL = 
		GBA_BG_4BPP |
		GBA_BG_SIZE_REG_64x64 |
		GBA_BG_PRIORITY_0 |
		GBA_BG_TILEBLOCK(test_bg_tile_asset.block_num) |
		GBA_BG_TILEMAP(test_bg_tilemap_asset.start_map_index);
	GBA_BG0_HOFF = 0;
	GBA_BG0_VOFF = 0;
	
	GBA_DISPLAY_CONTROL = GBA_DSPCNT_MODE_0 | GBA_DSPCNT_TILE_MAP_1D | GBA_DSPCNT_ENABLE_SPRITE | GBA_DSPCNT_ENABLE_BG0;
}

void TestScene::stop(scene_events_t & events) {
	events.update_event.remove_listener(update_listener_id);
	
	tile_manager.unstage_asset(test_bg_tile_asset);
	tile_manager.unstage_asset(test_bg_tilemap_asset);
	
	sprite_manager.remove_sprite(& player_sprite);
	tile_manager.unstage_asset(test_player_tile_asset);
	pal_manager.unstage_asset(test_player_palette_asset);
	
	bg_scene.set_enabled(false);
}

void TestScene::update() {
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
	
	player_walk.walk(walk_dir);
	Vec2 player_pos = player_walk.get_position();
	bg_scene.set_camera_position(Vec2(player_pos.x.int_part() - 120, player_pos.y.int_part() - 80));
	bg_scene.update();
}

void TestScene::update_listener(void * this_ptr) {
	reinterpret_cast<TestScene *>(this_ptr)->update();
}
