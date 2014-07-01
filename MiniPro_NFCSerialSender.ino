#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h>
Adafruit_NFCShield_I2C nfc(2, 3); // Pin 2 is IRQ, Pin 3 is RESET (By default on shield) Pins can be changed here.

void setup(void) {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  nfc.begin();
  nfc.SAMConfig();
}

void loop(void) {

  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;
  
  if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)){
    for (int i = 0; i < uidLength; i++){
      printHex(uid[i]);
      
      if (i < uidLength - 1) 
        Serial.write(":");
    }  
  
   Serial.print('\n');
   
   digitalWrite(13, HIGH); delay(100); digitalWrite(13, LOW);
  }
}

void printHex(int num) {
      char tmp[16];
      char format[128];
 
      sprintf(format, "%%.%dX", 2);
      sprintf(tmp, format, num);
 
      Serial.print(tmp);
}
