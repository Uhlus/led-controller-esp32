/**
 * @author Tobias Uhl
 * @brief Controllable W2812B Led Lights
 * @version 0.1
 * @date 2025-08-22
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  includes                                  */
/* -------------------------------------------------------------------------- */
#include <Arduino.h>
#include <iostream>
#include <Adafruit_NeoPixel.h>
#include <algorithm>
#include "settings.h"
#include "button.h"
#include "animations.h"

/* -------------------------------------------------------------------------- */
/*                                   defines                                  */
/* -------------------------------------------------------------------------- */

/* -------------------------------- LED Sting ------------------------------- */
#define LED_STRIP_PIN 2

// #define NUM_PIXELS 50 // Tree
// #define NUM_PIXELS 300 // Desk
#define NUM_PIXELS 534 // Kallax

// Animation_base NeoPixel(NUM_PIXELS, LED_STRIP_PIN, NEO_BGR + NEO_KHZ800); // Tree

Animation_base NeoPixel(NUM_PIXELS, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800); // Kallax / Desk

/* --------------------------------- Button --------------------------------- */

Settings settings(11);
Button button_1(4);

/* -------------------------------- Animation ------------------------------- */

Adafruit_NeoPixel anim(NUM_PIXELS, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

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
  Serial.println("ESP32 started");

  NeoPixel.set_pixel_range_start(0);
  NeoPixel.set_pixel_range_end(NUM_PIXELS);

  NeoPixel.begin();
  NeoPixel.clear();
  NeoPixel.show();

  Serial.println("LED initialization completed");

  // settings.set_mode(8);
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
  // Serial.print("| mode = ");
  // Serial.print(settings.get_mode());
  NeoPixel.update_animation(true, settings.get_mode());

  NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.
}
