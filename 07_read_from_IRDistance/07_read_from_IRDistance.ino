float smoothedValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(0);

  smoothedValue += (value-smoothedValue)*0.1;
  Serial.println(smoothedValue);
}
