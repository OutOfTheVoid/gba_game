#ifndef GBA_HAL_HPP
#define GBA_HAL_HPP

#include <cstdint>

/*
LCD Vertical Count
==================
This register says which scanline the gba is currently on over the display period.
It counts up from 0 -> 160 over the display interval, and then for 68 more
lines in the vertical blank period. (0 -> 227 total)
*/

#define GBA_VCOUNT (* reinterpret_cast<volatile uint16_t *>(0x04000006))

/*
Display Control
===============
The display control controls how the GBA display controllerrenders to the screen - it has three
bitmap modes and three tile modes.

This is set by assigning the union of several mode flags to the display control register. For
example, to set the gba into mode 2, with sprites enabled, you would write:

GBA_DISPLAY_CONTROL = GBA_DSPCNT_MODE_0 | GBA_DSPCNT_SPRITE_EN;
*/
#define GBA_DISPLAY_CONTROL (* reinterpret_cast<volatile uint16_t *>(0x04000000))

/*
Display modes
=============

Mode | Rot/Scale | Layers | BG Sizes             | Tiles | Colors       | Features
----------------------------------------------------------------------------------
0    | No        | 0-3    | 256x256 to 512x512   | 1024  | 16/16, 256/1 | SFMABP
1    | No        | 0, 1   | 256x256 to 512x512   | 1024  | 16/16, 256/1 | SFMABP
1    | Yes       | 2      | 128x128 to 1024x1024 | 256   | 256/1        | S.MABP
2    | Yes       | 2, 3   | 128x128 to 1024x1024 | 256   | 256/1        | S.MABP

Mode | Yes       | Layers | BG Size              | FBs   | Colors       | Features
----------------------------------------------------------------------------------
3    | Yes       | 2      | 240x160              | 1     | 32768        | ..MABP
4    | Yes       | 2      | 240x160              | 2     | 256/1        | ..MABP
5    | Yes       | 2      | 160x128              | 2     | 32768        | ..MABP

Feature | Description
-------------------------------
S       | scrolling
F       | flip
M       | mosaic
A       | alpha blending
B       | brightness
P       | priority.
*/
#define GBA_DSPCNT_MODE_0 0x0000
#define GBA_DSPCNT_MODE_1 0x0001
#define GBA_DSPCNT_MODE_2 0x0002
#define GBA_DSPCNT_MODE_3 0x0003
#define GBA_DSPCNT_MODE_4 0x0004
#define GBA_DSPCNT_MODE_5 0x0005

// For bitmapped modes with 2 FBs, selects which one is displayed
#define GBA_DSPCNT_FRAMEBUFFER_SELECT 0x0010
// Allows access to OAM during HBLANK
#define GBA_DSPCNT_ALLOW_OAM_HBLANK 0x0020
// If set, sprite tiles are indexed in 1d, instead of 2d in a 32x32 tile map
#define GBA_DSPCNT_TILE_MAP_1D 0x0040
// Forces the display blank, allowing fast access to VRAM/OAM/Pallete
#define GBA_DSPCNT_FORCE_BLANK 0x0080
// enables each given layer - backgrounds 0-3 and sprites
#define GBA_DSPCNT_ENABLE_BG0 0x0100
#define GBA_DSPCNT_ENABLE_BG1 0x0200
#define GBA_DSPCNT_ENABLE_BG2 0x0400
#define GBA_DSPCNT_ENABLE_BG3 0x0800
#define GBA_DSPCNT_ENABLE_SPRITE 0x1000
// enables each of the given windows - bg window 1, 2 and the sprite window
#define GBA_DSPCNT_ENABLE_BG_WINDOW_0 0x2000
#define GBA_DSPCNT_ENABLE_BG_WINDOW_1 0x4000
#define GBA_DSPCNT_ENABLE_SPRITE_WINDOW 0x8000

#define GBA_DISPLAY_STATUS (* reinterpret_cast<volatile uint16_t *>(0x04000004))

