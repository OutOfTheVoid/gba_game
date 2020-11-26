#ifndef UTIL_VECTOR_HPP
#define UTIL_VECTOR_HPP

#include <cstdint>
#include <initializer_list>
#include <cstdlib>

template<class T>
class Vector {
public:
	enum class PREALLOC {
		p
	};
	
	Vector (PREALLOC p, uint32_t prealloc):
		backing_size(prealloc),
		size(0),
		elements((T *) malloc(sizeof(T) * backing_size)) {
	}
	
	Vector():
		elements(nullptr),
		backing_size(0),
		size(0) {
	}
	
	Vector(std::initializer_list<T> init_list):
		backing_size(init_list.size() * 2),
		elements((T *) malloc(sizeof(T) * backing_size)),
		size(init_list.size()) {
		uint32_t i = 0;
		auto iter = init_list.begin();
		while(iter != init_list.end()) {
			elements[i] = * iter;
			i ++;
			iter ++;
		}
	}
	
	~Vector() {
		free(reinterpret_cast<void *>(elements));
	}
	
	const T & operator[](int i) const {
		return elements[i];
	}
	
	T & operator[](int i) {
		return elements[i];
	}
	
	uint32_t get_size() {
		return size;
	}
	
	uint32_t get_capacity() {
		return backing_size;
	}
	
	void push(T element) {
		reserve(size + 1);
		elements[size] = element;
		size ++;
	}
	
	T pop() {
		size --;
		return elements[size];
	}
	
	void remove(uint32_t start, uint32_t count = 1) {
		if (start >= size) {
			return;
		}
		uint32_t copy_start = start + count;
		uint32_t copy_count = count;
		if (size - copy_start >= count) {
			copy_count = size - copy_start;
		}
		for (uint32_t i = start; i < start + copy_count; i ++) {
			elements[i] = elements[i + count];
		}
		size -= count;
	}
	
	void insert(T element, uint32_t index) {
		if (index >= size) {
			push(element);
			return;
		}
		reserve(size + 1);
		for (uint32_t i = size; i > index; i ++) {
			elements[i] = elements[i - 1];
		}
		elements[index] = element;
		size ++;
	}
	
	int32_t index_of(const T & test) {
		for (uint32_t i = 0; i < size; i ++) {
			if (elements[i] == test) {
				return i;
			}
		}
		return -1;
	}
	
	template <class COMPARE_T>
	int32_t index_of(COMPARE_T compare_value, bool (* is_equal)(COMPARE_T a, const T & b)) {
		for (uint32_t i = 0; i < size; i ++) {
			if (is_equal(compare_value, elements[i])) {
				return i;
			}
		}
		return -1;
	}
	
	T * find(const T & test) {
		for (uint32_t i = 0; i < size; i ++) {
			if (elements[i] == test) {
				return elements[i];
			}
		}
		return nullptr;
	}
	
	T * find(const T & test, bool (* is_equal)(const T & a, const T & b)) {
		for (uint32_t i = 0; i < size; i ++) {
			if (is_equal(test, elements[i])) {
				return elements[i];
			}
		}
		return nullptr;
	}
	
	void reserve(uint32_t count) {
		if (count <= backing_size) {
			return;
		}
		uint32_t backing_size = this->backing_size;
		if (backing_size == 0) {
			backing_size = 1;
		}
		while (count > backing_size) {
			backing_size <<= 1;
		}
		T * new_elements = reinterpret_cast<T *>(realloc(elements, sizeof(T) * backing_size));
		this->elements = new_elements;
		this->backing_size = backing_size;
	}
	
	void clear(bool dealloc = false) {
		size = 0;
		if (dealloc) {
			backing_size = 0;
			free(reinterpret_cast<void *>(elements));
			elements = nullptr;
		}
	}
	
private:
	T * elements;
	uint32_t backing_size;
	uint32_t size;
};

#endif
