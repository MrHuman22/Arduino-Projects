/*

  Servo Test

  Problem: how do we program arduinos with out programming arduinos?
  Answer: make them adjustable

  What are we adjusting?
  - Range of motion
  - Gap between instructions

  How do we do this with one pot per servo?
  - Switch: one direction controls range of motion, the other the timing

  Test 1:
  - Adjust range of motion

  Test 2:
  - Adjust timing

  Test 3:
  - Switching modes using toggle switch

  Test 4:
  - Bringing it all together

  Author: Peter Newman
  Organisation: University of Newcastle Science and Engineering Challenge
*/

#include <Servo.h>

//pin variables
const int pot = A0;
const int servoPin = 3;
const int ledPin = 13;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myServo.attach(servoPin);

  // testing the servo;
  myServo.write(0);
  delay(1000);
  myServo.write(180);
  delay(1000);
  myServo.write(90);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
