

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(0);
  Serial.println(val);
}
