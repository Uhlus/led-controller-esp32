/**
 * @file Arduino Led Buttons.ino
 * @author Tobias Uhl
 * @brief Controllable W2812B Led Lights
 * @version 0.1
 * @date 2023-11-24
 *
 * @copyright Copyright (c) 2023
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  includes                                  */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <Adafruit_NeoPixel.h>
#include <algorithm>
#include "settings.h"
#include "button.h"
#include "test2.h"

/* -------------------------------------------------------------------------- */
/*                                   defines                                  */
/* -------------------------------------------------------------------------- */

/* -------------------------------- LED Sting ------------------------------- */
#define led_strip 2
Adafruit_NeoPixel strip(300, led_strip, NEO_GRB + NEO_KHZ800);

/* --------------------------------- Button --------------------------------- */
Settings settings(2);
Button button_1(4);

/* -------------------------------------------------------------------------- */
/*                              global variables                              */
/* -------------------------------------------------------------------------- */
long GLOBAL_time = 0;
bool reset = true;
bool button_state = true;
int out = 0;
/* -------------------------------------------------------------------------- */
/*                                    setup                                   */
/* -------------------------------------------------------------------------- */
void setup()
{
  Serial.begin(115200);

  pinMode(led_strip, OUTPUT);
  digitalWrite(led_strip, LOW);
}

void loop()
{
  /**
   * @brief Increase mode if Button is pressed
   *
   */
  if (button_1.is_short_press())
  {
    settings.increase_mode();
  }
  /**
   * @brief Run current mode
   *
   */
  switch (settings.get_mode())
  {
  case 0:
    out = 0;
    break;
  case 1:
    out = 1;
    break;
  default:
    out = 0;
    break;
  }
  /* ------------------------------- Debug Stuff ------------------------------ */

  Serial.print("out = ");
  Serial.print(out);
  Serial.print("millis = ");
  Serial.print(millis());
  Serial.print("is held = ");
  Serial.print(button_1.is_pressed());
  Serial.print("\r\n");
}
