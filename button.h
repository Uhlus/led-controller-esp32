#ifndef BUTTON
#define BUTTON
#include <Arduino.h>
class Button
{
private:
  byte pin;
  byte state;
  byte last_reading;
  unsigned long last_debounce_time = 0;
  unsigned long debounce_delay = 500;
  bool reset = true;

public:
  Button(byte pin);

  void init();

  void update();

  byte getState();

  bool is_pressed();

  bool is_short_press();
};
#endif