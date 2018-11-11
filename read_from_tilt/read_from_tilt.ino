
void setup() {
  Serial.begin(9600); // ouvrir la connection série
  pinMode(7, INPUT); // préciser que la pin 7 va être utilisée comme une entrée
}

void loop() {
  int value = digitalRead(7); // lire la valeur sur la pin 7 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
