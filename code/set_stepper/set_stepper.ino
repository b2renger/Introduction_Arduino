/*
 * Driver -> Arduino
 * 
 *  IN1   -> D8
 *  IN2   -> D9
 *  IN3   -> D10
 *  IN4   -> D11
 * 
 *  GND   -> GND
 *  VCC   -> 5V
 */


#include <Stepper.h>
const float stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution of your stepper
const float degPerStep = 360 / stepsPerRevolution ; // for a stepper CX28BYJ48 step per revolution should be 64 eg 1 step == 5.625 deg
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // initialize the stepper library on pins 8 through 11 from in1 to in4

int stepCount = 0;


void setup() {
 Serial.begin(9600);
 Serial.println(degPerStep);
}

void loop() {

  //For better control, keep the speed high and only go a few steps with each call to step().
  myStepper.setSpeed(200 );
  
  Serial.println("going forward");
  for (float i = 0 ; i < 90 ; i += degPerStep){
    myStepper.step(1);
  }

  Serial.println("going backwards");
  for (float i = 0 ; i < 90 ; i += degPerStep){
    myStepper.step(-1);
  }

}
