#include "events/event.hpp"

Event::Event():
	listeners(),
	id_counter() {
}

uint32_t Event::add_listener(void (* listener)(void * data_arg), void * data) {
	uint32_t id = id_counter;
	id_counter ++;
	listeners.push((listener_data_t) {
		listener,
		data,
		id
	});
	return id;
}

bool Event::event_compare_fn(uint32_t id, const listener_data_t & listener) {
	return listener.id == id;
}

void Event::remove_listener(uint32_t id) {
	int32_t index = listeners.index_of<uint32_t>(id, & event_compare_fn);
	if (index >= 0) {
		listeners.remove(index);
	}
}

void Event::dispatch() {
	uint32_t count = listeners.get_size();
	for (uint32_t i = 0; i < count; i ++) {
		listeners[i].listener(listeners[i].data);
	}
}
