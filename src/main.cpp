#include <Arduino.h>
#include <Wire.h>
#define prominiReset 14
#define DEBUG
void setup() {
  Serial.begin(115200);
/****************proMini Reset Procedure******************/
  // pinMode(prominiReset,OUTPUT);
  // digitalWrite(prominiReset,LOW);
  // delay(100);
  // digitalWrite(prominiReset,HIGH);
  // delay(1000);
/*********************************************************/

/***********RFID Variables to be sent over I2C************/
  uint16_t readTime =10000;
  uint16_t  readPower=800;
  bool start =1;
  String command = String(start)+","+String(readTime)+","+String(readPower);
/*********************************************************/

/**************send command over I2C to slave*************/
  Wire.begin();
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(command.c_str());        // start,scanning time,power
  Wire.endTransmission();
/*********************************************************/

  delay(readTime+1000);//wait 1 second after the command is executed on the slave's side

/******request RFID data back from slave******************/
  for (uint8_t i = 0; i < 10; i++)
  {
    Wire.requestFrom(8, 24);    // request 6 bytes from slave device #8
    #ifdef DEBUG
    Serial.print("tag # ");Serial.print(i);Serial.print("= ");
    #endif
    while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
    }
    #ifdef DEBUG
    Serial.println("");
    #endif
    delay(10);
  }
}
/**********************************************************/
void loop() {
  //nothing here
}