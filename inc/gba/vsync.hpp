#ifndef GBA_VSYNC_HPP
#define GBA_VSYNC_HPP

#include "hal.hpp"

#define VCOUNT_VBLANK_START 160

inline static void vcount_wait(uint16_t count) {
	while(GBA_VCOUNT > count);
	while(GBA_VCOUNT < count);
}

#endif
