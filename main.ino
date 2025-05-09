/**
 * @author Tobias Uhl
 * @brief Controllable W2812B Led Lights
 * @version 0.1
 * @date 2025-05-09
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
#include "test.h"

/* -------------------------------------------------------------------------- */
/*                                   defines                                  */
/* -------------------------------------------------------------------------- */

/* -------------------------------- LED Sting ------------------------------- */
#define LED_STRIP_PIN 2
#define NUM_PIXELS 300
Adafruit_NeoPixel NeoPixel(NUM_PIXELS, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

/* --------------------------------- Button --------------------------------- */
Settings settings(6);
Button button_1(4);

/* -------------------------------- Animation ------------------------------- */

Animation_base anim(0, 300, 0, 1, NUM_PIXELS);

/* -------------------------------------------------------------------------- */
/*                              global variables                              */
/* -------------------------------------------------------------------------- */
long GLOBAL_time = 0;
bool reset = true;
bool button_state = true;

/* -------------------------------------------------------------------------- */
/*                                    setup                                   */
/* -------------------------------------------------------------------------- */
void setup()
{
  Serial.begin(115200);

  pinMode(LED_STRIP_PIN, OUTPUT);
  digitalWrite(LED_STRIP_PIN, LOW);

  anim.update_animation();

  NeoPixel.begin();
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
    for (int current_pixel = 0; current_pixel < NUM_PIXELS; current_pixel++)
    {
      NeoPixel.setPixelColor(current_pixel, NeoPixel.Color(255, 255, 255));
    }
    break;
  case 1:
    for (int current_pixel = 0; current_pixel < NUM_PIXELS / 6; current_pixel++)
    {
      NeoPixel.setPixelColor(current_pixel, NeoPixel.Color(255, 0, 0));
      NeoPixel.setPixelColor(current_pixel + NUM_PIXELS / 6, NeoPixel.Color(255, 50, 0));
      NeoPixel.setPixelColor(current_pixel + NUM_PIXELS / 6 * 2, NeoPixel.Color(225, 200, 0));
      NeoPixel.setPixelColor(current_pixel + NUM_PIXELS / 6 * 3, NeoPixel.Color(0, 255, 38));
      NeoPixel.setPixelColor(current_pixel + NUM_PIXELS / 6 * 4, NeoPixel.Color(0, 30, 255));
      NeoPixel.setPixelColor(current_pixel + NUM_PIXELS / 6 * 5, NeoPixel.Color(115, 0, 130));
    }

    break;
  case 2:
    NeoPixel.clear(); // send the updated pixel colors to the NeoPixel hardware.
    break;
  case 3:
    NeoPixel.clear(); // send the updated pixel colors to the NeoPixel hardware.
    break;
  default:
    settings.set_mode(0);
    break;
  }

  NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.

  /* ------------------------------- Debug Stuff ------------------------------ */

  Serial.print("mode = ");
  Serial.print(settings.get_mode());
  // Serial.print("is held = ");
  // Serial.print(button_1.is_pressed());
  // Serial.print("pixel = ");
  // Serial.print(pixel);
  Serial.print("\r\n");
}
