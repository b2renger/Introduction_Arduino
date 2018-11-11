// prévenir que nous allons avoir besoin de ces bibliothèques
#include <Wire.h>
#include "ITG3200.h"

ITG3200 gyro;
void setup(){
    Serial.begin(9600);
    // on active notre capteur
    gyro.init();
    gyro.zeroCalibrate(200,10);//sample 200 times to calibrate and it will take 200*10ms
}

void loop(){
    // on crée trois variables pour stocker les valeurs brutes de notre gyro.
    int16_t x,y,z;
    gyro.getXYZ(&x,&y,&z);//on lit les données de l'gyro et on les stockent dans nos variables.
    // on imprimme le résultat dans le moniteur série
    Serial.print("values of X , Y , Z: ");
    Serial.print(x);
    Serial.print(" , ");
    Serial.print(y);
    Serial.print(" , ");
    Serial.println(z);

    // on crée trois variables pour stocker les valeurs provenant du calcul effectué par notre bibliothèques
    float ax,ay,az;
    gyro.getAngularVelocity(&ax,&ay,&az);
    // on imprimme
    Serial.print("Angular Velocity of X , Y , Z: ");
    Serial.print(ax);
    Serial.print(" , ");
    Serial.print(ay);
    Serial.print(" , ");
    Serial.print(az);
    Serial.println(" degrees per second");
    Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    //delay(500); // if you want to monitor in the console
    delay(10); // if you want to trace
}

