#include <Arduino.h>
#include <SCServo.h>

#define RX1_PIN 18
#define TX1_PIN 17

SMS_STS smst;

int currentID = 1; // Factory default
int newID = 2;     // The unique ID you want to assign

void setup() {
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, RX1_PIN, TX1_PIN);
  smst.pSerial = &Serial1;
  delay(1000);

  Serial.println("Changing ID...");
  smst.unLockEprom(currentID);                 // Unlock EPROM memory
  smst.writeByte(currentID, SMS_STS_ID, newID); // Write the new ID into the servo
  smst.LockEprom(newID);                        // Re-lock EPROM
  Serial.println("Done! Label this physical servo with its new ID.");
}

void loop() {}
