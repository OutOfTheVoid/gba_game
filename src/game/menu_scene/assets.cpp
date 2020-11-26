#include "game/menu_scene/assets.hpp"
#include "gba/color.hpp"

const palette_16_t menu_button_palette {
	RGB(0, 0, 0),
	RGB(31, 31, 31),
	RGB(0, 0, 0),
};

palette_16_asset_t menu_button_palette_asset(& menu_button_palette);
