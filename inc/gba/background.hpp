#ifndef GBA_BACKGROUND_HPP
#define GBA_BACKGROUND_HPP

#include <cstdint>
#include "hal.hpp"

enum class Background: uint32_t {
	Bg0 = 0,
	Bg1 = 1,
	Bg2 = 2,
	Bg3 = 3
};

#define VF(x) ((x | GBA_BGTILE_VFLIP))
#define HF(x) ((x | GBA_BGTILE_HFLIP))

#endif
