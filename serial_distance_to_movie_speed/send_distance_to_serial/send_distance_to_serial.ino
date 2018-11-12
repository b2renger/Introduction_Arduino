
void setup() {
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(A0);

  String json;
  json = "{\"distance\":";
  json = json + value;
  json = json + "}";

  Serial.println(json);
}