#define GBA_DISPLAY_STATUS_VBLANK 0x0001
#define GBA_DISPLAY_STATUS_HBLANK 0x0002
#define GBA_DISPLAY_STATUS_VCOUNT 0x0004
#define GBA_DISPLAY_STATUS_VBLANK_INTR_EN 0x0008
#define GBA_DISPLAY_STATUS_HBLANK_INTR_EN 0x0010
#define GBA_DISPLAY_STATUS_VCOUNT_INTR_EN 0x0020

#define GBA_DISPLAY_STATUS_VCOUNT_MATCH_SHIFT 8
#define GBA_DISPLAY_STATUS_VCOUNT_MATCH_MASK 0xFF00

/*
Framebuffers
============
Each framebuffer macro expands to a pointer to the framebuffer in it's native pixel size
(8 or 16 bits), indexable as a standard 2D arrays. (index = x + y * width)

Mode 3
------
GBA_MODE3_FRAMEBUFFER: 240x160x16
pixels are 16-bit (-rrrrrgggggbbbbb) colors.

Mode 4
------
GBA_MODE4_FRAMEBUFFER_0,
GBA_MODE4_FRAMEBUFFER_1: (120x2)x160x16
pixels are pairs (left, right) of 8-bit indexes into the background palette

Mode 5
------
GBA_MODE5_FRAMEBUFFER_0,
GBA_MODE5_FRAMEBUFFER_1: 160x128x16
pixels are 16-bit (-rrrrrgggggbbbbb) colors.
*/
#define GBA_MODE3_FRAMEBUFFER (reinterpret_cast<volatile uint16_t *>(0x06000000))
#define GBA_MODE3_FRAMEBUFFER_W 240
#define GBA_MODE3_FRAMEBUFFER_H 160

#define GBA_MODE4_FRAMEBUFFER_0 (reinterpret_cast<volatile uint16_t *>(0x06000000))
#define GBA_MODE4_FRAMEBUFFER_1 (reinterpret_cast<volatile uint16_t *>(0x0600A000))
#define GBA_MODE4_FRAMEBUFFER_W 120
#define GBA_MODE4_FRAMEBUFFER_H 160

#define GBA_MODE5_FRAMEBUFFER_0 (reinterpret_cast<volatile uint16_t *>(0x06000000))
#define GBA_MODE5_FRAMEBUFFER_1 (reinterpret_cast<volatile uint16_t *>(0x0600A000))
#define GBA_MODE5_FRAMEBUFFER_W 160
#define GBA_MODE5_FRAMEBUFFER_H 128

/*
Tiles
=====
Tile data is a collection of 8x8 pixel images. Each collection (usually referred to as
either a tile block or character block) is 16KB large, containing 256 8-bit pixel tiles,
or 512 4-bit pixel tiles.
*/

#define TILE_4BPP_PER_BLOCK 512
#define TILE_8BPP_PER_BLOCK 256

typedef uint16_t tile_4bpp_t[16];
typedef uint16_t tile_8bpp_t[32];

#define GBA_TILE_BLOCK_4BPP(block) (reinterpret_cast<volatile tile_4bpp_t *>(0x06000000 + block * 0x4000))
#define GBA_TILE_BLOCK_8BPP(block) (reinterpret_cast<volatile tile_8bpp_t *>(0x06000000 + block * 0x4000))

#define GBA_TILE_BLOCK_4BPP_0 (reinterpret_cast<volatile tile_4bpp_t *>(0x06000000))
#define GBA_TILE_BLOCK_4BPP_1 (reinterpret_cast<volatile tile_4bpp_t *>(0x06004000))
#define GBA_TILE_BLOCK_4BPP_2 (reinterpret_cast<volatile tile_4bpp_t *>(0x06008000))
#define GBA_TILE_BLOCK_4BPP_3 (reinterpret_cast<volatile tile_4bpp_t *>(0x0600C000))
#define GBA_TILE_BLOCK_4BPP_4 (reinterpret_cast<volatile tile_4bpp_t *>(0x06010000))
#define GBA_TILE_BLOCK_4BPP_5 (reinterpret_cast<volatile tile_4bpp_t *>(0x06014000))

