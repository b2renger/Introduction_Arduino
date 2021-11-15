
#include <Arduino.h>
#include "ServoEasing.hpp"



ServoEasing Servo1;
void setup() {

  pinMode(6, OUTPUT);
  // put your setup code here, to run once:
  Servo1.attach(6, 0); // on pin D6 , start position is 0
  Servo1.setEasingType(EASE_CUBIC_IN_OUT);
  Servo1.easeTo(180, 20); // move to 180 at 20 per second
  
  //delay(1000);
  


  //delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Servo1.setSpeed(80);
  Servo1.setEasingType(EASE_BOUNCE_OUT);
  Servo1.easeTo(0);

  Servo1.setSpeed(20);
   Servo1.setEasingType(EASE_ELASTIC_IN_OUT);
  Servo1.easeTo(180);
}
