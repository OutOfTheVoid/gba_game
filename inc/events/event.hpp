#ifndef EVENTS_EVENT_HPP
#define EVENTS_EVENT_HPP

#include "util/vector.hpp"

class Event {
public:
	static const uint32_t InvalidEventID = 0xFFFFFFFF;
	
	Event();
	
	uint32_t add_listener(void (* listener)(void * data), void * data);
	void remove_listener(uint32_t id);
	
	void dispatch();
	
private:
	struct listener_data_t {
		void (* listener)(void * data);
		void * data;
		uint32_t id;
	};
	
	static bool event_compare_fn(uint32_t id, const listener_data_t & listener);
	
	Vector<listener_data_t> listeners;
	uint32_t id_counter;
};

#endif
