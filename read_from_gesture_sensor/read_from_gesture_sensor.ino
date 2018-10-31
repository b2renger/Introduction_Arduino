

#include <Wire.h>
#include "paj7620.h"

uint8_t gesture = 0;

void setup() {
  Serial.begin(9600);
  gesture = paj7620Init();			// initialize Paj7620 registers
  Serial.println("Please input your gestures:\n");
}

void loop() {
  uint8_t data = 0, data1 = 0;
  gesture = paj7620ReadReg(0x43, 1, &data);

  switch (data){
    case GES_RIGHT_FLAG:
      Serial.println("Right");
      break;
    case GES_LEFT_FLAG:
      Serial.println("Left");
      break;
    case GES_UP_FLAG:
      Serial.println("Up");
      break;
    case GES_DOWN_FLAG:
      Serial.println("Down");
      break;
    case GES_FORWARD_FLAG:
      Serial.println("Forward");
      break;
    case GES_BACKWARD_FLAG:
      Serial.println("Backward");
      break;
    case GES_CLOCKWISE_FLAG:
      Serial.println("Clockwise");
      break;
    case GES_COUNT_CLOCKWISE_FLAG:
      Serial.println("anti-clockwise");
      break;
    default:
      paj7620ReadReg(0x44, 1, &data1);
      if (data1 == GES_WAVE_FLAG) {
        Serial.println("wave");
      }
      break;
  }

}

