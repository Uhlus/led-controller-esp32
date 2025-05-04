#include "settings.h"

/**
 * @brief Construct a new Settings object
 *
 */
Settings::Settings(int max_modes)
{
	this->current_mode = 0;
	this->max_modes = max_modes;
}

/**
 * @brief Set the mode of the animation (clamped to the min and max mode number)
 *
 * @param mode
 * @return int
 */
int Settings::set_mode(int mode)
{
	mode = int_clamp(mode, 0, this->max_modes);

	this->current_mode = mode;
	return get_mode();
}
/**
 * @brief Get the mode
 *
 * @return int
 */
int Settings::get_mode()
{
	return this->current_mode;
}
/**
 * @brief Incease Mode by one
 *
 * @return int
 */
int Settings::increase_mode()
{
	int mode = get_mode() + 1;
	mode = (mode > this->max_modes) ? 0 : mode;
	return set_mode(mode);
}
