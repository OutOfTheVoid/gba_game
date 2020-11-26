#include "gba/keys.hpp"

KeyMonitor::KeyMonitor():
	last_state(Key::None),
	current_state(Key::None) {
}

void KeyMonitor::update() {
	last_state = current_state;
	current_state = static_cast<Key>(GBA_KEYS);
}

bool KeyMonitor::key_pressed(Key key) {
	return ((current_state & ~last_state) & key) != Key::None;
}

bool KeyMonitor::key_released(Key key) {
	return ((last_state & ~ current_state) & key) != Key::None;
}

bool KeyMonitor::key_down(Key key) {
	return (key & current_state) != Key::None;
}
	