#define GBA_TILE_BLOCK_8BPP_0 (reinterpret_cast<volatile tile_8bpp_t *>(0x06000000))
#define GBA_TILE_BLOCK_8BPP_1 (reinterpret_cast<volatile tile_8bpp_t *>(0x06004000))
#define GBA_TILE_BLOCK_8BPP_2 (reinterpret_cast<volatile tile_8bpp_t *>(0x06008000))
#define GBA_TILE_BLOCK_8BPP_3 (reinterpret_cast<volatile tile_8bpp_t *>(0x0600C000))
#define GBA_TILE_BLOCK_8BPP_4 (reinterpret_cast<volatile tile_8bpp_t *>(0x06010000))
#define GBA_TILE_BLOCK_8BPP_5 (reinterpret_cast<volatile tile_8bpp_t *>(0x06014000))

/*
Tile Maps
=========
Tile Maps are the maps that define tiled backgrounds. They exist in the same region
of memory as tile blocks, so they cannot overlap.

Each tile map is a 32x32 2d array of u16s, each of which is an index into the tile block
for the given background
*/
typedef uint16_t tilemap_t[32][32];

#define GBA_TILE_MAP(n) (reinterpret_cast<volatile tilemap_t *> (0x06000000 + 0x800 * n))

/*
Palettes
========
The palettes are linear arrays of 16-bit colors (-rrrrrgggggbbbbb). When operating in
16-palette mode, these are indexed like: index = palette * 16 + color
*/
#define GBA_BG_PALETTE (reinterpret_cast<volatile uint16_t *>(0x05000000))
#define GBA_SPRITE_PALETTE (reinterpret_cast<volatile uint16_t *>(0x05000200))

/*
Backgrounds
===========
Backgrounds on the GBA are composed of some number of sequential Tile Maps, which index
into tile blocks, which contain tiles. See video modes for a discussion about background
capabilities.
*/

#define GBA_BG0_CONTROL (* reinterpret_cast<volatile uint16_t *>(0x04000008))
#define GBA_BG1_CONTROL (* reinterpret_cast<volatile uint16_t *>(0x0400000A))
#define GBA_BG2_CONTROL (* reinterpret_cast<volatile uint16_t *>(0x0400000C))
#define GBA_BG3_CONTROL (* reinterpret_cast<volatile uint16_t *>(0x0400000E))

#define GBA_BG_PRIORITY_0 0b00
#define GBA_BG_PRIORITY_1 0b01
#define GBA_BG_PRIORITY_2 0b10
#define GBA_BG_PRIORITY_3 0b11

#define GBA_BG_TILEBLOCK(n) ((n & 3) << 2)

#define GBA_BG_MOSAIC 0x40
#define GBA_BG_4BPP 0x00
#define GBA_BG_8BPP 0x80

#define GBA_BG_TILEMAP(n) ((n & 0x1F) << 8)

#define GBA_BG_WRAP 0x2000

#define GBA_BG_SIZE_REG_32x32 0x0000
#define GBA_BG_SIZE_REG_64x32 0x4000
#define GBA_BG_SIZE_REG_32x64 0x8000
#define GBA_BG_SIZE_REG_64x64 0xC000

#define GBA_BG_SIZE_AFF_16x16   0x0000
#define GBA_BG_SIZE_AFF_32x32   0x4000
#define GBA_BG_SIZE_AFF_64x64   0x8000
#define GBA_BG_SIZE_AFF_128x128 0xC000

