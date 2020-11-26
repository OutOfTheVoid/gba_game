#include "gba/bg_dynamic_scene.hpp"
#include "main.hpp"

#define AREA_FLAG_VISIBLE 1
#define AREA_FLAG_STAGED 2
#define AREA_FLAG_IN_VIEW 4

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

#define REF_COUNT_FREE 0xFFFF

static const tile_4bpp_t default_tile[] {
	{
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
		0x0000, 0x0000,
	}
};
static const tile_pack_4bpp_t default_tile_pack(default_tile, 1);

BgDyanmicScene::BgDyanmicScene(Background bg, uint8_t tile_buffer_size):
	bg(bg),
	enabled(false),
	camera_x(0),
	camera_y(0),
	old_camera_tile_x(1000),
	old_camera_tile_y(1000),
	tilemap_asset(4),
	tile_asset(tile_buffer_size),
	id_counter(0),
	areas(),
	tile_ranges() {
	tile_ranges.push(tile_range_t {
		& default_tile_pack,
		1,
		0,
		0,
		true
	});
	tile_ranges.push(tile_range_t {
		nullptr,
		REF_COUNT_FREE,
		1,
		static_cast<uint8_t>(tile_buffer_size - 1),
		false
	});
}

void BgDyanmicScene::set_background(Background bg) {
	this -> bg = bg;
}

void BgDyanmicScene::set_enabled(bool enabled) {
	if (enabled && ! this -> enabled) {
		tile_manager.stage_asset(tile_asset, VramZone::Background);
		tile_manager.stage_asset(tilemap_asset);
		for (int i = 0; i < 4; i ++) {
			clear_tilemap(GBA_TILE_MAP(tilemap_asset.start_map_index), 0);
		}
	}
	if (! enabled && this -> enabled) {
		tile_manager.unstage_asset(tile_asset);
		tile_manager.unstage_asset(tilemap_asset);
	}
	this -> enabled = enabled;
}

int32_t BgDyanmicScene::add_area(const bg_area_def_t * area_def, const IVec2 & position, bool visible) {
	area_record_t new_area;
	new_area.id = id_counter;
	id_counter ++;
	new_area.tile_range = -1;
	new_area.position = position;
	new_area.mapped_area.x_low = INT32_MAX;
	new_area.mapped_area.y_low = INT32_MAX;
	new_area.mapped_area.x_high = INT32_MIN;
	new_area.mapped_area.y_high = INT32_MIN;
	new_area.flags = (visible ? AREA_FLAG_VISIBLE : 0);
	new_area.area_def = area_def;
	areas.push(new_area);
	return new_area.id;
}

void BgDyanmicScene::set_camera_position(const Vec2 & position) {
	camera_x = position.x.int_part();
	camera_y = position.y.int_part();
}

void BgDyanmicScene::stage_area_resources(area_record_t & area) {
	if (area.tile_range != -1) {
		return;
	}
	pal_manager.stage_asset(* area.area_def->palette, VramZone::Background);
	area.tile_range = ref_or_alloc_tiles(area.area_def->tile_pack);
}

void BgDyanmicScene::unstage_area_resources(area_record_t & area) {
	if (area.tile_range == -1) {
		return;
	}
	pal_manager.unstage_asset(* area.area_def->palette);
	if (area.tile_range != -1) {
		free_tiles(area.tile_range);
	}
}

int BgDyanmicScene::ref_or_alloc_tiles(const tile_pack_4bpp_t * tile_pack) {
	for (uint32_t r = 0; r < tile_ranges.get_size(); r ++) {
		if (tile_ranges[r].tile_pack == tile_pack && tile_ranges[r].ref_count != REF_COUNT_FREE) {
			tile_ranges[r].ref_count ++;
			return r;
		}
	}
	for (uint32_t r = 0; r < tile_ranges.get_size(); r ++) {
		uint32_t range_size = tile_ranges[r].high - tile_ranges[r].low + 1;
		if (tile_ranges[r].ref_count == REF_COUNT_FREE && range_size >= static_cast<uint32_t>(tile_pack->tile_count)) {
			if (range_size != static_cast<uint32_t>(tile_pack->tile_count)) {
				tile_range_t new_range;
				new_range.high = tile_ranges[r].high;
				new_range.low = tile_ranges[r].low + tile_pack->tile_count;
				new_range.ref_count = REF_COUNT_FREE;
				new_range.tile_pack = nullptr;
				new_range.dirty = false;
				tile_ranges[r].high = tile_ranges[r].low + tile_pack->tile_count - 1;
				tile_ranges.insert(new_range, r + 1);
			}
			tile_ranges[r].ref_count = 1;
			tile_ranges[r].tile_pack = tile_pack;
			tile_ranges[r].dirty = true;
			return r;
		}
	}
	for (uint32_t r = 0; r < tile_ranges.get_size(); r ++) {
		uint32_t range_size = tile_ranges[r].high - tile_ranges[r].low + 1;
		if (tile_ranges[r].ref_count == 0 && range_size >= static_cast<uint32_t>(tile_pack->tile_count)) {
			if (range_size != static_cast<uint32_t>(tile_pack->tile_count)) {
				tile_range_t new_range;
				new_range.high = tile_ranges[r].high;
				new_range.low = tile_ranges[r].low + tile_pack->tile_count;
				new_range.ref_count = REF_COUNT_FREE;
				new_range.tile_pack = nullptr;
				new_range.dirty = false;
				tile_ranges[r].high = tile_ranges[r].low + tile_pack->tile_count - 1;
				tile_ranges.insert(new_range, r + 1);
			}
			tile_ranges[r].ref_count = 1;
			tile_ranges[r].tile_pack = tile_pack;
			tile_ranges[r].dirty = true;
			return r;
		}
	}
	return -1;
}

