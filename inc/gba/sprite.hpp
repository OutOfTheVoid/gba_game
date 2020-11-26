#ifndef GBA_SPRITE_HPP
#define GBA_SPRITE_HPP

#include "hal.hpp"
#include "mem.hpp"

inline static void init_oam() {
	for (int i = 0; i < SPRITE_COUNT; i ++) {
		GBA_OAM[i].attr_0 = GBA_OAM_ATTR0_AFF_MODE_DISABLE;
	}
}

inline static void copy_spr_attr(uint32_t sprite, const spr_attr_t & source) {
	memcpy_16v(reinterpret_cast<const void *>(& source), reinterpret_cast<volatile void *>(& GBA_OAM[sprite]), 3);
}

inline static void copy_sprite_attr_list(uint32_t start_sprite, spr_attr_t * attr_list, uint32_t count) {
	for (uint32_t i = 0; i < count; i ++) {
		memcpy_16v(reinterpret_cast<const void *>(& attr_list[i]), reinterpret_cast<volatile void *>(& GBA_OAM[start_sprite + i]), 3);
	}
}

#endif
