#ifndef GBA_PAL_MANAGER_HPP
#define GBA_PAL_MANAGER_HPP

#include <cstdint>
#include "hal.hpp"
#include "panic.hpp"

typedef uint16_t palette_16_t[16];

struct palette_16_asset_t {
	inline palette_16_asset_t(const palette_16_t * palette):
		palette(palette),
		ref_count(0),
		pal_num(-1) {
	}
	
	const palette_16_t * palette;
	int ref_count;
	int pal_num;
	VramZone vram_zone;
};

class PalManager {
public:
	enum class Zone {
		Background,
		Sprite
	};
	
	PalManager();
	
	bool stage_asset(palette_16_asset_t & asset, VramZone zone);
	void unstage_asset(palette_16_asset_t & asset);
	
private:
	friend void panic(const char * message);
	void panic_clear();
	
	uint16_t bg_alloc_bits;
	uint16_t spr_alloc_bits;
};

#endif
