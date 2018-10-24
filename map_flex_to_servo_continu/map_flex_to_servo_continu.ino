

#include <Servo.h>
Servo myservo;


void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  myservo.attach(6);


}

void loop() {

  int soundLvl = analogRead(0);
  Serial.println(soundLvl);
  int servoRotation = map(soundLvl, 200, 700, 0, 180);
  myservo.write(servoRotation);



}
