
import processing.serial.*;
Serial myPort;  

int photor1 =0;
int photor2 =0;


void setup() {
  size(800, 500);
  // initialisation de la communication via usb depuis arduino
  // ATTENTION à bien utiliser le port adapté
  printArray(Serial.list());
  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {    
  background(0);
  fill(255);

  ellipse(width*0.25, height*0.5, photor1, photor1);
  ellipse(width*0.75, height*0.5, photor2, photor2);
}  

void serialEvent (Serial myPort) {
  try {
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n');
      if (inBuffer != null) {
        if (inBuffer.substring(0, 1).equals("{")) {
          JSONObject json = parseJSONObject(inBuffer);
          if (json == null) {
            //println("JSONObject could not be parsed");
          } else {
            // récupérer les données stockée dans le format json transmis via usb
            photor1    = json.getInt("photor1"); // on récupère la valeur correspondant à la clé "photor1"
            photor2    = json.getInt("photor2");

            JSONArray js  = loadJSONArray("data.json"); // on charge le fichier data.json - dans lequel on va ajouter une entrée

            JSONObject njs = new JSONObject(); // on crée un nouvel objet json
            // on ajoute un timestamp avec date et heure
            njs.setString("timestamp", year()+"-"+month()+"-"+day()+"-"+hour()+"-"+minute()+"-"+second());
            njs.setInt("luminosity1", photor1); // on ajoute la première valeur
            njs.setInt("luminosity2", photor2); // on ajoute la seconde valeur
           
            js.append(njs); // on ajoute ce nouvel objet à l'objet chargé précédement
            saveJSONArray(js, "data/data.json"); // on sauvegarde le tout en écrasant le fichier précédent.
          }
        } else {
        }
      }
    }
  } 
  catch (Exception e) {
  }
}
