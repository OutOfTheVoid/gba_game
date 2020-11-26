#ifndef GBA_UTIL_HPP
#define GBA_UTIL_HPP

#define ARM_CODE __attribute((__target__("arm")))

#define THUMB_CODE __attribute((__target__("thumb")))

#define IWRAM __attribute((section(".iwram")))

#define ALIGN_4 __attribute((aligned (4)))

#endif
