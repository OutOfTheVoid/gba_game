#ifndef GBA_INTERRUPTS_HPP
#define GBA_INTERRUPTS_HPP

enum Interrupt {
	VBlank = 0,
	HBlank = 1,
	VCount = 2,
	Timer0 = 3,
	Timer1 = 4,
	Timer2 = 5,
	Timer3 = 6,
	Serial = 7,
	Dma0 = 8,
	Dma1 = 9,
	Dma2 = 10,
	Dma3 = 11,
	Keys = 12,
	Cartridge = 13
};

void init_interrupts();

bool block_interrups();
void restore_interrupts(bool state);

void set_interrupt_enabled(Interrupt interrupt, bool enabled);

void set_handler(Interrupt interrupt, void (* handler)());

#endif
