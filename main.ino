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
#define NUM_PIXELS 534
// #define NUM_PIXELS 300

Animation_base NeoPixel;

/* --------------------------------- Button --------------------------------- */
Settings settings(4);
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
  // Serial.print("| mode = ");
  // Serial.print(settings.get_mode());
  NeoPixel.update_animation(true, settings.get_mode());

  NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.
}
