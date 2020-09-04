#ifndef sendMIDI_h_
#define sendMIDI_h_

const uint8_t NOTE_OFF = 0x80;
const uint8_t NOTE_ON = 0x90;
const uint8_t KEY_PRESSURE = 0xA0;
const uint8_t CC = 0xB0;
const uint8_t PROGRAM_CHANGE = 0xC0;
const uint8_t CHANNEL_PRESSURE = 0xD0;
const uint8_t PITCH_BEND = 0xE0;

const unsigned long headerResendTime = 1000;   // send a new header every second

void sendMIDIHeader(uint8_t header) {
  static unsigned long lastHeaderTime = millis();
  static uint8_t runningHeader = 0;

  if (header != runningHeader                  // If the new header is different from the previous
    || (millis() - lastHeaderTime)
    > headerResendTime) {                      // Or if the last header was sent more than 1 s ago
    Serial.write(header);                      // Send the status byte over Serial
    runningHeader = header;                    // Remember the new header
    lastHeaderTime = millis();
  }
}

void sendMIDI(uint8_t messageType, uint8_t channel, uint8_t data1, uint8_t data2) {
  if (messageType == NOTE_OFF) {               // Replace note off messages
    messageType = NOTE_ON;                     // with a note on message
    data2 = 0;                                 // with a velocity of zero.
  }
  channel--;                                   // Decrement the channel, because MIDI channel 1
                                               // corresponds to binary channel 0
  uint8_t statusByte = messageType | channel;  // Combine the messageType (high nibble)
                                               // with the channel (low nibble)
                                               // Both the message type and the channel
                                               // should be 4 bits wide
  statusByte |= 0b10000000;                    // Set the most significant bit of the status byte
  data1      &= 0b01111111;                    // Clear the most significant bit of the data bytes
  data2      &= 0b01111111;

  sendMIDIHeader(statusByte);                  // Send the header over Serial, using running status
  Serial.write(data1);                         // Send the data bytes over Serial
  Serial.write(data2);
}
 void sendMIDI(uint8_t messageType, uint8_t channel, uint8_t data) {
  channel--;                                   // Decrement the channel, because MIDI channel 1
                                               // corresponds to binary channel 0
  uint8_t statusByte = messageType | channel;  // Combine the messageType (high nibble)
                                               // with the channel (low nibble)
                                               // Both the message type and the channel
                                               // should be 4 bits wide
  statusByte |= 0b10000000;                    // Set the most significant bit of the status byte
  data       &= 0b01111111;                    // Clear the most significant bit of the data byte

  sendMIDIHeader(statusByte);                  // Send the header over Serial, using running status
  Serial.write(data);                          // Send the data byte over Serial
}

#endif