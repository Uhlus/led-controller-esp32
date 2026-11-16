#include "helper-functions.h"
class Settings
{
private:
	int current_mode;
	int max_modes;

public:
	/**
	 * @brief Construct a new Settings object
	 *
	 */
	Settings(int max_modes);

	/**
	 * @brief Set the mode of the animation (clamped to the min and max mode number)
	 *
	 * @param mode
	 * @return int
	 */
	int set_mode(int mode);
	/**
	 * @brief Get the mode
	 *
	 * @return int
	 */
	int get_mode();
	/**
	 * @brief Incease Mode by one
	 *
	 * @return int
	 */
	int increase_mode();
};