#include "game/collision/player_walk.hpp"

WalkAreaGroup::WalkAreaGroup(const WalkArea ** areas, uint32_t area_count, int32_t priority):
	areas(areas),
	area_count(area_count),
	priority(priority),
	next(nullptr),
	last(nullptr),
	has_player(false),
	enter_cb(nullptr),
	enter_data(nullptr),
	exit_cb(nullptr),
	exit_data(nullptr) {
}

bool WalkAreaGroup::test_areas(Vec2 position) {
	for (uint32_t i = 0; i < area_count; i ++) {
		if (areas[i]->test_area(position)) {
			return true;
		}
	}
	return false;
}

void WalkAreaGroup::set_enter_callback(void (* enter_cb)(void * data), void * data) {
	this->enter_cb = enter_cb;
	this->enter_data = data;
}

void WalkAreaGroup::set_exit_callback(void (* exit_cb)(void * data), void * data) {
	this->exit_cb = exit_cb;
	this->exit_data = data;
}

PlayerWalk::PlayerWalk(Vec2 start_position):
	position(start_position),
	head(nullptr),
	current(nullptr) {
}

void PlayerWalk::add_area_group(WalkAreaGroup * group) {
	if (head == nullptr) {
		head = group;
	} else {
		group->next = head;
		head->last = group;
		head = group;
	}
}

void PlayerWalk::remove_area_group(WalkAreaGroup * group) {
	if (current == group) {
		current = nullptr;
	}
	if (group->next != nullptr) {
		group->next->last = group->last;
	}
	if (group->last != nullptr) {
		group->last->next = group->next;
	}
	if (head == group) {
		head = group->next;
	}
	group->next = nullptr;
	group->last = nullptr;
}

bool PlayerWalk::set_position(Vec2 new_position, bool force) {
	int highest_prio = INT32_MIN;
	WalkAreaGroup * highest_match = nullptr;
	WalkAreaGroup * search = head;
	while(search != nullptr) {
		if (search->test_areas(new_position)) {
			if (search->priority > highest_prio) {
				highest_prio = search->priority;
				highest_match = search;
			}
		}
		search = search->next;
	}
	if (highest_match == nullptr) {
		if (force) {
			current = nullptr;
			position = new_position;
		}
		return false;
	}
	current = highest_match;
	position = new_position;
	return true;
}

void PlayerWalk::walk(Vec2 direction) {
	set_position(position + Vec2(direction.x, 0), false);
	set_position(position + Vec2(0, direction.y), false);
}

Vec2 PlayerWalk::get_position() {
	return position;
}