#define GBA_BG0_HOFF (* reinterpret_cast<volatile uint16_t *>(0x04000010))
#define GBA_BG0_VOFF (* reinterpret_cast<volatile uint16_t *>(0x04000012))
#define GBA_BG1_HOFF (* reinterpret_cast<volatile uint16_t *>(0x04000014))
#define GBA_BG1_VOFF (* reinterpret_cast<volatile uint16_t *>(0x04000016))
#define GBA_BG2_HOFF (* reinterpret_cast<volatile uint16_t *>(0x04000018))
#define GBA_BG2_VOFF (* reinterpret_cast<volatile uint16_t *>(0x0400001A))
#define GBA_BG3_HOFF (* reinterpret_cast<volatile uint16_t *>(0x0400001C))
#define GBA_BG3_VOFF (* reinterpret_cast<volatile uint16_t *>(0x0400001E))

#define GBA_BGTILE_VFLIP 0x400
#define GBA_BGTILE_HFLIP 0x800

/*
Sprites
*/
#define SPRITE_COUNT 128

struct spr_attr_t {
	inline spr_attr_t():
		attr_0(0x0200),
		attr_1(0),
		attr_2(0) {
	}
	
	uint16_t attr_0;
	uint16_t attr_1;
	uint16_t attr_2;
	uint16_t aff_weight;
};

#define GBA_OAM (reinterpret_cast <volatile spr_attr_t *>(0x07000000))

#define GBA_OAM_ATTR0_Y_MASK 0x00FF

#define GBA_OAM_ATTR0_AFF_MODE_REGULAR 0x0000
#define GBA_OAM_ATTR0_AFF_MODE_AFFINE 0x0100
#define GBA_OAM_ATTR0_AFF_MODE_DISABLE 0x0200
#define GBA_OAM_ATTR0_AFF_MODE_AFFINE2X 0x0300

#define GBA_OAM_ATTR0_BLEND_MODE_REGULAR 0x0000
#define GBA_OAM_ATTR0_BLEND_MODE_ALPHA 0x0400
#define GBA_OAM_ATTR0_BLEND_MODE_WINDOW_MASK 0x0800

#define GBA_OAM_ATTR0_MOSAIC_ENABLE 0x1000

#define GBA_OAM_ATTR0_COLOR_4BPP 0x0000
#define GBA_OAM_ATTR0_COLOR_8BPP 0x2000

#define GBA_OAM_ATTR0_SHAPE_SQUARE 0x0000
#define GBA_OAM_ATTR0_SHAPE_WIDE 0x4000
#define GBA_OAM_ATTR0_SHAPE_TALL 0x8000
#define GBA_OAM_ATTR0_SHAPE_MASK 0xC000

#define GBA_OAM_ATTR1_X_MASK 0x01FF

#define GBA_OAM_ATTR1_AFFINE_INDEX_MASK 0x3E00
#define GBA_OAM_ATTR1_AFFINE_INDEX_SHIFT 9

#define GBA_OAM_ATTR1_VFLIP 0x1000
#define GBA_OAM_ATTR1_HFLIP 0x2000

#define GBA_OAM_ATTR1_SIZE_0 0x0000
#define GBA_OAM_ATTR1_SIZE_1 0x4000
#define GBA_OAM_ATTR1_SIZE_2 0x8000
#define GBA_OAM_ATTR1_SIZE_3 0xC000

#define GBA_OAM_ATTR2_TILE_INDEX_MASK 0x03FF

#define GBA_OAM_ATTR2_PRIORITY_MASK 0x0C00
#define GBA_OAM_ATTR2_PRIORITY_SHIFT 10

#define GBA_OAM_ATTR2_PAL_NUM_MASK 0xF000
#define GBA_OAM_ATTR2_PAL_NUM_SHIFT 12

/*
Mosaic
======
*/
#define GBA_MOSAIC_CONTROL (* reinterpret_cast<volatile uint16_t *>(0x0400004C))

