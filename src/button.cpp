#include "button.h"

/**
 * @brief Construct a new Button object
 *
 * @param pin
 */
Button::Button(byte pin)
{
  this->pin = pin;
  last_reading = LOW;
  init();
}
void Button::init()
{
  pinMode(pin, INPUT_PULLUP);
  update();
}
/**
 * @brief Update Status of Button
 *
 */
void Button::update()
{
  byte new_reading = is_pressed();
  if (new_reading != last_reading)
  {
    last_debounce_time = millis();
  }

  if (millis() - last_debounce_time > debounce_delay)
  {
    state = new_reading;
  }

  last_reading = new_reading;
}
/**
 * @brief Get Status of Button
 *
 * @return byte
 */
byte Button::getState()
{
  update();
  return state;
}
/**
 * @brief Test if button is held
 *
 * @return true
 * @return false
 */
bool Button::is_pressed()
{

  return !digitalRead(pin);
}
/**
 * @brief Test if button is pressed for a short time
 *
 * @return true
 * @return false
 */
bool Button::is_short_press()
{
  static bool reset = true;
  if (this->is_pressed())
  {
    if (reset)
    {
      reset = false;
      return true;
    }
  }
  else
  {
    reset = true;
  }
  return false;
}