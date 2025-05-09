#include "helper-functions.h"
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