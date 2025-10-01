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
  return this->previous_millis = millis();
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
/**2560x1440
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
int Animation_base::update_animation(bool render_now, int animation_id)
{
  int time_since_last_frame = this->get_frametime_progress();

  switch (animation_id)
  {
  case 0:
    this->set_target_frametime(1000);
    this->set_loop_point(1);
    for (int current_pixel = 0; current_pixel < this->get_pixel_range_end() / 6; current_pixel++)
    {
      this->setPixelColor(current_pixel, Color(255, 0, 0));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6, Color(255, 50, 0));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 2, Color(225, 200, 0));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 3, Color(0, 255, 38));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 4, Color(0, 30, 255));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 5, Color(115, 0, 130));
    }
    break;
  case 1:
    this->set_target_frametime(250);
    this->set_loop_point(6);
    for (int current_pixel = 0; current_pixel < this->get_pixel_range_end(); current_pixel++)
    {
      int offset = this->get_step();
      int current_pixel_modulo = (current_pixel + offset) % 6;

      if (current_pixel_modulo == 0)
      {
        this->setPixelColor(current_pixel, Color(255, 0, 0));
      }
      if (current_pixel_modulo == 1)
      {
        this->setPixelColor(current_pixel, Color(255, 50, 0));
      }
      if (current_pixel_modulo == 2)
      {
        this->setPixelColor(current_pixel, Color(225, 200, 0));
      }
      if (current_pixel_modulo == 3)
      {
        this->setPixelColor(current_pixel, Color(0, 255, 38));
      }
      if (current_pixel_modulo == 4)
      {
        this->setPixelColor(current_pixel, Color(0, 30, 255));
      }
      if (current_pixel_modulo == 5)
      {
        this->setPixelColor(current_pixel, Color(115, 0, 130));
      }
    }
    break;
  case 2:
    this->set_target_frametime(30);
    this->set_loop_point(this->get_pixel_range_end());

    this->setPixelColor(this->get_step(), Color(255, 255, 255));
    this->setPixelColor((this->get_step() - 1), Color(0, 0, 0));

    break;
  case 3:
    this->set_target_frametime(100);
    this->set_loop_point(this->get_pixel_range_end() / 6);
    for (int current_pixel = 0; current_pixel < this->get_pixel_range_end() / 6; current_pixel++)
    {
      float color_offset = ((((float)this->get_step() / (float)this->get_loop_point()) + ((float)current_pixel / ((float)this->get_pixel_range_end() / (float)6))) / 2);

      // Serial.print((int)lerp(100, 255, color_offset));
      this->setPixelColor(current_pixel, Color(
                                             (int)lerp(0, 255, color_offset),
                                             (int)lerp(0, 0, color_offset),
                                             (int)lerp(0, 0, color_offset)

                                                 ));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6, Color(

                                                                               (int)lerp(191, 255, color_offset),
                                                                               (int)lerp(38, 50, color_offset),
                                                                               (int)lerp(0, 0, color_offset)

                                                                                   ));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 2, Color(

                                                                                   (int)lerp(191, 225, color_offset),
                                                                                   (int)lerp(150, 200, color_offset),
                                                                                   (int)lerp(0, 0, color_offset)

                                                                                       ));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 3, Color(

                                                                                   (int)lerp(0, 0, color_offset),
                                                                                   (int)lerp(191, 255, color_offset),
                                                                                   (int)lerp(29, 38, color_offset)

                                                                                       ));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 4, Color(

                                                                                   (int)lerp(0, 0, color_offset),
                                                                                   (int)lerp(23, 30, color_offset),
                                                                                   (int)lerp(191, 255, color_offset)

                                                                                       ));
      this->setPixelColor(current_pixel + this->get_pixel_range_end() / 6 * 5, Color(

                                                                                   (int)lerp(86, 115, color_offset),
                                                                                   (int)lerp(0, 0, color_offset),
                                                                                   (int)lerp(98, 130, color_offset)

                                                                                       ));
    }
    break;
  default:
    break;
  }
  if (time_since_last_frame >= this->get_target_frametime())
  {
    this->set_start_time_current_frame();
    Serial.print("ft ");
    Serial.print(time_since_last_frame);
    Serial.print("ms");
    Serial.print(" | f ");
    Serial.print(this->get_step() + 1);
    Serial.print("| mxf ");
    Serial.print(this->get_loop_point());
    if (this->step() >= this->get_loop_point())
    {
      Serial.print(" | l 1 ");
      // Serial.print("\r\n");
      this->reset_animation();
    }
    else
    {
      Serial.print(" | l 0 ");
    }
    Serial.print("\n\r");
  }

  return 0;
}