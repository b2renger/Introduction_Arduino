
#include "CustomMIDI.h"

#define D5 0x4A
#define D6 0x56
#define A5 0x51
#define g5 0x50
#define G5 0x4F
#define F5 0x4D
#define C5 0x48
#define B4 0x47
#define a5 0x52

int BPM = 120;
int n =  60000 / BPM; 

void playOneNote(uint16_t note ,int time){
  sendMIDI(NOTE_ON, 1, note, 64); 
  delay(time);
  sendMIDI(NOTE_OFF, 1, note, 64); 
}


void setup() {
  Serial.begin(115200);
  sendMIDI(0xC0, 1, 4);
}

void loop() {
  playOneNote(D5,n/4);
  playOneNote(D5,n/4);
  playOneNote(D6,n/4);
  delay(n/4);
  playOneNote(A5,n/4);
  delay(n/2);
  playOneNote(g5,n/4);
  delay(n/4);
  playOneNote(G5,n/4);
  delay(n/4);
  playOneNote(F5,n/4);
  playOneNote(D5,n/4);
  playOneNote(F5,n/4);
  playOneNote(G5,n/4);
  playOneNote(C5,n/4);
  playOneNote(C5,n/4);
  playOneNote(D6,n/4);
  delay(n/4);
  playOneNote(A5,n/4);
  delay(n/2);
  playOneNote(g5,n/4);
  delay(n/2);
  playOneNote(G5,n/4);
  delay(n/4);
  playOneNote(F5,n/2);
  playOneNote(D5,n/4);
  playOneNote(F5,n/4);
  playOneNote(G5,n/4);
  playOneNote(B4,n/4);
  playOneNote(B4,n/4);
  playOneNote(D6,n/4);
  delay(n/4);
  playOneNote(A5,n/4);
  delay(n/2);
  playOneNote(g5,n/4);
  delay(n/4);
  playOneNote(G5,n/4);
  delay(n/4);
  playOneNote(F5,n/2);
  playOneNote(D5,n/4);
  playOneNote(F5,n/4);
  playOneNote(G5,n/4);
  delay(n*4);
}
