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

/**
 * @brief omputes the linear interpolation between a and b, if the parameter t is inside (​0​, 1) (the linear extrapolation otherwise)
 *
 * @param a
 * @param b
 * @param t
 * @return float
 */
float lerp(float a, float b, float t)
{
	return (a * (1.0 - t)) + (b * t);
}