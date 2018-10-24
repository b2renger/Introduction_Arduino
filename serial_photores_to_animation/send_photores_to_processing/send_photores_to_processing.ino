
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);


  String json;

  //json = "{\"controle\":{\"pot1\":";
  json = "{\"photores\":";
  json = json + value;
  json = json + "}";

  Serial.println(json);
}
