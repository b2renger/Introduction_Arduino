
#include <Servo.h>
Servo myservo;
int deltaT = 1500;


void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object

}

void loop() {

  myservo.write(90);
  delay(deltaT);
  myservo.write(180);
  delay(deltaT);
  myservo.write(0);
  delay(deltaT);


}

