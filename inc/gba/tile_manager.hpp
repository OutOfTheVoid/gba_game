#ifndef GBA_TILE_MANAGER_HPP
#define GBA_TILE_MANAGER_HPP

#include "gba/hal.hpp"
#include "gba/tile.hpp"
#include "panic.hpp"

#include "stddef.h"

enum class TileAssetLayout {
	Native,
	Visual,
};

struct tile_pack_4bpp_t {
	inline tile_pack_4bpp_t(const tile_4bpp_t * tile_list, int tile_count, TileAssetLayout layout = TileAssetLayout::Native):
		tile_list(tile_list),
		tile_count(tile_count),
		layout(layout) {
	}
	
	const tile_4bpp_t * tile_list;
	int tile_count;
	TileAssetLayout layout;
	
};

struct tile_asset_4bpp_t {
	inline tile_asset_4bpp_t(const tile_pack_4bpp_t * tile_pack):
		tile_pack(tile_pack),
		ref_count(0),
		tile_offset(-1) {
	}
	
	const tile_pack_4bpp_t * tile_pack;
	int ref_count;
	int tile_offset;
	int block_num;
	VramZone vram_zone;
};

struct dynamic_tile_asset_4bpp_t {
	int ref_count;
	int tile_offset;
	int block_num;
	VramZone vram_zone;
	// do not change when staged!
	const int tile_count;
	
	inline dynamic_tile_asset_4bpp_t(int tile_count):
		ref_count(0),
		tile_offset(0),
		block_num(0),
		vram_zone(VramZone::Background),
		tile_count(tile_count) {
	};
	
	void * operator new(size_t size, void * addr) {
		(void) size;
		return addr;
	}
	
	inline dynamic_tile_asset_4bpp_t & operator=(const dynamic_tile_asset_4bpp_t & copy_from) {
		new (reinterpret_cast<void *>(this)) dynamic_tile_asset_4bpp_t(copy_from.tile_count);
		return * this;
	}
	
	inline void copy_tiles(const tile_4bpp_t * source_tiles, int start, int length = -1, TileAssetLayout layout = TileAssetLayout::Native) {
		if (layout == TileAssetLayout::Native) {
			switch (vram_zone)
			{
				case VramZone::Background: {
					for (int i = 0; i < length; i ++) {
						copy_tile_4bpp(GBA_TILE_BLOCK_4BPP(block_num), tile_offset + start + i, source_tiles[i]);
					}
				} break;
				case VramZone::Sprite: {
					for (int i = 0; i < length; i ++) {
						copy_tile_4bpp(GBA_TILE_BLOCK_4BPP(4 + block_num), tile_offset + start + i, source_tiles[i]);
					}
				} break;
			}
		} else {
			switch (vram_zone)
			{
				case VramZone::Background: {
					for (int i = 0; i < length; i ++) {
						copy_tile_4bpp_visual_layout(GBA_TILE_BLOCK_4BPP(block_num), tile_offset + start + i, source_tiles[i]);
					}
				} break;
				case VramZone::Sprite: {
					for (int i = 0; i < length; i ++) {
						copy_tile_4bpp_visual_layout(GBA_TILE_BLOCK_4BPP(4 + block_num), tile_offset + start + i, source_tiles[i]);
					}
				} break;
			}
		}
	}
	
	inline void copy_tiles_visual_layout(const tile_4bpp_t * source_tiles, int start, int length = -1) {
		switch (vram_zone)
		{
			case VramZone::Background: {
				for (int i = 0; i < length; i ++) {
					copy_tile_4bpp_visual_layout(GBA_TILE_BLOCK_4BPP(block_num), tile_offset + start + i, source_tiles[i]);
				}
			} break;
			case VramZone::Sprite: {
				for (int i = 0; i < length; i ++) {
					copy_tile_4bpp_visual_layout(GBA_TILE_BLOCK_4BPP(4 + block_num), tile_offset + start + i, source_tiles[i]);
				}
			} break;
		}
	}
};

struct tilemap_pack_t {
	inline tilemap_pack_t(const tilemap_t * tilemaps, int tilemap_count):
		tilemaps(tilemaps),
		tilemap_count(tilemap_count) {
	}
	
	const tilemap_t * tilemaps;
	int tilemap_count;
};

struct tilemap_asset_t {
	inline tilemap_asset_t(const tilemap_pack_t * tilemaps):
		tilemaps(tilemaps),
		ref_count(0),
		start_map_index(-1) {
	}
	
	const tilemap_pack_t * tilemaps;
	int ref_count;
	int start_map_index;
};

struct dynamic_tilemap_asset_t {
	inline dynamic_tilemap_asset_t(int tilemap_count):
		tilemap_count(tilemap_count),
		ref_count (0),
		start_map_index(-1) {
	}
	
	int tilemap_count;
	int ref_count;
	int start_map_index;
};

class TileManager {
public:
	TileManager();
	
	bool stage_asset(tile_asset_4bpp_t & asset, VramZone zone);
	bool stage_asset(dynamic_tile_asset_4bpp_t & asset, VramZone zone);
	bool stage_asset(tilemap_asset_t & asset, uint16_t tile_index_offset);
	bool stage_asset(dynamic_tilemap_asset_t & asset);
	
	void unstage_asset(tile_asset_4bpp_t & asset);
	void unstage_asset(dynamic_tile_asset_4bpp_t & asset);
	void unstage_asset(tilemap_asset_t & asset);
	void unstage_asset(dynamic_tilemap_asset_t & asset);
	
private:
	void panic_clear();
	friend void panic(const char * message);
	
	bool bg_read_alloc(int tile);
	void bg_write_alloc(int tile, bool alloc);
	int bg_find_free_region_from_start(int tile_count);
	
	bool spr_read_alloc(int tile);
	void spr_write_alloc(int tile, bool alloc);
	int spr_find_free_region_from_start(int tile_count);
	
	uint32_t bg_alloc_bits[64];
	uint32_t spr_alloc_bits[32];
};

#endif
