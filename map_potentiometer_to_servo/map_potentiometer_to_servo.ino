

#include <Servo.h>
Servo myservo;


void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  myservo.attach(6);


}

void loop() {

  int potValue = analogRead(0);
  Serial.println(potValue);
  int servoPos = map(potValue, 0, 1023, 0, 180);
  myservo.write(servoPos);



}
