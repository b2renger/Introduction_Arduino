void setup() {

   pinMode(2, INPUT);
   Serial.begin(9600);
}

void loop() {
  int value = digitalRead(2);
  Serial.println(value);
}
