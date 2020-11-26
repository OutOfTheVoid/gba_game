#ifndef GBA_MEM_HPP
#define GBA_MEM_HPP

#include <cstdint>

inline static void memcpy_16(const void * src, void * dst, uint32_t size) {
	const uint16_t * src_end = reinterpret_cast<const uint16_t *>(reinterpret_cast<uint32_t>(src) + (size << 1));
	const uint16_t * src_16 = reinterpret_cast <const uint16_t *>(src);
	uint16_t * dst_16 = reinterpret_cast <uint16_t *>(dst);
	while (src_16 < src_end) {
		* dst_16 = * src_16;
		src_16 ++;
		dst_16 ++;
	}
}

inline static void memcpy_16v(const void * src, volatile void * dst, uint32_t size) {
	const uint16_t * src_end = reinterpret_cast<const uint16_t *>(reinterpret_cast<uint32_t>(src) + (size << 1));
	const uint16_t * src_16 = reinterpret_cast <const uint16_t *>(src);
	volatile uint16_t * dst_16 = reinterpret_cast <volatile uint16_t *>(dst);
	while (src_16 < src_end) {
		* dst_16 = * src_16;
		src_16 ++;
		dst_16 ++;
	}
}

#endif