#define GBA_MOSAIC_BG_W(x) ((x & 0xF) << 0)
#define GBA_MOSAIC_BG_H(x) ((x & 0xF) << 4)
#define GBA_MOSAIC_SPRITE_W(x) ((x & 0xF) << 8)
#define GBA_MOSAIC_SPRITE_H(x) ((x & 0xF) << 12)

/*
VRAM Zones
==========
simple enum for several other peices of code including asset managers
*/
enum class VramZone {
	Background,
	Sprite
};

/*
Keys
====
*/

#define GBA_KEYS (* reinterpret_cast<volatile uint16_t *>(0x4000130))

#define GBA_KEY_A          0x0001
#define GBA_KEY_B          0x0002
#define GBA_KEY_SELECT     0x0004
#define GBA_KEY_START      0x0008
#define GBA_KEY_RIGHT      0x0010
#define GBA_KEY_LEFT       0x0020
#define GBA_KEY_UP         0x0040
#define GBA_KEY_DOWN       0x0080
#define GBA_KEY_R_SHOULDER 0x0100
#define GBA_KEY_L_SHOULDER 0x0200

/*
Interrupts
==========
*/

#define GBA_INTERRUPT_ROUTINE_PTR (* reinterpret_cast<void (* volatile * )()>(0x03007FFC))

#define GBA_INTERRUPT_ENABLE (* reinterpret_cast<volatile uint16_t *>(0x04000200))
#define GBA_INTERRUPT_FLAGS (* reinterpret_cast<volatile uint16_t *>(0x04000202))
#define GBA_INTERRUPT_FLAGS_BIOS (* reinterpret_cast<volatile uint16_t *>(0x03007FF8))


#define GBA_INTERRUPT_VBLANK 0x0001
#define GBA_INTERRUPT_HBLANK 0x0002
#define GBA_INTERRUPT_VCOUNT 0x0004
#define GBA_INTERRUPT_TIMER_0 0x0008
#define GBA_INTERRUPT_TIMER_1 0x0010
#define GBA_INTERRUPT_TIMER_2 0x0020
#define GBA_INTERRUPT_TIMER_3 0x0040
#define GBA_INTERRUPT_SERIAL 0x0080
#define GBA_INTERRUPT_DMA_0 0x0100
#define GBA_INTERRUPT_DMA_1 0x0200
#define GBA_INTERRUPT_DMA_2 0x0400
#define GBA_INTERRUPT_DMA_3 0x0800
#define GBA_INTERRUPT_KEYS 0x1000
#define GBA_INTERRUPT_CARTRIDGE 0x2000

#define GBA_INTERRUPT_MASTER_ENABLE (* reinterpret_cast<volatile uint16_t *>(0x04000208))


/*
Sound
=====
*/

#define GBA_SOUND_STATUS (* reinterpret_cast<uint16_t *>(0x04000084))

#define GBA_SOUND_STATUS_MASTER_ENABLE 0x0080

#define GBA_SOUND_DMG_CONTROL (* reinterpret_cast<uint16_t *>(0x04000080))

#define GBA_SOUND_DMG_CONTROL_VOLUME_L_MASK 0x0007
#define GBA_SOUND_DMG_CONTROL_VOLUME_R_MASK 0x0070
#define GBA_SOUND_DMG_CONTROL_VOLUME_R_SHIFT 4

#define GBA_SOUND_DMG_CONTROL_SQUARE1_L_EN 0x1000
#define GBA_SOUND_DMG_CONTROL_SQUARE2_L_EN 0x2000
#define GBA_SOUND_DMG_CONTROL_WAVE_L_EN    0x4000
#define GBA_SOUND_DMG_CONTROL_NOISE_L_EN   0x8000
#define GBA_SOUND_DMG_CONTROL_SQUARE1_R_EN 0x1000
#define GBA_SOUND_DMG_CONTROL_SQUARE2_R_EN 0x2000
#define GBA_SOUND_DMG_CONTROL_WAVE_R_EN    0x4000
#define GBA_SOUND_DMG_CONTROL_NOISE_R_EN   0x8000

