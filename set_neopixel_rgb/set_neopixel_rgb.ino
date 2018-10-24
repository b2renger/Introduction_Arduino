#include <FastLED.h>
#define NUM_LEDS 5

CRGBArray<NUM_LEDS> leds;
float  inc = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
}

void loop() {

  inc +=  0.05;
  int green = (sin(inc) + 1)*122;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(255-green, green, 0);
    FastLED.delay(1);
  }
}

