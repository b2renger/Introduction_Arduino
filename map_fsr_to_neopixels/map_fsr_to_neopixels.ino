#include <FastLED.h>
#define NUM_LEDS 5

CRGBArray<NUM_LEDS> leds;
float  inc = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);
}

void loop() {
  int fsrValue = analogRead(0);
  int hueValue = map(fsrValue, 0, 1023, 0, 200);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hueValue, 255, 255);
    FastLED.delay(1);
  }
}

