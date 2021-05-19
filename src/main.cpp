#include <Arduino.h>
#include <Wire.h>
bool received =false;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  pinMode(2,OUTPUT);

  // Wire.beginTransmission(8); // transmit to device #8
  // Wire.write("0,0,0");        // sends five bytes
  // Wire.endTransmission();
}

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("1,5000,800");        // start,scanning time,power
  Wire.endTransmission();
  delay(10000);

  for (uint8_t i = 0; i < 10; i++)
  {
    Wire.requestFrom(8, 24);    // request 6 bytes from slave device #8
    Serial.print("tag # ");Serial.print(i);Serial.print("= ");
    while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
    }Serial.println("");
  }



}