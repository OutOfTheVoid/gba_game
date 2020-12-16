#ifndef GBA_BIOS_HPP
#define GBA_BIOS_HPP

#include "util.hpp"
#include "interrupts.hpp"
#include "hal.hpp"

inline static void init_vblank_intr_wait() {
	GBA_DISPLAY_STATUS |= GBA_DISPLAY_STATUS_VBLANK_INTR_EN;
	set_interrupt_enabled(Interrupt::VBlank, true);
}

static inline void vblank_intr_wait() {
	asm volatile("swi 0x05");
}

#endif
