#ifndef GBA_KEYS_HPP
#define GBA_KEYS_HPP

#include <cstdint>

#include "gba/hal.hpp"

/*
#define GBA_KEY_A          0x0001
#define GBA_KEY_B          0x0002
#define GBA_KEY_SELECT     0x0004
#define GBA_KEY_START      0x0008
#define GBA_KEY_RIGHT      0x0010
#define GBA_KEY_LEFT       0x0020
#define GBA_KEY_UP         0x0040
#define GBA_KEY_DOWN       0x0080
#define GBA_KEY_R_SHOULDER 0x0100
#define GBA_KEY_L_SHOULDER 0x0200
*/

enum class Key: uint16_t {
	None = 0,
	A = GBA_KEY_A,
	B = GBA_KEY_B,
	Select = GBA_KEY_SELECT,
	Start = GBA_KEY_START,
	Right = GBA_KEY_RIGHT,
	Left = GBA_KEY_LEFT,
	Up = GBA_KEY_UP,
	Down = GBA_KEY_DOWN,
	R_Soulder = GBA_KEY_R_SHOULDER,
	L_Shoulder = GBA_KEY_L_SHOULDER,
	All = 0x3FF,
};

inline Key operator|(const Key a, const Key b) {
	return static_cast<Key>(static_cast<uint16_t>(a) | static_cast<uint16_t>(b));
}

inline Key operator&(const Key a, const Key b) {
	return static_cast<Key>(static_cast<uint16_t>(a) & static_cast<uint16_t>(b));
}

inline Key operator~(const Key x) {
	return static_cast<Key>((~ static_cast<uint16_t>(x)) & static_cast<uint16_t>(Key::All));
}

inline static bool key_down(Key key) {
	return ((~ GBA_KEYS) & static_cast<uint16_t>(key)) == static_cast<uint16_t>(key);
}

class KeyMonitor {
public:
	KeyMonitor();
	void update();
	bool key_pressed(Key key);
	bool key_released(Key key);
	bool key_down(Key key);
	
private:
	Key last_state;
	Key current_state;
};

#endif
