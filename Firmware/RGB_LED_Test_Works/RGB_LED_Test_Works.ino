#include <FastLED.h> // http://librarymanager/All#FastLED

#define LED_PIN     4 //Any GPIO should work
#define COLOR_ORDER GRB
#define CHIPSET     WS2812
#define NUM_LEDS    1

#define BRIGHTNESS  25

CRGB leds[NUM_LEDS];

void setup()
{
  Serial.begin(115200);
  delay(250);
  Serial.println("Start");
  //delay(30); // Sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  //class WS2811Controller800Khz : public ClocklessController<DATA_PIN, NS(350), NS(450), NS(300), RGB_ORDER> {};


  FastLED.setBrightness( BRIGHTNESS );
}

void loop()
{
  Serial.println("Running");
  
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(200);

  leds[0] = CRGB::Green;
  FastLED.show();
  delay(200);

  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(200);

  leds[0] = CRGB::Black;
  FastLED.show();
  delay(100);

  leds[0] = CRGB::White;
  FastLED.show();
  delay(2000);

  leds[0] = CRGB::Black;
  FastLED.show();
  delay(100);
}
