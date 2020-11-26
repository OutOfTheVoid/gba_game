#ifndef ANIMATION_EASING_HPP
#define ANIMATION_EASING_HPP

#include "math/fx16.hpp"
//  1 -|        ***********|
//     |   *****           |
//     | **                |
//  0 -|*------------------|
//     |                   |
//     |                   |
// -1 -|                   |
//
// 0 - 1 => 0 - 1 - 0
inline static fx16_t ease_sin_in(fx16_t x) {
	return sin_fx16(x * fx16_t::PI_OVER_2);
}

/*

  f(t)
 1 |     *********     |
   |  ***         ***  |
   | *               * |
 0 |*-----------------*| 1 t
   |                   |
   |                   |
-1 |                   |

*/
inline static fx16_t ease_sin_in_out(fx16_t x) {
	return sin_fx16(x * fx16_t::PI);
}

/*

  f(t)
 1 |**********         |
   |          ******   |
   |                ** |
 0 |------------------*| 1 t
   |                   |
   |                   |
-1 |                   |

*/
inline static fx16_t ease_sin_out(fx16_t x) {
	return sin_fx16(x * fx16_t::PI_OVER_2 + fx16_t::PI_OVER_2);
}

/*

  f(t)
 1 |                ***|
   |            ****   |
   |      ******       |
 0 |******-------------| 1 t
   |                   |
   |                   |
-1 |                   |

*/
inline static fx16_t ease_quadratic_in(fx16_t x) {
	return x * x;
}

/*

  f(t)
 1 |                   |
   |                   |
   |                   |
 0 |-------------------| 1 t
   |                   |
   |                   |
-1 |                   |

*/
//inline static fx16_t ease_

#endif
