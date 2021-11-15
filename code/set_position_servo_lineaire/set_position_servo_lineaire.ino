// inclure la bibliothèque servo
#include <Servo.h>

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo;

void setup() {
  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo.attach(6);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 6
}

void loop() {
  myservo.write(90); // au milieu
  delay(1500); // attendre 1.5 sec
  myservo.write(0); // à l'opposé
  delay(1500);
  myservo.write(90);//au milieu
  delay(1500);
  myservo.write(180); // à l'autre opposé
  delay(1500);
}

