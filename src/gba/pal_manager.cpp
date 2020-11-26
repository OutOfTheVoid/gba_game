#include "gba/pal_manager.hpp"
#include "gba/mem.hpp"
#include "gba/hal.hpp"

PalManager::PalManager():
	bg_alloc_bits(0),
	spr_alloc_bits(0) {
}

bool PalManager::stage_asset(palette_16_asset_t & asset, VramZone zone) {
	if (asset.ref_count > 1) {
		if (zone != asset.vram_zone) {
			return false;
		}
		asset.ref_count ++;
		return true;
	} else {
		switch(zone) {
			case VramZone::Background: {
				if (bg_alloc_bits == 0xFFFF)
					return false;
				for (int i = 0; i < 16; i ++) {
					if ((bg_alloc_bits & (1 << i)) == 0) {
						bg_alloc_bits |= (1 << i);
						asset.pal_num = i;
						asset.ref_count = 1;
						asset.vram_zone = VramZone::Background;
						memcpy_16v(asset.palette, & GBA_BG_PALETTE[i * 16], 16);
						return true;
					}
				}
			} break;
			case VramZone::Sprite: {
				if (spr_alloc_bits == 0xFFFF)
					return false;
				for (int i = 0; i < 16; i ++) {
					if ((spr_alloc_bits & (1 << i)) == 0) {
						spr_alloc_bits |= (1 << i);
						asset.pal_num = i;
						asset.ref_count = 1;
						asset.vram_zone = VramZone::Sprite;
						memcpy_16v(asset.palette, & GBA_SPRITE_PALETTE[i * 16], 16);
						return true;
					}
				}
			} break;
		}
	}
	return false;
}

void PalManager::unstage_asset(palette_16_asset_t & asset) {
	if (asset.ref_count > 1) {
		asset.ref_count --;
	} else {
		asset.ref_count = 0;
		switch(asset.vram_zone) {
			case VramZone::Background:
				bg_alloc_bits &= ~(1 << asset.pal_num);
				break;
			case VramZone::Sprite:
				spr_alloc_bits &= ~(1 << asset.pal_num);
				break;
		}
	}
}

void PalManager::panic_clear() {
	bg_alloc_bits = 0;
	spr_alloc_bits = 0;
}

