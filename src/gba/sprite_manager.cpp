#include "gba/sprite_manager.hpp"
#include "gba/sprite.hpp"

/*
int enabled_attr_count;
int attr_min;
int attr_count;

Sprite * head;
*/

void SpriteManager::init(int attr_min, int attr_count) {
	this->attr_min = attr_min;
	this->attr_count = attr_count;
	last_sprite_count = attr_count;
	clear();
}

void SpriteManager::update() {
	Sprite * current = head;
	int i = 0;
	while(current != nullptr) {
		copy_spr_attr(i + attr_min, current->attrs);
		current = current->next;
		i ++;
	}
	int sprite_count = i;
	spr_attr_t default_attr;
	for (; i < last_sprite_count; i ++) {
		copy_spr_attr(i + attr_min, default_attr);
	}
	last_sprite_count = sprite_count;
}

void SpriteManager::clear() {
	spr_attr_t default_attr;
	for (int i = 0; i < last_sprite_count; i ++) {
		copy_spr_attr(i + attr_min, default_attr);
	}
	last_sprite_count = 0;
	head = nullptr;
}

void SpriteManager::add_sprite(Sprite * sprite) {
	sprite->next = head;
	sprite->last = nullptr;
	if (head != nullptr) {
		head -> last = sprite;
	}
	head = sprite;
}

void SpriteManager::remove_sprite(Sprite * sprite) {
	if (sprite == head) {
		head = sprite -> next;
		sprite->next->last = nullptr;
	} else {
		if (sprite->next != nullptr) {
			sprite->next->last = sprite->last;
		}
		sprite->last->next = sprite->next;
	}
	sprite->next = nullptr;
	sprite->last = nullptr;
}