#define GBA_SOUND1_CONTROL_A (* reinterpret_cast<volatile uint16_t *>(0x04000060))
#define GBA_SOUND1_CONTROL_B (* reinterpret_cast<volatile uint16_t *>(0x04000062))
#define GBA_SOUND1_CONTROL_C (* reinterpret_cast<volatile uint16_t *>(0x04000064))

#define GBA_SOUND2_CONTROL_A (* reinterpret_cast<volatile uint16_t *>(0x04000068))
#define GBA_SOUND2_CONTROL_B (* reinterpret_cast<volatile uint16_t *>(0x0400006C))

#define GBA_SOUND2_CONTROL_A_LENGTH_MASK 0x003F

#define GBA_SOUND2_CONTROL_A_DUTY_CYCLE_12_5 0x0000
#define GBA_SOUND2_CONTROL_A_DUTY_CYCLE_25   0x0040
#define GBA_SOUND2_CONTROL_A_DUTY_CYCLE_50   0x0080
#define GBA_SOUND2_CONTROL_A_DUTY_CYCLE_75   0x00C0
#define GBA_SOUND2_CONTROL_A_DUTY_CYCLE_MASK 0x00C0

#define GBA_SOUND2_CONTROL_A_ENVELOPE_TIME_SHIFT 8
#define GBA_SOUND2_CONTROL_A_ENVELOPE_TIME_MASK 0x0700

#define GBA_SOUND2_CONTROL_A_ENVELOPE_TIME(x) ((x << GBA_SOUND2_CONTROL_A_ENVELOPE_TIME_SHIFT) & GBA_SOUND2_CONTROL_A_ENVELOPE_TIME_MASK)

#define GBA_SOUND2_CONTROL_A_ENVELOPE_DIRECTION_DECREASE 0
#define GBA_SOUND2_CONTROL_A_ENVELOPE_DIRECTION_INCREASE 0x0400

#define GBA_SOUND2_CONTROL_A_INITIAL_VOLUME_MASK 0xF000
#define GBA_SOUND2_CONTROL_A_INITIAL_VOLUME_SHIFT 12

#define GBA_SOUND2_CONTROL_A_INITIAL_VOLUME(x) ((x << GBA_SOUND2_CONTROL_A_INITIAL_VOLUME_SHIFT) & GBA_SOUND2_CONTROL_A_INITIAL_VOLUME_MASK)

#define GBA_SOUND2_CONTROL_B_FREQUENCY_MASK 0x07FF

#define GBA_SOUND2_CONTROL_B_STOP_ON_TIMEOUT 0x4000

#define GBA_SOUND2_CONTROL_B_START 0x8000

#define GBA_SOUND3_CONTROL_A (* reinterpret_cast<volatile uint16_t *>(0x04000070))
#define GBA_SOUND3_CONTROL_B (* reinterpret_cast<volatile uint16_t *>(0x04000072))
#define GBA_SOUND3_CONTROL_C (* reinterpret_cast<volatile uint16_t *>(0x04000074))

#define GBA_SOUND_CONTROL_A (* reinterpret_cast<volatile uint16_t *>(0x04000080))
#define GBA_SOUND_CONTROL_B (* reinterpret_cast<volatile uint16_t *>(0x04000082))
#define GBA_SOUND_CONTROL_C (* reinterpret_cast<volatile uint16_t *>(0x04000084))

#define GBA_SOUND_CONTROL_A_MASTER_VOLUME_RIGHT_MASK 0x0007
#define GBA_SOUND_CONTROL_A_MASTER_VOLUME_RIGHT(x) x

#define GBA_SOUND_CONTROL_A_MASTER_VOLUME_LEFT_MASK  0x0070
#define GBA_SOUND_CONTROL_A_MASTER_VOLUME_LEFT_SHIFT 4
#define GBA_SOUND_CONTROL_A_MASTER_VOLUME_LEFT(x) ((x << GBA_SOUND_CONTROL_A_MASTER_VOLUME_LEFT_SHIFT) & GBA_SOUND_CONTROL_A_MASTER_VOLUME_LEFT_MASK)

