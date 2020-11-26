#include "game/random.hpp"
#include "gba/interrupts.hpp"

//#define RANDOM_ENABLE_INTERRUPT_ACCESS

#if defined(RANDOM_ENABLE_INTERRUPT_ACCESS)
#endif

uint64_t rol64(uint64_t x, int k)
{
	return (x << k) | (x >> (64 - k));
}

struct Xoshiro256ss_state {
	uint64_t s[4];
};

uint64_t xoshiro256ss(Xoshiro256ss_state &state)
{
	uint64_t *s = state.s;
	uint64_t const result = rol64(s[1] * 5, 7) * 9;
	uint64_t const t = s[1] << 17;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;
	s[3] = rol64(s[3], 45);

	return result;
}

static Xoshiro256ss_state _gba_global_xoshiro256ss_state{{0x4685307f2e2c9b43ULL, 0xfdfcaa91110765b6ULL, 0x6dc878990b1ea4dbULL, 0xf74ff5fab0e603daULL}};

uint64_t random_u64() {
	#if defined(RANDOM_ENABLE_INTERRUPT_ACCESS)
	bool int_block = block_interrups();
	#endif
	uint64_t result = xoshiro256ss(_gba_global_xoshiro256ss_state);
	#if defined(RANDOM_ENABLE_INTERRUPT_ACCESS)
	restore_interrupts(int_block);
	#endif
	return result;
}
