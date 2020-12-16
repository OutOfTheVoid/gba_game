#include "game/assets/cat1.hpp"
#include "gba/tile_manager.hpp"
#include "gba/pal_manager.hpp"
#include "gba/color.hpp"


static const palette_16_t cat1_palette_data {
	RGB(0, 0, 0),
	RGB(31, 17, 4),
	RGB(25, 13, 3),
	RGB(0, 0, 0),
	RGB(31, 31, 31),
};
palette_16_asset_t cat1_palette_asset(& cat1_palette_data);

const tile_4bpp_t cat1_tile_data[] {
	{
		0x0100, 0x0002,
		0x0120, 0x0112,
		0x0112, 0x2112,
		0x0132, 0x3110,
		0x4411, 0x1144,
		0x0113, 0x1122,
		0x0431, 0x3241,
		0x4002, 0x2124,
	}, {
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x4000, 0x2000,
		0x0000, 0x1000,
		0x0000, 0x1200,
		0x2000, 0x0100,
		0x2100, 0x0100,
	}, {
		0x0001, 0x1121,
		0x0002, 0x2211,
		0x0001, 0x1112,
		0x0001, 0x1121,
		0x0001, 0x2211,
		0x0001, 0x1112,
		0x0011, 0x2011,
		0x0012, 0x0112,
	}, {
		0x2220, 0x0100,
		0x1212, 0x0120,
		0x2212, 0x0011,
		0x1122, 0x0002,
		0x1212, 0x0011,
		0x2111, 0x2120,
		0x1111, 0x1000,
		0x2220, 0x0000,
	}, {
		0x0100, 0x0002,
		0x0120, 0x0112,
		0x0112, 0x2112,
		0x0132, 0x3110,
		0x4411, 0x1144,
		0x0113, 0x1122,
		0x0431, 0x3241,
		0x4002, 0x2124,
	}, {
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x4000, 0x0100,
		0x0000, 0x2100,
		0x0000, 0x1000,
		0x2000, 0x1000,
		0x2100, 0x1200,
	}, {
		0x0001, 0x1121,
		0x0002, 0x2211,
		0x0001, 0x1112,
		0x0001, 0x1121,
		0x0001, 0x2211,
		0x0001, 0x1112,
		0x0011, 0x2011,
		0x0012, 0x0112,
	}, {
		0x2220, 0x0100,
		0x1212, 0x0120,
		0x2212, 0x0010,
		0x1122, 0x0210,
		0x1212, 0x0100,
		0x2111, 0x2100,
		0x1111, 0x1000,
		0x2220, 0x0000,
	}, {
		0x0100, 0x0002,
		0x0120, 0x0112,
		0x0112, 0x2112,
		0x0132, 0x3110,
		0x4411, 0x1144,
		0x0113, 0x1122,
		0x0431, 0x3241,
		0x4002, 0x2124,
	}, {
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x4000, 0x1000,
		0x0001, 0x0000,
		0x0001, 0x2000,
		0x2000, 0x1000,
		0x2100, 0x1200,
	}, {
		0x0001, 0x1121,
		0x0002, 0x2211,
		0x0001, 0x1112,
		0x0001, 0x1121,
		0x0001, 0x2211,
		0x0001, 0x1112,
		0x0011, 0x2011,
		0x0012, 0x0112,
	}, {
		0x2220, 0x0120,
		0x1212, 0x0010,
		0x2212, 0x0012,
		0x1122, 0x0001,
		0x1212, 0x0001,
		0x2111, 0x2020,
		0x1111, 0x1110,
		0x2220, 0x0000,
	}, 
};

const tile_pack_4bpp_t cat1_tile_pack (cat1_tile_data, sizeof(cat1_tile_data) / sizeof(tile_4bpp_t), TileAssetLayout::Visual);

tile_asset_4bpp_t cat1_tile_asset(& cat1_tile_pack);