#include <FastLED.h>
#define NUM_LEDS 5

CRGBArray<NUM_LEDS> leds;
float  inc = 0;

void setup() {

  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
}

void loop() {

  inc +=  0.05;
  int saturation = (sin(inc) + 1)*122;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(255 - i *50, saturation, 255);
    FastLED.show();
  }
}


