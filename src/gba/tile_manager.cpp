#include "gba/tile_manager.hpp"
#include "gba/tile.hpp"

const tile_4bpp_t clear_tile {
	0x0000, 0x0000,
	0x0000, 0x0000,
	0x0000, 0x0000,
	0x0000, 0x0000,
	0x0000, 0x0000,
	0x0000, 0x0000,
	0x0000, 0x0000,
	0x0000, 0x0000,
};

TileManager::TileManager() {
	for (int i = 0; i < 64; i ++) {
		bg_alloc_bits[i] = 0;
	}
	for (int i = 0; i < 32; i ++) {
		spr_alloc_bits[i] = 0;
	}
}

bool TileManager::stage_asset(tile_asset_4bpp_t & asset, VramZone zone) {
	if (asset.ref_count > 0) {
		if (zone != asset.vram_zone) {
			return false;
		}
		asset.ref_count ++;
	} else {
		// allocate the asset
		int tile_count = asset.tile_pack->tile_count;
		int tile_start;
		switch (zone) {
			case VramZone::Background:
				tile_start = bg_find_free_region_from_start(tile_count);
				break;
			
			case VramZone::Sprite:
				tile_start = spr_find_free_region_from_start(tile_count);
				break;
		}
		if (tile_start == -1) {
			return false;
		}
		if (asset.tile_pack->layout == TileAssetLayout::Native) {
			switch (zone) {
				case VramZone::Background:
					for (int i = 0; i < tile_count; i ++) {
						copy_tile_4bpp(GBA_TILE_BLOCK_4BPP_0, tile_start + i, asset.tile_pack->tile_list[i]);
					}
					break;
				
				case VramZone::Sprite:
					for (int i = 0; i < tile_count; i ++) {
						copy_tile_4bpp(GBA_TILE_BLOCK_4BPP_4, tile_start + i, asset.tile_pack->tile_list[i]);
					}
					break;
			}
		} else {
			switch (zone) {
				case VramZone::Background:
					for (int i = 0; i < tile_count; i ++) {
						copy_tile_4bpp_visual_layout(GBA_TILE_BLOCK_4BPP_0, tile_start + i, asset.tile_pack->tile_list[i]);
					}
					break;
				
				case VramZone::Sprite:
					for (int i = 0; i < tile_count; i ++) {
						copy_tile_4bpp_visual_layout(GBA_TILE_BLOCK_4BPP_4, tile_start + i, asset.tile_pack->tile_list[i]);
					}
					break;
			}
		}
		
		asset.block_num = tile_start / 512;
		asset.tile_offset = tile_start - asset.block_num * 512;
		asset.ref_count = 1;
		asset.vram_zone = zone;
	}
	return true;
}

bool TileManager::stage_asset(dynamic_tile_asset_4bpp_t & asset, VramZone zone) {
	if (asset.ref_count > 0) {
		if (zone != asset.vram_zone) {
			return false;
		}
		asset.ref_count ++;
	} else {
		// allocate the asset
		int tile_count = asset.tile_count;
		int tile_start;
		switch (zone) {
			case VramZone::Background:
				tile_start = bg_find_free_region_from_start(tile_count);
				break;
			
			case VramZone::Sprite:
				tile_start = spr_find_free_region_from_start(tile_count);
				break;
		}
		if (tile_start == -1) {
			return false;
		}
		switch (zone) {
			case VramZone::Background:
				for (int i = 0; i < tile_count; i ++) {
					copy_tile_4bpp(GBA_TILE_BLOCK_4BPP_0, tile_start + i, clear_tile);
				}
				break;
			
			case VramZone::Sprite:
				for (int i = 0; i < tile_count; i ++) {
					copy_tile_4bpp(GBA_TILE_BLOCK_4BPP_4, tile_start + i, clear_tile);
				}
				break;
		}
		
		asset.block_num = tile_start / 512;
		asset.tile_offset = tile_start - asset.block_num * 512;
		asset.ref_count = 1;
		asset.vram_zone = zone;
	}
	return true;
}


bool TileManager::stage_asset(tilemap_asset_t & asset, uint16_t tile_index_offset) {
	if (asset.ref_count > 0) {
		asset.ref_count ++;
	} else {
		
		int tilemap_count = asset.tilemaps->tilemap_count;
		
		for (int i = 62 - (tilemap_count - 1) * 2; i >= 0; i --) {
			bool good = true;
			for (int j = 0; j < tilemap_count * 2; j ++) {
				if (bg_alloc_bits[i + j] != 0) {
					good = false;
					break;
				}
			}
			if (good) {
				for (int j = 0; j < tilemap_count * 2; j ++) {
					bg_alloc_bits[i + j] = 0xFFFFFFFF;
				}
				asset.start_map_index = i / 2;
				for (int j = 0; j < tilemap_count; j ++) {
					copy_tilemap_with_offset(GBA_TILE_MAP(asset.start_map_index + j), asset.tilemaps->tilemaps[j], tile_index_offset);
				}
				asset.ref_count = 1;
				return true;
			}
		}
		return false;
	}
	return true;
}

