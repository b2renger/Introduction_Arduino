
#include "Ultrasonic.h" // importer la bibliothèque
Ultrasonic ultrasonic(2); // la broche "sig" du capteur est branchée sur "D2" de l'arduino

void setup() {
  Serial.begin(9600);
}

void loop() {
  long RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // mesurer la distance en cm
  Serial.println(RangeInCentimeters);//0~400cm
  delay(100); // attendre un peu entre deux mesures.
}
