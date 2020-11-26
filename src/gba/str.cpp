#include "gba/str.hpp"

int to_str_n(char * str, uint32_t n, int value) {
	char * str_start = str;
	if (n == 0) {
		return -1;
	}
	bool negative = value < 0;
	value = negative ? - value : value;
	
	int power = 1;
	while(power * 10 < value) {
		power *= 10;
	}
	
	char * str_end = & str[n];
	if (negative) {
		* str = '-';
	}
	
	while(str != str_end && power != 0) {
		int digit = value / power;
		value = value % power;
		power /= 10;
		* str = static_cast<char>('0' + digit);
		str ++;
	}
	if (str == str_end) {
		return -1;
	}
	* str = '\0';
	return reinterpret_cast<uint32_t>(str) - reinterpret_cast<uint32_t>(str_start);
}