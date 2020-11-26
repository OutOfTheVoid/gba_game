#include "gba/panic.hpp"

#include <cstddef>
#include <cstdlib>

extern "C" void __cxa_pure_virtual() {
	panic();
}

void* operator new (std::size_t size) {
	void * mem = malloc(size);
	if (mem == nullptr) {
		panic();
	}
	return mem;
}

void* operator new[] (std::size_t size) {
	void * mem = malloc(size);
	if (mem == nullptr) {
		panic();
	}
	return mem;
}

void operator delete[] (void * mem) {
	free(mem);
}

void operator delete[] (void * mem, unsigned int size) {
	(void) size;
	free(mem);
}
