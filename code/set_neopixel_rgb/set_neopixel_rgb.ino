// inclure la bibliothèque fast-led
#include <FastLED.h>
#define NUM_LEDS 5 // définir le nombre de leds

CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0; // un variable que l'on va utiliser pour créer une animation.

void setup() {
  // on initialise notre strip de led sur la pin 9
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
}

void loop() {

  inc +=  0.05; // on augmente la valeur de inc
  // on calcul en fonction de inc un valeur qui va osciller entre 0 et 244.
  int green = (sin(inc) + 1)*122; // cette valeur est stocké dans une variable nommée "green"

  // Pour i allant de 0 à 5, on va éxecuter le code entre accolades,
  // à chaque fois on augmente la valeur de i de 1
  for (int i = 0; i < NUM_LEDS; i++) {
    // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
    leds[i] = CRGB(255-green, green, 0);
  }
  FastLED.show(); // on actualise le ruban de led
}

