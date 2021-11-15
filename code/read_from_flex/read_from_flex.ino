
void setup() {
  Serial.begin(9600);

}

void loop() {
  int value = analogRead(0);
  Serial.println(value);
}
