#include <Servo.h>

const int servoPin = 9;
const int potPin = A1;
const int restPoint = 60;
const int endPoint = 150;
const int startPoint = 0;
const int minInterval = 300;
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
  int interval = map(potVal,10,1023,minInterval,3000);
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print(" interval: ");
  Serial.println(interval);
  if(potVal < 10){
    myServo.write(restPoint);
    }
  else {
  myServo.write(endPoint);
  delay(minInterval);
  myServo.write(restPoint);
  delay(interval);
  }
}
