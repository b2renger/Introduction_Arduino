/*
 * This programm communicates with Touch Designer
 * we send a string via serial using a csv formatting
 * and getting it back in TD with a Dat node.
 * 
 * we use a potentiometer  to change the radius of a circle
 * 
 */

void setup() {
 
  Serial.begin(9600);
}

void loop() {
  int potVal = analogRead(0);
  // we use a csv like formatting for communication with TD
  String s = String(analogRead(0)) ;
  s = s + ',';
  s = s + random(1000); // you can replace this by any other value
  Serial.println(s);
}
