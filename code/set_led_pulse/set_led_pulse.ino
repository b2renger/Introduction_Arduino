
float t = 0; // une variable pour stocker le temps

void setup() {
   pinMode(3, OUTPUT); // utiliser la broche 3 en mode sortie
}

void loop() {
  t += 0.025; // on augmente la valeur du temps (on peut changer la valeur pour faire pulse + ou - vite)
  double l = ((sin(t) + 1) /2.0)*255; // on calcule une luminosité l doit être compris entre 0 et 255
  analogWrite(3, l); // on allume la led avec la luminosité calculée.
}
