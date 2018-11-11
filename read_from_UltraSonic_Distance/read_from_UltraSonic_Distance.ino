
// pour nous en souvenir nous allons utiliser des variables pour stocker les numéros des pins utilisées
int trigPin = 11;    // Trigger
int echoPin = 10;    // Echo

void setup() {
  Serial.begin (9600);
  // nous précisons que la pin 11 est une sortie (émission d'ultra-sons)
  pinMode(trigPin, OUTPUT); // trigPin est remplacé par sa valeur
  // nous précisons que la pin 10 est une entrée (réception de l'écho)
  pinMode(echoPin, INPUT);
}

void loop() {
  // On envoit un signal écrivant sur la pin de trigger (11)
  // En alternant les valeurs de courant LOW et HIGH et de cours délais
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // récuperer la distance en mesurant les pics en courant HIGH sur la pin d'écho
  long duration = pulseIn(echoPin, HIGH);
  // Convertir la durée en cm
  long cm = (duration/2) / 29.1;

  // imprimer le réulstat
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  // attendre un peu avant de recommencer l'opération
  delay(250);
}
