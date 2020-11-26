#ifndef GBA_TIMER_HPP
#define GBA_TIMER_HPP

#include "hal.hpp"

enum class Timer {
	Timer0 = 0,
	Timer1 = 1,
	Timer2 = 2,
	Timer3 = 3
};

enum class TimerSpeed {
	k16_78MHz = 0,
	k262187_5kHz = 1,
	k65546_875kHz = 2,
	k16386_71875kHz = 3
};

inline static void set_timer_reload(Timer timer, uint16_t reload) {
	GBA_TIMER_CONTROL(static_cast<uint32_t>(timer)) = reload;
}

inline static void setup_timer(Timer timer, TimerSpeed speed, bool interrupt, bool cascade, bool start = false) {
	GBA_TIMER_CONTROL(static_cast<uint32_t>(timer)) = 
		static_cast<uint16_t>(speed) |
		(interrupt ? GBA_TIMER_CONTROL_INTERRUPT_EN : 0) |
		(cascade ? GBA_TIMER_CONTROL_CASCADE : 0) |
		(start ? GBA_TIMER_CONTROL_EN : 0);
}

inline static void start_timer(Timer timer) {
	GBA_TIMER_CONTROL(static_cast<uint32_t>(timer)) |= GBA_TIMER_CONTROL_EN;
}

inline static void stop_timer(Timer timer) {
	GBA_TIMER_CONTROL(static_cast<uint32_t>(timer)) &= ~GBA_TIMER_CONTROL_EN;
}

#endif
