
#include <Servo.h>
Servo myservo;

void setup() {
  pinMode(6, OUTPUT);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  myservo.write(90);
  delay(1500);
  myservo.write(0);
  delay(1500);
  myservo.write(90);
  delay(1500);
  myservo.write(180);
  delay(1500);


}

