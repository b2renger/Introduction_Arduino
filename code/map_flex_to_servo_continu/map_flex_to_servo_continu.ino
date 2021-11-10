// inclure la bibliothèque pour controller des servomoteurs
#include <Servo.h>
Servo myservo; // créer un objet qui nous permettra de manipuler notre servomoteur.


void setup() {
  Serial.begin(9600); // ouvrir une connexion série pour pouvoir imprimmer des valeurs dans le moniteur série
  pinMode(6, OUTPUT); // on précise que l'on utilise la pin 6 comme une sortie
  myservo.attach(6); // on précise que notre servo est connecté sur la pin 6


}

void loop() {
  // on lit la valeur provenant de notre capteur de flexion qui est branché sur la pin A0
  int flexion = analogRead(0);
  Serial.println(flexion);// on imprime la valeur dans le moniteur série

  // on va calculer une vitesse de rotation pour notre servomoteur qui dépendera de la valeur mesurée par
  // notre capteur de flexion. En observant les valeurs imprimmées dans le moniteur série, on se rend compte que
  // les valeurs de notre capteur sont a peu près comprises entre 200 et 700.
  int servoRotation = map(flexion, 200, 700, 0, 180); // on mappe donc notre valeur de flexion qui est comprise entre 200 et 700 vers de valeurs comprises entre 0 et 180
  myservo.write(servoRotation); // on envoit ces nouvelles valeurs vers notre servomoteur pour le faire tourner.
}
