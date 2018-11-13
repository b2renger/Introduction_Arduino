import processing.serial.*;

Serial myPort;  // Create object from Serial class

void setup() {
  size(600, 600); 
  colorMode(HSB,255,255,255);
  println(Serial.list());
  String portName = Serial.list()[3]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  int pressed = 0;
  if (mousePressed == true) {    
    pressed = 1;         
  } else {                         
    pressed = 0; 
  }  

  int x =int( map(mouseX, 0, width, 0, 255));
  int y =int( map(mouseY, 0, height, 0, 255));
  println(pressed+","+x+","+y+";");
  background(x, y, pressed*255);
  myPort.write(pressed+","+x+","+y+";");
}
