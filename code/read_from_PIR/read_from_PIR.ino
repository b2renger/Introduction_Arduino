
void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop() {
  int value = digitalRead(7);
  Serial.println(value);
}
