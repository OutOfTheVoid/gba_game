#ifndef UTIL_STRING_HPP
#define UTIL_STRING_HPP

#include <cstdint>
#include <cstring>

#define STRING_DEFAULT_BUFF_OVERHEAD 5
#define STRING_DEFAULT_BUFFER 8

enum class StringAllocPolicy {
	Necessary,
	RepeateDoubleFit,
	DoubleOrNecessary,
	DoubleOrNecessaryPlusOverhead,
	NecessaryPlusOverhead,
	Default,
};

class String {
public:
	String():
		str_size(0),
		buff_size(STRING_DEFAULT_BUFFER),
		buffer(new char[STRING_DEFAULT_BUFFER]),
		copy_on_write(false) {
	}
	
	String(const char * c_str, bool copy_on_write = false):
		str_size(strlen(c_str)),
		buff_size(str_size + STRING_DEFAULT_BUFF_OVERHEAD),
		buffer(nullptr),
		copy_on_write(copy_on_write) {
		if (copy_on_write) {
			buffer = const_cast<char *>(c_str);
		} else {
			buffer = new char[buff_size];
			for (uint32_t i = 0; i < str_size; i ++) {
				buffer[i] = c_str[i];
			}
		}
	}
	
	String(const char * source_array, uint32_t str_size, bool copy_on_write = false):
		str_size(str_size),
		buff_size(str_size + STRING_DEFAULT_BUFF_OVERHEAD),
		buffer(nullptr),
		copy_on_write(copy_on_write) {
		if (copy_on_write) {
			buffer = const_cast<char *>(source_array);
		} else {
			buffer = new char[buff_size];
			for (uint32_t i = 0; i < str_size; i ++) {
				buffer[i] = source_array[i];
			}
		}
	}
	
	String(const String & copy_from):
		str_size(copy_from.str_size),
		buff_size(copy_from.str_size + STRING_DEFAULT_BUFF_OVERHEAD),
		buffer(new char[buff_size]),
		copy_on_write(false) {
		for (uint32_t i = 0; i < str_size; i ++) {
			buffer[i] = copy_from.buffer[i];
		}
	}
	
	String(uint32_t size, char fill_char):
		str_size(size),
		buff_size(size + STRING_DEFAULT_BUFF_OVERHEAD),
		buffer(new char[buff_size]),
		copy_on_write(false) {
		for (uint32_t i = 0; i < size; i ++) {
			buffer[i] = fill_char;
		}
	}
	
	String(uint32_t prealloc, uint32_t size, char fill_char):
		str_size(size),
		copy_on_write(false) {
		if (prealloc < size) {
			prealloc = size + 1;
		}
		buffer = new char[prealloc];
	}
	
	~String() {
		if (! copy_on_write) {
			delete[] buffer;
		}
	}
	
	char & operator[](uint32_t index) {
		if (copy_on_write) {
			resolve_cow();
		}
		return buffer[index];
	}
	
	const char & operator[](uint32_t index) const {
		return buffer[index];
	}
	
	uint32_t buffer_size() const {
		return buff_size;
	}
	
	uint32_t size() const {
		return str_size;
	}
	
	bool reserve(uint32_t capacity) {
		if (buff_size < capacity) {
			char * new_buff = new char[capacity];
			uint32_t i = 0;
			for(; i < str_size; i ++) {
				new_buff[i] = buffer[i];
			}
			if (! copy_on_write) {
				delete[] buffer;
			}
			buffer = new_buff;
			buff_size = capacity;
			copy_on_write = false;
		}
		return true;
	}
	
	void trim(uint32_t capacity) {
		if (buff_size > capacity) {
			char * new_buff = new char[capacity];
			uint32_t i = 0;
			for(; i < str_size; i ++) {
				new_buff[i] = buffer[i];
			}
			if (! copy_on_write) {
				delete[] buffer;
			}
			buffer = new_buff;
			buff_size = capacity;
			copy_on_write = false;
		}
	}
	
	void append(const String & str, StringAllocPolicy alloc_policy = StringAllocPolicy::Default) {
		int new_size = str_size + str.str_size;
		reserve_for_policy(new_size, alloc_policy);
		
	}
	
private:
	inline void resolve_cow() {
		if (copy_on_write) {
			copy_on_write = false;
			char * buffer_new = new char[buff_size];
			uint32_t i = 0;
			for(; i < str_size; i ++) {
				buffer_new[i] = buffer[i];
			}
			buffer = buffer_new;
		}
	}
	
	inline void reserve_for_policy(uint32_t reserve_size, StringAllocPolicy policy) {
		if (reserve_size < buff_size) {
			return;
		}
		uint32_t alloc_size = 0;
		switch(policy) {
			case StringAllocPolicy::Necessary: {
				alloc_size = reserve_size + 1;
			} break;
			case StringAllocPolicy::RepeateDoubleFit: {
				alloc_size = buff_size * 2;
				while(alloc_size < reserve_size) {
					alloc_size *= 2;
				}
			} break;
			case StringAllocPolicy::DoubleOrNecessary: {
				alloc_size = buff_size * 2;
				if (alloc_size < reserve_size) {
					alloc_size = reserve_size + 1;
				}
			} break;
			case StringAllocPolicy::DoubleOrNecessaryPlusOverhead: {
				alloc_size = buff_size * 2;
				if (alloc_size < reserve_size) {
					alloc_size = reserve_size + STRING_DEFAULT_BUFF_OVERHEAD;
				}
			} break;
			case StringAllocPolicy::Default:
			case StringAllocPolicy::NecessaryPlusOverhead: {
				alloc_size = reserve_size + STRING_DEFAULT_BUFF_OVERHEAD;
			} break;
		}
		char * buffer_new = new char[alloc_size];
		buff_size = alloc_size;
		uint32_t i = 0;
		for(; i < str_size; i ++) {
			buffer_new[i] = buffer[i];
		}
		delete[] buffer;
		buffer = buffer_new;
	}
	
	uint32_t str_size;
	uint32_t buff_size;
	char * buffer;
	bool copy_on_write;
};

#endif /* UTIL_STRING_HPP */
