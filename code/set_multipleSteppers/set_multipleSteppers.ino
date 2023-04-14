/*
 * Driver -> Arduino
 * 
 *  GND   -> GND
 *  VCC   -> 5V
 * 
 * Driver1
 *  IN1   -> D8
 *  IN2   -> D9
 *  IN3   -> D10
 *  IN4   -> D11
 * 
 * Driver2
 *  IN1   -> D2
 *  IN2   -> D3
 *  IN3   -> D4
 *  IN4   -> D5
 */

#include <AccelStepper.h>

// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::FULL4WIRE, 8, 10, 9, 11);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 2, 4, 3, 5);

void setup(){

  stepper1.setMaxSpeed(300.0);
  stepper1.setAcceleration(100.0);
  stepper1.moveTo(90);

  stepper2.setMaxSpeed(300.0);
  stepper2.setAcceleration(100.0);
  stepper2.moveTo(180);
}

void loop(){

  if (stepper1.distanceToGo() == 0) {
    int dst = random(-360, 360);
    stepper1.moveTo(dst);
  }
  if (stepper2.distanceToGo() == 0) {
    int dst = random(-360, 360);
    stepper2.moveTo(dst);
  }

  stepper1.run();
  stepper2.run();
}
