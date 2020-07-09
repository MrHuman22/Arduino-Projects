#include <Arduino.h>
const int ledPin = 13;
int loopCount = 1;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(loopCount);
  digitalWrite(ledPin,HIGH);
  delay(500);
  digitalWrite(ledPin,LOW);
  delay(500);
  loopCount = loopCount + 1;
}