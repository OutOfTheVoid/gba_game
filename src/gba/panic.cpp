#include "gba/panic.hpp"
#include "gba/hal.hpp"
#include "gba/tile.hpp"
#include "gba/tile_manager.hpp"
#include "gba/pal_manager.hpp"
#include "gba/sprite_manager.hpp"
#include "gba/sprite.hpp"
#include "gba/color.hpp"
#include "gba/interrupts.hpp"
#include "gba/sound_driver.hpp"
#include "drawing/sprite_bitmap.hpp"
#include "drawing/bitmap_font.hpp"
#include "drawing/fonts.hpp"
#include "main.hpp"

static const palette_16_t panic_palette {
	RGB(0, 0, 0),
	RGB(31, 0, 0),
	RGB(31, 31, 31)
};
static palette_16_asset_t panic_palette_asset (& panic_palette);
static palette_16_asset_t panic_text_palette_asset (& panic_palette);

static const tile_4bpp_t panic_tiles[] { {
		0x1111, 0x1111,
		0x1111, 0x1111,
		0x1111, 0x1111,
		0x1111, 0x1111,
		0x1111, 0x1111,
		0x1111, 0x1111,
		0x1111, 0x1111,
		0x1111, 0x1111,
	}, {
		0x2221, 0x1122,
		0x1121, 0x1211,
		0x1121, 0x1211,
		0x2221, 0x1122,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1121, 0x1111,
	}, {
		0x2211, 0x1122,
		0x1121, 0x1211,
		0x1121, 0x1211,
		0x2221, 0x1222,
		0x1121, 0x1211,
		0x1121, 0x1211,
		0x1121, 0x1211,
		0x1121, 0x1211,
	}, {
		0x1121, 0x1211,
		0x1221, 0x1211,
		0x2121, 0x1211,
		0x2121, 0x1211,
		0x1121, 0x1212,
		0x1121, 0x1212,
		0x1121, 0x1221,
		0x1121, 0x1211,
	}, {
		0x2221, 0x1222,
		0x2111, 0x1111,
		0x2111, 0x1111,
		0x2111, 0x1111,
		0x2111, 0x1111,
		0x2111, 0x1111,
		0x2111, 0x1111,
		0x2221, 0x1222,
	}, {
		0x2111, 0x1122,
		0x1211, 0x1211,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1211, 0x1211,
		0x2111, 0x1122,
	}, {
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1121, 0x1111,
		0x1111, 0x1111,
		0x1121, 0x1111,
	}, 
};

static const tile_pack_4bpp_t panic_tile_pack(panic_tiles, sizeof(panic_tiles) / sizeof(tile_4bpp_t));
static tile_asset_4bpp_t panic_tile_asset(& panic_tile_pack);

static dynamic_tilemap_asset_t panic_tilemap_asset(1);

void panic(const char * message) {
	sound_driver_stop();
	block_interrups();
	
	pal_manager.panic_clear();
	pal_manager.stage_asset(panic_palette_asset, VramZone::Background);
	pal_manager.stage_asset(panic_text_palette_asset, VramZone::Sprite);
	
	tile_manager.panic_clear();
	tile_manager.stage_asset(panic_tile_asset, VramZone::Background);
	tile_manager.stage_asset(panic_tilemap_asset);
	volatile tilemap_t * tilemap = GBA_TILE_MAP(panic_tilemap_asset.start_map_index);
	for (int y = 0; y < 32; y ++) {
		for (int x = 0; x < 32; x ++) {
			set_tilemap_entry(tilemap, x, y, 0 | (panic_palette_asset.pal_num << 12));
		}
	}
	set_tilemap_entry(tilemap, 0, 0, 1 | (panic_palette_asset.pal_num << 12));
	set_tilemap_entry(tilemap, 1, 0, 2 | (panic_palette_asset.pal_num << 12));
	set_tilemap_entry(tilemap, 2, 0, 3 | (panic_palette_asset.pal_num << 12));
	set_tilemap_entry(tilemap, 3, 0, 4 | (panic_palette_asset.pal_num << 12));
	set_tilemap_entry(tilemap, 4, 0, 5 | (panic_palette_asset.pal_num << 12));
	set_tilemap_entry(tilemap, 5, 0, 6 | (panic_palette_asset.pal_num << 12));
	
	SpriteBitmap panic_message_bitmap(SpriteSize::Size_64x64, true);
	panic_message_bitmap.clear(0);
	panic_message_bitmap.draw_text(message, font_basic, 2, 0, 0, 64, 8);
	panic_message_bitmap.stage(tile_manager);
	panic_message_bitmap.copy_to_vram();
	
	Sprite panic_message_sprite;
	panic_message_sprite.set_mode(SpriteMode::Regular);
	panic_message_sprite.set_color_mode(false);
	panic_message_sprite.set_size(SpriteSize::Size_64x64);
	panic_message_sprite.set_palette(panic_text_palette_asset.pal_num);
	panic_message_sprite.set_start_tile(panic_message_bitmap.get_start_tile());
	panic_message_sprite.set_position(0, 10);
	init_oam();
	sprite_manager.clear();
	sprite_manager.init(0, 128);
	sprite_manager.add_sprite(& panic_message_sprite);
	sprite_manager.update();
	
	GBA_DISPLAY_CONTROL = GBA_DSPCNT_ENABLE_BG0 | GBA_DSPCNT_MODE_0 | GBA_DSPCNT_ENABLE_SPRITE | GBA_DSPCNT_TILE_MAP_1D;
	GBA_BG0_CONTROL = GBA_BG_4BPP | GBA_BG_SIZE_REG_32x32 | GBA_BG_TILEMAP(panic_tilemap_asset.start_map_index) | GBA_BG_TILEBLOCK(panic_tile_asset.block_num);
	
	while(true) {
	};
	
}
