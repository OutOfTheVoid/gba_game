#include "gba/interrupts.hpp"
#include "gba/hal.hpp"
#include "gba/util.hpp"

void ARM_CODE master_isr();

bool block_interrups() {
	bool state = GBA_INTERRUPT_MASTER_ENABLE != 0;
	GBA_INTERRUPT_MASTER_ENABLE = 0;
	return state;
}

void restore_interrupts(bool state) {
	GBA_INTERRUPT_MASTER_ENABLE = state ? 1 : 0;
}

void (* handlers[14])() = {
};

void init_interrupts() {
	GBA_INTERRUPT_MASTER_ENABLE = 0;
	GBA_INTERRUPT_ENABLE = 0;
	for (int i = 0; i < 14; i ++) {
		handlers[i] = nullptr;
	}
	GBA_INTERRUPT_ROUTINE_PTR = & master_isr;
	GBA_INTERRUPT_MASTER_ENABLE = 1;
}


void set_interrupt_enabled(Interrupt interrupt, bool enabled) {
	uint16_t int_bit = 1 << static_cast<int32_t>(interrupt);
	if (enabled) {
		GBA_INTERRUPT_ENABLE |= int_bit;
	} else {
		GBA_INTERRUPT_ENABLE &= ~int_bit;
	}
}

void set_handler(Interrupt interrupt, void (* handler)()) {
	bool int_state = block_interrups();
	int int_num = static_cast<int>(interrupt);
	uint16_t int_bit = 1 << int_num;
	handlers[int_num] = handler;
	if (handler != nullptr) {
		GBA_INTERRUPT_ENABLE |= int_bit;
	} else {
		GBA_INTERRUPT_ENABLE &= ~int_bit;
	}
	restore_interrupts(int_state);
}

void ARM_CODE master_isr() {
	bool iblock = block_interrups();
	uint16_t interrupts = GBA_INTERRUPT_FLAGS;
	for (int i = 0; i < 14; i ++) {
		if (((interrupts & (1 << i)) != 0) && (handlers[i] != nullptr)) {
			handlers[i]();
		}
	}
	GBA_INTERRUPT_FLAGS_BIOS = interrupts;
	GBA_INTERRUPT_FLAGS = interrupts;
	restore_interrupts(iblock);
}
