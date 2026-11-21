#include "helper-functions.h"
#include <stdint.h>
#include <iostream>
using namespace std;
/**
 * @brief returns value clamped between min and max
 *
 * @param value
 * @param min
 * @param max
 * @return int
 */
int int_value_clamp(int value, int min, int max)
{
	return std::max(min, std::min(value, max));
}

/**
 * splitColor() - Receive a uint32_t value, and spread into bits.
 */
uint8_t splitColor(uint32_t c, char value)
{
	switch (value)
	{
	case 'r':
		return (uint8_t)(c >> 16);
	case 'g':
		return (uint8_t)(c >> 8);
	case 'b':
		return (uint8_t)(c >> 0);
	default:
		return 0;
	}
}