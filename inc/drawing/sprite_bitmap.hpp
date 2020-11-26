#ifndef DRAWING_PRITE_BITMAP_SHPP
#define DRAWING_PRITE_BITMAP_SHPP

#include "gba/tile.hpp"
#include "gba/tile_manager.hpp"
#include "gba/sprite_manager.hpp"

#include "drawing/bitmap_font.hpp"

class SpriteBitmap {
public:
	// Sets up a Sprite-sized bitmap, residing in
	// vram, and optionally a buffer on the heap. Writing to
	// vram requires staging in the tile manager with the
	// stage(...) method.
	SpriteBitmap(SpriteSize size, bool ram_buffer);
	// Sets up an arbitrarily sized bitmap on the heap. (Cannot be staged)
	SpriteBitmap(int width, int height);
	~SpriteBitmap();
	
	// note: setting false will destroy your buffer. No guarentee it will still be there when set true again
	void set_buffer_state(bool is_buffered);
	
	bool stage(TileManager & tile_manager);
	void unstage(TileManager & tile_manager);
	
	void clear(int color_num);
	void draw_rect(int x, int y, int w, int h, int color);
	void draw_rect_filled(int x, int y, int w, int h, int color);
	void set_pixel(int x, int y, int color);
	
	void draw_text(const char * text, const bitmap_font_t & font, int color, int x, int y, int text_w, int max_lines);
	
	void copy_to_vram();
	
	int get_start_tile();
	
private:
	int w;
	int h;
	bool is_vram_type;
	SpriteSize sprite_size;
	
	dynamic_tile_asset_4bpp_t tile_asset;
	union {
		tile_4bpp_t * vram_back_buffer;
		uint8_t * ram_back_buffer;
	};
};

#endif
