void setup() {
  Serial.begin(9600); // ouvrir une connection via le cable série
}

void loop() {
  int photor1 = analogRead(A0); // lire les données sur A0 et les stocker dans une variable
  int photor2 = analogRead(A1);// lire les données sur A1 et les stocker dans une variable

  delay(1000); // attendre 1 seconde
 
  // construire une chaine de caractère par concatenation
  String json;
  json = "{\"photor1\":"; // on ajoute la première clé "photor1"
  json = json + photor1; // on ajoute la première valeur  
  json = json +";\"photor2\":"; // on ajoute la seconde clé "photor2"
  json = json +  photor2;// on ajoute la seconde valeur  
  json = json + "}";

  Serial.println(json); // on écrit notre fichier sur le port série
  // nous allons donc pouvoir récupérer ces valeurs avec processing
}
