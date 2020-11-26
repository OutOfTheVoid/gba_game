#ifndef GAME_ASSETS_HPP
#define GAME_ASSETS_HPP

#include "gba/tile_manager.hpp"
#include "gba/pal_manager.hpp"
#include "gba/sound_driver.hpp"

extern tile_asset_4bpp_t test_player_tile_asset;
extern palette_16_asset_t test_player_palette_asset;

extern const tile_4bpp_t test_bg_tiles[];
extern const size_t test_bg_tile_count;
extern const tile_pack_4bpp_t test_bg_tile_pack;
extern tile_asset_4bpp_t test_bg_tile_asset;
extern palette_16_asset_t test_bg_palette_asset;
extern tilemap_asset_t test_bg_tilemap_asset;

#endif