void BgDyanmicScene::free_tiles(uint32_t r) {
	tile_ranges[r].ref_count --;
	if (tile_ranges[r].ref_count == 0) {
		bool left_free = 
			(r != 0) && 
				((tile_ranges[r - 1].ref_count == 0)
				|| (tile_ranges[r - 1].ref_count == REF_COUNT_FREE));
		bool right_free = 
			(r + 1 < tile_ranges.get_size()) &&
				((tile_ranges[r + 1].ref_count == 0)
				|| (tile_ranges[r + 1].ref_count == REF_COUNT_FREE));
		if (left_free && right_free) {
			// todo: colaescing
		} else if (left_free) {
			// todo: colaescing
		} else if (right_free) {
			// todo: colaescing
		}
	}
}

void BgDyanmicScene::update() {
	if (! enabled) {
		return;
	}
	
	int camera_tile_x = camera_x >> 3;
	int camera_tile_y = camera_y >> 3;
	IAABB viewport_rect(camera_tile_x - 1, camera_tile_x + 31, camera_tile_y - 1, camera_tile_y + 21);
	int camera_tile_travel_x = camera_tile_x - old_camera_tile_x;
	int camera_tile_travel_y = camera_tile_y - old_camera_tile_y;
	old_camera_tile_x = camera_tile_x;
	old_camera_tile_y = camera_tile_y;
	camera_tile_travel_x = IMAX(-31, camera_tile_travel_x);
	camera_tile_travel_x = IMIN(31, camera_tile_travel_x);
	camera_tile_travel_y = IMAX(-21, camera_tile_travel_y);
	camera_tile_travel_y = IMIN(21, camera_tile_travel_y);
	
	if (camera_tile_travel_x > 0) {
		for (int y = viewport_rect.y_low; y < viewport_rect.y_high; y ++) {
			for (int x = 0; x < camera_tile_travel_x; x ++) {
				write_tilemap(viewport_rect.x_high - x, y, 0);
			}
		}
	}
	if (camera_tile_travel_x < 0) {
		camera_tile_travel_x = - camera_tile_travel_x;
		for (int y = viewport_rect.y_low; y < viewport_rect.y_high; y ++) {
			for (int x = 0; x < camera_tile_travel_x; x ++) {
				write_tilemap(viewport_rect.x_low + x, y, 0);
			}
		}
	}
	if (camera_tile_travel_y > 0) {
		for (int x = viewport_rect.x_low; x < viewport_rect.x_high; x ++) {
			for (int y = 0; y < camera_tile_travel_y; y ++) {
				write_tilemap(x, viewport_rect.y_high - y, 0);
			}
		}
	}
	if (camera_tile_travel_y < 0) {
		camera_tile_travel_y = - camera_tile_travel_y;
		for (int x = viewport_rect.x_low; x < viewport_rect.x_high; x ++) {
			for (int y = 0; y < camera_tile_travel_y; y ++) {
				write_tilemap(x, viewport_rect.y_low + y, 0);
			}
		}
	}
	
	uint32_t area_count = areas.get_size();
	for (uint32_t i = 0; i < area_count; i ++) {
		area_record_t & area = areas[i];
		IAABB area_rect (area.position.x, area.position.x + area.area_def->tile_patch->width - 1, area.position.y, area.position.y + area.area_def->tile_patch->height - 1);
		IAABB area_visible_rect;
		bool is_visible = IAABB::intersection(area_rect, viewport_rect, area_visible_rect);
		if (is_visible) {
			stage_area_resources(area);
			if (!(area_visible_rect == area.mapped_area)) {
				if (area.mapped_area.valid()) {
					if (area_visible_rect.x_low < area.mapped_area.x_low) {
						IAABB update_rect (
							area_visible_rect.x_low, area.mapped_area.x_low,
							area_visible_rect.y_low, area_visible_rect.y_high
						);
						write_tilemap_aabb(update_rect, area.position, area.area_def->tile_patch, tile_ranges[area.tile_range].low, area.area_def->palette->pal_num);
					}
					if (area_visible_rect.x_high > area.mapped_area.x_high) {
						IAABB update_rect (
							area.mapped_area.x_high, area_visible_rect.x_high,
							area_visible_rect.y_low, area_visible_rect.y_high
						);
						write_tilemap_aabb(update_rect, area.position, area.area_def->tile_patch, tile_ranges[area.tile_range].low, area.area_def->palette->pal_num);
					}
					if (area_visible_rect.y_low < area.mapped_area.y_low) {
						IAABB update_rect (
							area_visible_rect.x_low, area_visible_rect.x_high,
							area_visible_rect.y_low, area.mapped_area.y_low
						);
						write_tilemap_aabb(update_rect, area.position, area.area_def->tile_patch, tile_ranges[area.tile_range].low, area.area_def->palette->pal_num);
					}
					if (area_visible_rect.y_high > area.mapped_area.y_high) {
						IAABB update_rect (
							area_visible_rect.x_low, area_visible_rect.x_high,
							area.mapped_area.y_high, area_visible_rect.y_high
						);
						write_tilemap_aabb(update_rect, area.position, area.area_def->tile_patch, tile_ranges[area.tile_range].low, area.area_def->palette->pal_num);
					}
				} else {
					write_tilemap_aabb(area_visible_rect, area.position, area.area_def->tile_patch, tile_ranges[area.tile_range].low, area.area_def->palette->pal_num);
				}
				area.mapped_area = area_visible_rect;
			}
		} else {
			unstage_area_resources(area);
			area.mapped_area = IAABB::make_invalid();
		}
	}
	
	for (uint32_t i = 0; i < tile_ranges.get_size(); i ++) {
		if (tile_ranges[i].dirty && tile_ranges[i].ref_count != 0 && tile_ranges[i].ref_count != REF_COUNT_FREE) {
			tile_asset.copy_tiles(tile_ranges[i].tile_pack->tile_list, tile_ranges[i].low, tile_ranges[i].tile_pack->tile_count);
			tile_ranges[i].dirty = false;
		}
	}
	
	uint32_t control_reg = 
		GBA_BG_4BPP |
		GBA_BG_SIZE_REG_64x64 |
		GBA_BG_PRIORITY_0 |
		GBA_BG_TILEBLOCK(tile_asset.block_num) |
		GBA_BG_TILEMAP(tilemap_asset.start_map_index);
	uint32_t hoff_reg = camera_x;
	uint32_t voff_reg = camera_y;
	
	switch(bg) {
		case Background::Bg0: {
			GBA_BG0_CONTROL = control_reg;
			GBA_BG0_HOFF = hoff_reg;
			GBA_BG0_VOFF = voff_reg;
		} break;
		case Background::Bg1: {
			GBA_BG1_CONTROL = control_reg;
			GBA_BG1_HOFF = hoff_reg;
			GBA_BG1_VOFF = voff_reg;
		} break;
		case Background::Bg2: {
			GBA_BG2_CONTROL = control_reg;
			GBA_BG2_HOFF = hoff_reg;
			GBA_BG2_VOFF = voff_reg;
		} break;
		case Background::Bg3: {
			GBA_BG3_CONTROL = control_reg;
			GBA_BG3_HOFF = hoff_reg;
			GBA_BG3_VOFF = voff_reg;
		} break;
	}
}

void BgDyanmicScene::write_tilemap_aabb(const IAABB & aabb, IVec2 item_pos, const bg_tile_patch_t * patch, int tile_offset, int palette_offset) {
	for (int x = aabb.x_low; x <= aabb.x_high; x ++) {
		for (int y = aabb.y_low; y <= aabb.y_high; y ++) {
			int patch_index = x - item_pos.x + (y - item_pos.y) * patch->width;
			write_tilemap(x, y, patch->elements[patch_index] + tile_offset + (palette_offset << 12));
		}
	}
}

void BgDyanmicScene::write_tilemap(int x, int y, uint16_t entry) {
	int local_x = (x + 0x40000000) & 0x3F;
	int local_y = (y + 0x40000000) & 0x3F;
	int map_x = local_x >> 5;
	int map_y = local_y >> 5;
	local_x &= 0x1F;
	local_y &= 0x1F;
	int tilemap = tilemap_asset.start_map_index + map_x + (map_y << 1);
	set_tilemap_entry(GBA_TILE_MAP(tilemap), local_x, local_y, entry);
}