bool TileManager::stage_asset(dynamic_tilemap_asset_t & asset) {
	if (asset.ref_count > 0) {
		asset.ref_count ++;
	} else {
		
		int tilemap_count = asset.tilemap_count;
		
		for (int i = 62 - (tilemap_count - 1) * 2; i >= 0; i --) {
			bool good = true;
			for (int j = 0; j < tilemap_count * 2; j ++) {
				if (bg_alloc_bits[i + j] != 0) {
					good = false;
					break;
				}
			}
			if (good) {
				for (int j = 0; j < tilemap_count * 2; j ++) {
					bg_alloc_bits[i + j] = 0xFFFFFFFF;
				}
				asset.start_map_index = i / 2;
				asset.ref_count = 1;
				return true;
			}
		}
		return false;
	}
	return true;
}

void TileManager::unstage_asset(tile_asset_4bpp_t & asset) {
	if (asset.ref_count > 1) {
		asset.ref_count --;
	} else {
		asset.ref_count = 0;
		switch (asset.vram_zone) {
			case VramZone::Background:
				for (int c = 0; c < asset.tile_pack->tile_count; c ++) {
					bg_write_alloc(asset.tile_offset + c, false);
				}
				break;
			case VramZone::Sprite:
				for (int c = 0; c < asset.tile_pack->tile_count; c ++) {
					spr_write_alloc(asset.tile_offset + c, false);
				}
				break;
		}
	}
}

void TileManager::unstage_asset(dynamic_tile_asset_4bpp_t & asset) {
	if (asset.ref_count > 1) {
		asset.ref_count --;
	} else {
		asset.ref_count = 0;
		switch (asset.vram_zone) {
			case VramZone::Background:
				for (int c = 0; c < asset.tile_count; c ++) {
					bg_write_alloc(asset.tile_offset + c, false);
				}
				break;
			case VramZone::Sprite:
				for (int c = 0; c < asset.tile_count; c ++) {
					spr_write_alloc(asset.tile_offset + c, false);
				}
				break;
		}
	}
}

void TileManager::unstage_asset(tilemap_asset_t & asset) {
	if (asset.ref_count > 1) {
		asset.ref_count --;
	} else {
		asset.ref_count = 0;
		int tilemap_count = asset.tilemaps->tilemap_count;
		for (int i = 0; i < tilemap_count; i ++) {
			bg_alloc_bits[(i + asset.start_map_index) * 2 + 0] = 0;
			bg_alloc_bits[(i + asset.start_map_index) * 2 + 1] = 0;
		}
	}
}

void TileManager::unstage_asset(dynamic_tilemap_asset_t & asset) {
	if (asset.ref_count > 1) {
		asset.ref_count --;
	} else {
		asset.ref_count = 0;
		int tilemap_count = asset.tilemap_count;
		for (int i = 0; i < tilemap_count; i ++) {
			bg_alloc_bits[(i + asset.start_map_index) * 2 + 0] = 0;
			bg_alloc_bits[(i + asset.start_map_index) * 2 + 1] = 0;
		}
	}
}

void TileManager::panic_clear() {
	for (int i = 0; i < 32; i ++) {
		bg_alloc_bits[i * 2 + 0] = 0;
		bg_alloc_bits[i * 2 + 1] = 0;
		spr_alloc_bits[i] = 0;
	}
}

int TileManager::bg_find_free_region_from_start(int tile_count) {
	int b = 0;
	while((b < 64) && (bg_alloc_bits[b] == 0xFFFFFFFF)) {
		b ++;
	}
	b *= 32;
	for (; b < 2048 - (tile_count - 1); b ++) {
		bool region_good = true;
		for (int c = 0; c < tile_count; c ++) {
			if (bg_read_alloc(b + c)) {
				region_good = false;
				break;
			}
		}
		if (region_good) {
			for (int c = 0; c < tile_count; c ++) {
				bg_write_alloc(b + c, true);
			}
			return b;
		}
	}
	return -1;
}

int TileManager::spr_find_free_region_from_start(int tile_count) {
	int b = 0;
	while((b < 32) && (spr_alloc_bits[b] == 0xFFFFFFFF)) {
		b ++;
	}
	b *= 32;
	for (; b < 1024 - (tile_count - 1); b ++) {
		bool region_good = true;
		for (int c = 0; c < tile_count; c ++) {
			if (spr_read_alloc(b + c)) {
				region_good = false;
				break;
			}
		}
		if (region_good) {
			for (int c = 0; c < tile_count; c ++) {
				spr_write_alloc(b + c, true);
			}
			return b;
		}
	}
	return -1;
}

bool TileManager::bg_read_alloc(int tile) {
	int b = tile >> 5;
	int i = tile & 31;
	return (bool) (bg_alloc_bits[b] & (1 << i));
}

void TileManager::bg_write_alloc(int tile, bool alloc) {
	int b = tile >> 5;
	int i = tile & 31;
	if (alloc) {
		bg_alloc_bits[b] |= (1 << i);
	} else {
		bg_alloc_bits[b] &= ~(1 << i);
	}
}

bool TileManager::spr_read_alloc(int tile) {
	int b = tile >> 5;
	int i = tile & 31;
	return (bool) (spr_alloc_bits[b] & (1 << i));
}

void TileManager::spr_write_alloc(int tile, bool alloc) {
	int b = tile >> 5;
	int i = tile & 31;
	if (alloc) {
		spr_alloc_bits[b] |= (1 << i);
	} else {
		spr_alloc_bits[b] &= ~(1 << i);
	}
}


