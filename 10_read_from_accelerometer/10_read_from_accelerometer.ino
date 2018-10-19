
#include <Wire.h>
#include <ADXL345.h>


ADXL345 accel;

void setup() {
  Serial.begin(9600);
  accel.powerOn();
}

void loop() {


  int x, y, z;
  accel.readXYZ(&x, &y, &z); //read the accelerometer raw values
  Serial.print("values of X , Y , Z: ");
  Serial.print(x);
  Serial.print(" , ");
  Serial.print(y);
  Serial.print(" , ");
  Serial.println(z);

  double xyz[3]; // create an array to store values from .getAcceleration()
  accel.getAcceleration(xyz);
  Serial.print("X=");
  Serial.print(xyz[0]);
  Serial.print(" g , ");
  Serial.print("Y=");
  Serial.print(xyz[1]);
  Serial.print(" g , ");
  Serial.print("Z=");
  Serial.print(xyz[2]);
  Serial.println(" g");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  //delay(500); // if you want to look in the monitor
  delay(10); // if you want to look in the tracer
}
