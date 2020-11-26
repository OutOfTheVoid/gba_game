#ifndef GBA_TILE_HPP
#define GBA_TILE_HPP

#include "hal.hpp"
#include "mem.hpp"

inline static void blit_tile_4bpp(tile_4bpp_t & tile, int x, int y, int value) {
	int word = (x >> 2) + (y << 1);
	int nibble_shift = ((x & 3)) << 2;
	uint16_t tile_value = tile[word];
	tile_value &= ~(0x0F << nibble_shift);
	tile_value |= (value & 0x0F) << nibble_shift;
	tile[word] = tile_value;
}

inline static void fill_tile_4bpp(tile_4bpp_t & tile, int value) {
	value &= 0x0F;
	value = value | (value << 4);
	value = value | (value << 8);
	for (int i = 0; i < 16; i ++) {
		tile[i] = value;
	}
}

inline static void draw_rect_tile_4bpp(tile_4bpp_t & tile, int x, int y, int width, int height, int value, int edge_value = -1) {
	int x_high = x + width - 1;
	int y_high = y + height - 1;
	int x_low = x;
	int y_low = y;
	if (edge_value < 0) {
		edge_value = value;
	}
	for (x = x_low; x <= x_high; x ++) {
		for (y = y_low; y <= y_high; y ++) {
			bool edge = (x == x_low) || (x == x_high) || (y == y_low) || (y == y_high);
			if (edge) {
				blit_tile_4bpp(tile, x, y, edge_value);
			} else {
				blit_tile_4bpp(tile, x, y, value);
			}
		}
	}
	
}

inline static void set_tilemap_entry(volatile tilemap_t * tilemap, int x, int y, uint16_t index) {
	(* tilemap)[y][x] = index;
}

inline static void copy_tilemap(volatile tilemap_t * tilemap, const tilemap_t & source) {
	memcpy_16v(& source, tilemap, 1024);
}
inline static void copy_tilemap_with_offset(volatile tilemap_t * tilemap, const tilemap_t & source, uint16_t offset) {
	for (int x = 0; x < 32; x ++) {
		for (int y = 0; y < 32; y ++) {
			(*tilemap)[y][x] = source[y][x] + offset;
		}
	}
}

inline static void clear_tilemap(volatile tilemap_t * tilemap, uint16_t value) {
	for (int x = 0; x < 32; x ++) {
		for (int y = 0; y < 32; y ++) {
			(*tilemap)[y][x] = value;
		}
	}
}

inline static void copy_tile_4bpp(volatile tile_4bpp_t * tile_block, int tile, const tile_4bpp_t & source) {
	memcpy_16v(reinterpret_cast<const void *>(& source), reinterpret_cast<volatile void *>(& tile_block[tile]), 16);
}

inline static void copy_tile_8bpp(volatile tile_8bpp_t * tile_block, int tile, const tile_4bpp_t & source) {
	memcpy_16v(reinterpret_cast<const void *>(& source), reinterpret_cast<volatile void *>(& tile_block[tile]), 32);
}

#endif
