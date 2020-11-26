#ifndef GBA_RGB_HPP
#define GBA_RGB_HPP

#define RGB(r, g, b) static_cast<uint16_t>((b << 10) | (g << 5) | (r << 0))

#define RGB_GREYSCALE(x) RGB(x, x, x)

#define RGB_BLACK RGB_GREYSCALE(0)

#define RGB_WHITE RGB_GREYSCALE(31)

#endif
