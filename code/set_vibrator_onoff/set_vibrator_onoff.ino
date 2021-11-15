
void setup() {
  pinMode(3, OUTPUT); // utiliser la broche 3 en mode sortie
}

void loop() {
  digitalWrite(3, HIGH); // envoyer un courant 'fort' sur la broche 3
  delay(500); // attendre 500 millisecondes
  digitalWrite(3, LOW); // envoyer un courant 'faible' sur la broche 3
  delay(500); // attendre 500 millisecondes
} 
