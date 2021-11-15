#include "SPI.h"
#include "MFRC522.h"
/***
 * VCC -> 5V
 * RST -> D9
 * GND -> GND
 * MISO -> D12
 * MOSI -> D11
 * SCK -> D13
 * SDA or NSS -> D10
 */


#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("I am waiting for card...");
}

void loop() {
 
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;
  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));
  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
      (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
      String(rfid.uid.uidByte[i], HEX) +
      (i != 3 ? ":" : "");
  }

  strID.toUpperCase();
  Serial.println("");
  Serial.print("Tap card key: ");
  Serial.println(strID);
  Serial.println("");
  delay(1000);

  if (strID.indexOf("C0:8F:C8:49") >= 0) {  //put your own tap card key;
    
    Serial.println("blue badge");
    Serial.println("");
  }
  else if (strID.indexOf("8E:5B:CD:15") >= 0) {  //put your own tap card key;
    //Serial.println("");
    Serial.println("card");
    Serial.println("");
  }
  else {
    Serial.println("");
    Serial.println("unknown");
    Serial.println("");
  }
}
