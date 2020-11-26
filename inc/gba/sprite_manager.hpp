#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP

#include "hal.hpp"

class SpriteManager;

enum class SpriteSize {
	Size_8x8 =   0b0000,
	Size_16x16 = 0b0001,
	Size_32x32 = 0b0010,
	Size_64x64 = 0b0011,
	Size_16x8 =  0b0100,
	Size_32x8 =  0b0101,
	Size_32x16 = 0b0110,
	Size_64x32 = 0b0111,
	Size_8x16 =  0b1000,
	Size_8x32 =  0b1001,
	Size_16x32 = 0b1010,
	Size_32x64 = 0b1011,
};

enum class SpriteMode {
	Regular,
	Affine,
	Disabled,
	Affine2x
};

class Sprite {
public:
	inline Sprite(spr_attr_t attrs = spr_attr_t()):
		attrs(attrs),
		next(nullptr),
		last(nullptr) {
	}
	
	inline void set_mode(SpriteMode mode) {
		attrs.attr_0 &= ~GBA_OAM_ATTR0_AFF_MODE_AFFINE2X;
		switch (mode) {
			case SpriteMode::Regular:
				attrs.attr_0 |= GBA_OAM_ATTR0_AFF_MODE_REGULAR;
				break;
			case SpriteMode::Affine:
				attrs.attr_0 |= GBA_OAM_ATTR0_AFF_MODE_AFFINE;
				break;
			case SpriteMode::Disabled:
				attrs.attr_0 |= GBA_OAM_ATTR0_AFF_MODE_DISABLE;
				break;
			case SpriteMode::Affine2x:
				attrs.attr_0 |= GBA_OAM_ATTR0_AFF_MODE_AFFINE2X;
				break;
		}
	}
	
	inline void set_color_mode(bool is_8bpp) {
		if (is_8bpp) {
			attrs.attr_0 |= GBA_OAM_ATTR0_COLOR_8BPP;
		} else {
			attrs.attr_0 &= ~GBA_OAM_ATTR0_COLOR_8BPP;
		}
	}
	
	inline void set_palette(int palette) {
		attrs.attr_2 &= ~ 0x0FFF;
		attrs.attr_2 |= palette << 12;
	}
	
	inline void set_position(int x, int y) {
		if (x < -100) {
			x = -100;
		}
		if (x > 240) {
			x = 240;
		}
		if (y < - 94) {
			y = - 94;
		}
		if (y > 160) {
			y = 160;
		}
		attrs.attr_0 &= ~GBA_OAM_ATTR0_Y_MASK;
		attrs.attr_0 |= (y & GBA_OAM_ATTR0_Y_MASK);
		attrs.attr_1 &= ~GBA_OAM_ATTR1_X_MASK;
		attrs.attr_1 |= (x & GBA_OAM_ATTR1_X_MASK);
	}
	
	inline void set_size(SpriteSize size) {
		attrs.attr_0 &= ~GBA_OAM_ATTR0_SHAPE_MASK;
		attrs.attr_1 &= ~GBA_OAM_ATTR1_SIZE_3;
		switch (size) {
			case SpriteSize::Size_8x8: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_SQUARE;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_0;
			} break;
			case SpriteSize::Size_16x16: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_SQUARE;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_1;
			} break;
			case SpriteSize::Size_32x32: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_SQUARE;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_2;
			} break;
			case SpriteSize::Size_64x64: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_SQUARE;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_3;
			} break;
			case SpriteSize::Size_16x8: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_WIDE;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_0;
			} break;
			case SpriteSize::Size_32x8: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_WIDE;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_1;
			} break;
			case SpriteSize::Size_32x16: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_WIDE;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_2;
			} break;
			case SpriteSize::Size_64x32: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_WIDE;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_3;
			} break;
			case SpriteSize::Size_8x16: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_TALL;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_0;
			} break;
			case SpriteSize::Size_8x32: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_TALL;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_1;
			} break;
			case SpriteSize::Size_16x32: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_TALL;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_2;
			} break;
			case SpriteSize::Size_32x64: {
				attrs.attr_0 |= GBA_OAM_ATTR0_SHAPE_TALL;
				attrs.attr_1 |= GBA_OAM_ATTR1_SIZE_3;
			} break;
		}
	}
	inline void set_start_tile(int tile) {
		attrs.attr_2 &= ~GBA_OAM_ATTR2_TILE_INDEX_MASK;
		attrs.attr_2 |= (tile & GBA_OAM_ATTR2_TILE_INDEX_MASK);
	}
	
	inline void set_flipping(bool vflip, bool hflip) {
		attrs.attr_1 &= ~(GBA_OAM_ATTR1_VFLIP | GBA_OAM_ATTR1_HFLIP);
		attrs.attr_1 |= (vflip ? GBA_OAM_ATTR1_VFLIP : 0) | (hflip ? GBA_OAM_ATTR1_HFLIP : 0);
	}
	
	inline void set_affine_transform(int index) {
		attrs.attr_1 &= ~GBA_OAM_ATTR1_AFFINE_INDEX_MASK;
		attrs.attr_1 |= (index << GBA_OAM_ATTR1_AFFINE_INDEX_SHIFT) & GBA_OAM_ATTR1_AFFINE_INDEX_MASK;
	}
	
private:
	friend class SpriteManager;
	
	spr_attr_t attrs;
	
	Sprite * next;
	Sprite * last;
};

class SpriteManager {
public:
	void init(int attr_min, int attr_count);
	void clear();
	
	void update();
	void add_sprite(Sprite * sprite);
	void remove_sprite(Sprite * sprite);
	
private:
	static void remove_from_list(Sprite * sprite, Sprite ** head_ptr);
	
	int attr_min;
	int attr_count;
	int last_sprite_count;
	
	Sprite * head;
};

#endif