#define GBA_SOUND_CONTROL_A_SOUND1_RIGHT_EN 0x0100
#define GBA_SOUND_CONTROL_A_SOUND2_RIGHT_EN 0x0200
#define GBA_SOUND_CONTROL_A_SOUND3_RIGHT_EN 0x0400
#define GBA_SOUND_CONTROL_A_SOUND4_RIGHT_EN 0x0800
#define GBA_SOUND_CONTROL_A_SOUND1_LEFT_EN  0x1000
#define GBA_SOUND_CONTROL_A_SOUND2_LEFT_EN  0x2000
#define GBA_SOUND_CONTROL_A_SOUND3_LEFT_EN  0x4000
#define GBA_SOUND_CONTROL_A_SOUND4_LEFT_EN  0x8000

#define GBA_SOUND_CONTROL_B_SOUND_1_TO_4_VOLUME_25  0x0000
#define GBA_SOUND_CONTROL_B_SOUND_1_TO_4_VOLUME_50  0x0001
#define GBA_SOUND_CONTROL_B_SOUND_1_TO_4_VOLUME_100 0x0002
#define GBA_SOUND_CONTROL_B_SOUND_1_TO_4_VOLUME_MASK 0x0003

#define GBA_SOUND_CONTROL_B_PCM_A_VOLUME_100 0x0004
#define GBA_SOUND_CONTROL_B_PCM_A_VOLUME_50 0x0000

#define GBA_SOUND_CONTROL_B_PCM_B_VOLUME_100 0x0008
#define GBA_SOUND_CONTROL_B_PCM_B_VOLUME_50 0x0000

#define GBA_SOUND_CONTROL_B_PCM_A_RIGHT_EN     0x0100
#define GBA_SOUND_CONTROL_B_PCM_A_LEFT_EN      0x0200
#define GBA_SOUND_CONTROL_B_PCM_A_TIMER_SELECT 0x0400
#define GBA_SOUND_CONTROL_B_PCM_A_DMA_RESET_FIFO   0x0800

#define GBA_SOUND_CONTROL_B_PCM_B_RIGHT_EN     0x1000
#define GBA_SOUND_CONTROL_B_PCM_B_LEFT_EN      0x2000
#define GBA_SOUND_CONTROL_B_PCM_B_TIMER_SELECT 0x4000
#define GBA_SOUND_CONTROL_B_PCM_B_DMA_RESET_FIFO   0x8000

#define GBA_SOUND_CONTROL_C_MASTER_EN 0x0080

#define GBA_WAVE_RAM (* reinterpret_cast<volatile uint16_t *>(0x04000090))

#define GBA_SOUND_FIFO_A (* reinterpret_cast<volatile uint32_t *>(0x040000A0))
#define GBA_SOUND_FIFO_B (* reinterpret_cast<volatile uint32_t *>(0x040000A4))

/*
DMA
===
*/

#define GBA_DMA_SOURCE(n) (* reinterpret_cast<volatile uint32_t *>(0x040000B0 + 0x0C * n))
#define GBA_DMA_DESTINATION(n) (* reinterpret_cast<volatile uint32_t *>(0x040000B4 + 0x0C * n))
#define GBA_DMA_CONTROL(n) (* reinterpret_cast<volatile uint32_t *>(0x040000B8 + 0x0C * n))

#define GBA_DMA0_SOURCE GBA_DMA_SOURCE(0)
#define GBA_DMA1_SOURCE GBA_DMA_SOURCE(1)
#define GBA_DMA2_SOURCE GBA_DMA_SOURCE(2)
#define GBA_DMA3_SOURCE GBA_DMA_SOURCE(3)

