/*
  Controlling the SparkFun right-angle RGB CBI (circuit board indicator)
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 29th, 2023
  License: MIT. Please see LICENSE.md for more information.

  This example shows how to control four RGBs chained together.

  SparkFun RGB Addressable CBI LED 5mm - Right Angle (COM-23649) https://www.sparkfun.com/products/23649

  Hardware Connections:
  VCC on the LED can be 3.3V or 5V
  GND on the LED should connect to GND on the microcontroller.
  DI on the LED should connect to an output of your microcontroller. For 
  this example, we use an ESP32 which is capable of driving WS2812/APA106 type LEDs from
  nearly any pin. Your microcontroller may have restrictions.
*/

#include <FastLED.h> // http://librarymanager/All#FastLED

#define LED_PIN     16 //Any GPIO on the ESP32 should work
#define COLOR_ORDER RGB
#define CHIPSET     WS2812
#define NUM_LEDS    4

int brightness = 0; //0 to 255. 25 is plenty

CRGB leds[NUM_LEDS];

void setup()
{
  Serial.begin(115200);
  delay(250);
  Serial.println("Start");

  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  FastLED.setBrightness(brightness);

  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Purple;
  FastLED.show();
}

void loop()
{
  FastLED.setBrightness(25);
  FastLED.show();
  Serial.println("25");
  delay(2000);
  
  FastLED.setBrightness(100);
  FastLED.show();
  Serial.println("100");
  delay(2000);
  
  FastLED.setBrightness(255);
  FastLED.show();
  Serial.println("255");
  delay(2000);
}
