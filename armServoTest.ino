#include <Arduino.h>
#include <SCServo.h>

// Define custom ESP32-S3 UART1 Pins
#define RX1_PIN 18
#define TX1_PIN 17

// Create an instance for ST-series smart servos
SMS_STS smst;

void setup() {
  // 1. Initialize native USB serial monitor for debugging
  Serial.begin(115200);
  while(!Serial && millis() < 3000); // Wait for monitor console to snap open

  // 2. Initialize ESP32-S3 UART1 at 1Mbps linked to the Waveshare Adapter 
  Serial1.begin(1000000, SERIAL_8N1, RX1_PIN, TX1_PIN);
  
  // 3. Bind the SCServo controller class to use UART1 (Serial1)
  smst.pSerial = &Serial1;

  Serial.println("ESP32-S3 UART1 & STS3215 Bus Initialized.");
}

void loop() {
  Serial.println("Moving Servo ID 1 and 3 to 4095 and ID 2 to 0...");
  // WritePosEx parameters: (Servo ID, Target Position 0-4095, Speed, Acceleration)
  smst.WritePosEx(1, 4095, 0, 50); 
  smst.WritePosEx(2, 0, 0, 50);
  smst.WritePosEx(3, 4095, 0, 50); 
  delay(5000);

  Serial.println("Moving Servo ID 1 and 3 to 0 and ID 2 to 4095...");
  smst.WritePosEx(1, 0, 0, 50); 
  smst.WritePosEx(2, 4045, 0, 50);
  smst.WritePosEx(3, 0, 0, 50); 
  delay(5000);
}
