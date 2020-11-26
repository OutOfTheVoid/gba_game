#ifndef GAME_PLAYER_WALK_HPP
#define GAME_PLAYER_WALK_HPP

#include "walk_area.hpp"

class PlayerWalk;

class WalkAreaGroup {
public:
	WalkAreaGroup(const WalkArea ** areas, uint32_t area_count, int32_t priority = 0);
	
	bool test_areas(Vec2 position);
	
	void set_enter_callback(void (* enter_cb)(void * data), void * data);
	void set_exit_callback(void (* exit_cb)(void * data), void * data);
	
private:
	friend class PlayerWalk;
	
	const WalkArea ** areas;
	uint32_t area_count;
	int32_t priority;
	
	WalkAreaGroup * next;
	WalkAreaGroup * last;
	bool has_player;
	
	void (* enter_cb)(void * data);
	void * enter_data;
	void (* exit_cb)(void * data);
	void * exit_data;
};

class PlayerWalk {
public:
	PlayerWalk(Vec2 start_position);
	
	void add_area_group(WalkAreaGroup * group);
	void remove_area_group(WalkAreaGroup * group);
	
	bool set_position(Vec2 new_position, bool force);
	
	void walk(Vec2 direction);
	Vec2 get_position();
	
private:
	Vec2 position;
	
	WalkAreaGroup * head;
	WalkAreaGroup * current;
};

#endif
