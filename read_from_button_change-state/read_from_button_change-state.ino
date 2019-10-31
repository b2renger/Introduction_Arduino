
bool b1pval = false; // valeur prédente du bouton
bool b1val = false; // valeur actuelle du bouton


void setup() {
  Serial.begin(9600); // ouvrir la connection série
  pinMode(2, INPUT); // préciser que la pin 2 va être utilisée comme une entrée
}

void loop() {
  // appeler la fonction sur la pin 2
  // avec comme valeur précédente du bouton la variable b1pval
  // et comme valeur courante du bouton la variable b1val
  button_change(2, &b1pval, &b1val); 
  Serial.println(b1val);
}

void button_change(int pin, bool *pval, bool *val) {
  if (digitalRead(pin) == 1) {
    if (*val == *pval) {
      *val = !*val;
    }
  }
  else {
    *pval = *val;
  }
}
