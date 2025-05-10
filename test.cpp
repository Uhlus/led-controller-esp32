#include "test.h"
#include "helper-functions.h"

#include <iostream>
using namespace std;

/**
 * @brief Construct a new Animation_base::Animation_base object
 */
Animation_base::Animation_base()
{
}
/* -------------------------------------------------------------------------- */
/*                              Setters & Getters                             */
/* -------------------------------------------------------------------------- */
/* -------------------------------- frametime ------------------------------- */
/**
 * @brief sets the target frametime
 *
 * @param frametime
 * @return int current target frametime
 */
int Animation_base::set_target_frametime(int frametime)
{
  this->target_frametime = frametime;
  return this->get_target_frametime();
}
/**
 * @brief gets the target frametime
 *
 * @return int target_frametime
 */
int Animation_base::get_target_frametime()
{
  return this->target_frametime;
}
/**
 * @brief gets the current frametime
 *
 * @return int current_frametime
 */
int Animation_base::get_frametime_progress()
{
  int current = millis();
  int prev = this->get_start_time_prev_frame();

  return (current - prev);
}
int Animation_base::get_start_time_prev_frame()
{
  return this->previous_millis;
}
int Animation_base::set_start_time_current_frame()
{
  this->previous_millis = 100;
}
void Animation_base::set_frametime_prev_frame(int frametime)
{
  this->previous_frametime = frametime;
}
int Animation_base::get_frametime_prev_frame()
{
  return this->previous_frametime;
}

/* ------------------------------ pixel ranges ------------------------------ */
/**
 * @brief sets the range of pixels for the animation
 *
 * @param start
 * @param end
 */
void Animation_base::set_pixel_range(int start, int end)
{
  this->set_pixel_range_start(start);
  this->set_pixel_range_end(end);
}
/**
 * @brief sets the start of the range of pixels for the animation
 *
 * @param number start of range (inclusive)
 */
int Animation_base::set_pixel_range_start(int number)
{
  this->pixel_range_start = int_value_clamp(number, 0, this->get_strip_length());
  return this->get_pixel_range_start();
}
/**
 * @brief gets the start of the range of pixels for the animation
 *
 * @return int
 */
int Animation_base::get_pixel_range_start()
{
  return this->pixel_range_start;
}
/**
 * @brief sets the end of the range of pixels for the animation
 *
 * @param number end of range (inclusive)
 */
int Animation_base::set_pixel_range_end(int number)
{
  this->pixel_range_end = int_value_clamp(number, 0, this->get_strip_length());
  return this->get_pixel_range_end();
}
/**
 * @brief gets the end of the range of pixels for the animation
 *
 * @return int
 */
int Animation_base::get_pixel_range_end()
{
  return this->pixel_range_end;
}
/* ----------------------------- animation data ----------------------------- */
/**
 * @brief sets the number of steps after which the animation loops  (inclusive)
 *
 * @param number
 * @return int
 */
int Animation_base::set_loop_point(int number)
{
  this->loop_point = number;
  return this->get_loop_point();
}
/**
 * @brief gets the number of steps after which the animation loops
 */
int Animation_base::get_loop_point()
{
  return this->loop_point;
}
/**
 * @brief sets the number of LEDs in the strip
 *
 * @param number
 * @return int
 */
int Animation_base::set_strip_length(int number)
{

  this->strip_length = number;
}
/**
 * @brief gets the number of LEDs in the strip
 *
 * @return int
 */
int Animation_base::get_strip_length()
{
  return this->strip_length;
}
/**
 * @brief go to the next frame of animation
 *
 * @return int
 */
int Animation_base::step()
{
  this->current_step++;
  return this->get_step();
}
/**
 * @brief gets the current frame
 *
 */
int Animation_base::get_step()
{
  return this->current_step;
}
/**
 * @brief resets to the first frame of the animation
 *
 */
int Animation_base::reset_animation()
{
  this->current_step = 0;
  return this->get_step();
}
/**
 * @brief prepare the frame
 *
 * @return int
 */
int Animation_base::update_animation(bool render_now)
{
  int time_since_last_frame = this->get_frametime_progress();
  Serial.print(get_pixel_range_end());
  for (int current_pixel = 0; current_pixel < this->get_pixel_range_end() / 6; current_pixel++)
  {
    this->setPixelColor(current_pixel, Color(255, 0, 0));
    this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6, Color(255, 50, 0));
    this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 2, Color(225, 200, 0));
    this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 3, Color(0, 255, 38));
    this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 4, Color(0, 30, 255));
    this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 5, Color(115, 0, 130));
  }

  // skip rendering if under the frame limit
  // if (time_since_last_frame < this->get_target_frametime())
  // {
  //   return 1000000;
  // }
  // reset animation if after loop point

  // if (current_frame > this->get_loop_point())
  // {
  //   current_frame = this->reset_animation();
  // }
  // update frame

  // int start = this->get_pixel_range_start();
  // int end = this->get_pixel_range_end();
  // for (int current_pixel = std::min(start, end); current_pixel <= std::max(start, end); current_pixel++)
  // {
  // }
  // this->set_frametime_prev_frame(time_since_last_frame);
  // return this->get_frametime_prev_frame();
  return 0;
}