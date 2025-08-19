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
Animation_base NeoPixel;

/* --------------------------------- Button --------------------------------- */
Settings settings(6);
Button button_1(4);

/* -------------------------------- Animation ------------------------------- */

// Adafruit_NeoPixel anim(NUM_PIXELS, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

/* -------------------------------------------------------------------------- */
/*                              global variables                              */
/* -------------------------------------------------------------------------- */
long GLOBAL_time = 0;
bool reset = true;
bool button_state = true;
int px = 0;
/* -------------------------------------------------------------------------- */
/*                                    setup                                   */
/* -------------------------------------------------------------------------- */
void setup()
{
  Serial.begin(115200);

  pinMode(LED_STRIP_PIN, OUTPUT);
  digitalWrite(LED_STRIP_PIN, LOW);

  NeoPixel.setPin(LED_STRIP_PIN);
  NeoPixel.updateType(NEO_GRB + NEO_KHZ800);
  NeoPixel.updateLength(NUM_PIXELS);
  // NeoPixel.set_strip_length(NUM_PIXELS);
  NeoPixel.set_pixel_range_start(0);
  NeoPixel.set_pixel_range_end(NUM_PIXELS);

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
    // for (int current_pixel = 0; current_pixel < NUM_PIXELS; current_pixel++)
    // {
    // NeoPixel.setPixelColor(current_pixel, NeoPixel.Color(255, 255, 255));
    // }
    // px = random(NUM_PIXELS);
    // r = random(65000);
    // g = random(50);
    // b = random(255);
    // for (size_t i = 0; i < 10; i++)
    // {
    //   int real_pixel = (px + i) % NUM_PIXELS;
    //   NeoPixel.setPixelColor(real_pixel, NeoPixel.ColorHSV(r, 255, b));
    // }
    // NeoPixel.setPixelColor(5, NeoPixel.Color(255, 255, 255));
    // Serial.print("frametime = ");
    // Serial.print(anim.update_animation(false));
    // Serial.print("target = ");
    // Serial.print(anim.get_target_frametime());
    NeoPixel.update_animation(true);
    break;
  case 1:
    settings.set_mode(0);
    break;
  case 2:
    // NeoPixel.clear(); // send the updated pixel colors to the NeoPixel hardware.
    break;
  default:
    settings.set_mode(0);
    break;
  }

  NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.

  /* ------------------------------- Debug Stuff ------------------------------ */

  // Serial.print("mode = ");
  // Serial.print(settings.get_mode());
  // Serial.print("is held = ");
  // Serial.print(button_1.is_pressed());
  // Serial.print("pixel = ");
  // Serial.print(pixel);
  Serial.print("\r\n");
}
