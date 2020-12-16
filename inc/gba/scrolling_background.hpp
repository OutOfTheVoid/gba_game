#ifndef GBA_MANAGER_HPP
#define GBA_MANAGER_HPP

#include <cstdint>

#include "tile_manager.hpp"
#include "main.hpp"
#include "background.hpp"
#include "math/Vec2.hpp"
#include "math/aabb.hpp"
#include "util/vector.hpp"

struct bg_tile_patch_t {
	const uint16_t * elements;
	uint16_t width;
	uint16_t height;
};

struct bg_area_def_t {
	palette_16_asset_t * palette;
	const bg_tile_patch_t * tile_patch;
	const tile_pack_4bpp_t * tile_pack;
};

// struct bg_dynamic_tile_pack_4bpp_t {
// 	tile_4bpp_t * tiles;
// 	uint8_t tile_count;
// 	uint32_t dirty_bitfield;
// };

class ScrollingBackground {
public:
	ScrollingBackground(Background bg = Background::Bg0, uint8_t tile_buffer_size = 128);
	
	void set_background(Background bg);
	void set_enabled(bool enabled);
	
	int32_t add_area(const bg_area_def_t * area, const IVec2 & position, bool visible = true);
	void remove_area(int32_t area_id);
	
	void set_camera_position(const Vec2 & position);
	
	void update();
	
private:
	struct area_record_t {
		inline area_record_t(){};
		inline area_record_t(const area_record_t &) = default;
		
		const bg_area_def_t * area_def;
		IAABB mapped_area;
		
		uint32_t flags;
		int id;
		int tile_range;
		IVec2 position;
	};
	
	struct tile_range_t {
		const tile_pack_4bpp_t * tile_pack;
		uint16_t ref_count;
		uint8_t low;
		uint8_t high;
		bool dirty;
	};
	
	void stage_area_resources(area_record_t & area);
	void unstage_area_resources(area_record_t & area);
	
	void write_tilemap_aabb(const IAABB & aabb, IVec2 item_pos, const bg_tile_patch_t * patch, int tile_offset, int palette_offset);
	void write_tilemap(int x, int y, uint16_t entry);
	
	int ref_or_alloc_tiles(const tile_pack_4bpp_t * tile_pack);
	void free_tiles(uint32_t r);
	
	Background bg;
	bool enabled;
	
	int32_t camera_x;
	int32_t camera_y;
	int32_t old_camera_tile_x;
	int32_t old_camera_tile_y;
	
	dynamic_tilemap_asset_t tilemap_asset;
	dynamic_tile_asset_4bpp_t tile_asset;
	
	int32_t id_counter;
	Vector<area_record_t> areas;
	Vector<tile_range_t> tile_ranges;
};

#endif
