#include <Arduino.h>
#include <Wire.h>
bool received =false;

void setup() {
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  delay(300);
  Wire.requestFrom(8, 4);
  byte lb1; byte hb1; byte lb2; byte hb2;
  while (Wire.available()){lb1=Wire.read();hb1=Wire.read();lb2=Wire.read();hb2=Wire.read();received=true;}
    if(received){
      char str1[3];sprintf(str1, "%d", word(hb1,lb1));
      char str2[3];sprintf(str2, "%d", word(hb2,lb2));
      Serial.print("str1 = ");Serial.println(str1);
      Serial.print("str2 = ");Serial.println(str2);
      received=false;
    }else {Serial.println("Nothing received");}
}