#define GBA_DMA0_DESTINATION GBA_DMA_DESTINATION(0)
#define GBA_DMA1_DESTINATION GBA_DMA_DESTINATION(1)
#define GBA_DMA2_DESTINATION GBA_DMA_DESTINATION(2)
#define GBA_DMA3_DESTINATION GBA_DMA_DESTINATION(3)

#define GBA_DMA0_CONTROL GBA_DMA_CONTROL(0)
#define GBA_DMA1_CONTROL GBA_DMA_CONTROL(1)
#define GBA_DMA2_CONTROL GBA_DMA_CONTROL(2)
#define GBA_DMA3_CONTROL GBA_DMA_CONTROL(3)

#define GBA_DMA_CONTROL_N_MASK 0x0000FFFF

#define GBA_DMA_CONTROL_DEST_ADJUST_INC      0x00000000
#define GBA_DMA_CONTROL_DEST_ADJUST_DEC      0x00200000
#define GBA_DMA_CONTROL_DEST_ADJUST_FIXED    0x00400000
#define GBA_DMA_CONTROL_DEST_ADJUST_INC_LOOP 0x00600000
#define GBA_DMA_CONTROL_DEST_ADJUST_MASK     0x00600000

#define GBA_DMA_CONTROL_SOURCE_ADJUST_INC   0x00000000
#define GBA_DMA_CONTROL_SOURCE_ADJUST_DEC   0x00800000
#define GBA_DMA_CONTROL_SOURCE_ADJUST_FIXED 0x01000000
#define GBA_DMA_CONTROL_SOURCE_ADJUST_MASK  0x01800000

#define GBA_DMA_CONTROL_REPEATE 0x02000000

#define GBA_DMA_CONTROL_CHUNK_SIZE_16 0x00000000
#define GBA_DMA_CONTROL_CHUNK_SIZE_32 0x04000000

#define GBA_DMA_CONTROL_TIMING_NOW        0x00000000
#define GBA_DMA_CONTROL_TIMING_AT_VBLANK  0x10000000
#define GBA_DMA_CONTROL_TIMING_AT_HBLANK  0x20000000
#define GBA_DMA_CONTROL_TIMING_FIFO       0x30000000

#define GBA_DMA_CONTROL_IRQ_EN 0x40000000
#define GBA_DMA_CONTROL_ENABLE 0x80000000

/*
Timers
======
*/

#define GBA_TIMER_DATA(n) (* reinterpret_cast<volatile uint16_t *>(0x04000100 + n * 4))
#define GBA_TIMER_CONTROL(n) (* reinterpret_cast<volatile uint16_t *>(0x04000102 + n * 4))

#define GBA_TIMER0_DATA GBA_TIMER_DATA(0)
#define GBA_TIMER1_DATA GBA_TIMER_DATA(1)
#define GBA_TIMER2_DATA GBA_TIMER_DATA(2)
#define GBA_TIMER3_DATA GBA_TIMER_DATA(3)

#define GBA_TIMER0_CONTROL GBA_TIMER_CONTROL(0)
#define GBA_TIMER1_CONTROL GBA_TIMER_CONTROL(1)
#define GBA_TIMER2_CONTROL GBA_TIMER_CONTROL(2)
#define GBA_TIMER3_CONTROL GBA_TIMER_CONTROL(3)

#define GBA_TIMER_CONTROL_FREQUENCY_16_78_MHZ       0x0000
#define GBA_TIMER_CONTROL_FREQUENCY_262187_5_KHZ    0x0001
#define GBA_TIMER_CONTROL_FREQUENCY_65546_875_KHZ   0x0002
#define GBA_TIMER_CONTROL_FREQUENCY_16386_71875_KHZ 0x0003
#define GBA_TIMER_CONTROL_FREQUENCY_MASK            0x0003

#define GBA_TIMER_CONTROL_CASCADE 0x0004

#define GBA_TIMER_CONTROL_INTERRUPT_EN 0x0040
#define GBA_TIMER_CONTROL_EN 0x0080

#endif
