#include <Servo.h>

const int servoPin = 9;
const int potPin = A1;
const int restPoint = 60;
const int endPoint = 150;
const int startPoint = 0;
Servo myServo;


void setup() {
  Serial.begin(9600);
  
  myServo.attach(9);

  // check the extremes
  myServo.write(startPoint);
//  delay(1000);
//  myServo.write(endPoint);
//  delay(1000);
//  myServo.write(restPoint);
//  delay(1000);

}

void loop() {
  int potVal = analogRead(potPin);
  int interval = map(potVal,0,1023,10,2000);
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print(" interval: ");
  Serial.println(interval);
  myServo.write(endPoint);
  delay(interval);
  myServo.write(restPoint);
  delay(interval);
}
