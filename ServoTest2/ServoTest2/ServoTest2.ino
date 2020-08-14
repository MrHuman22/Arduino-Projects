/*

  Servo Test

  Problem: how do we program arduinos with out programming arduinos?
  Answer: make them adjustable

  What are we adjusting?
  - Range of motion
  - Temporal Gap between instructions

  Use Joystick 
  - X: controls range of motion, the other the timing
  - Y: controls timing (Y>0 increases time between pulses, Y<0 decreases time between instructions)

  Test 0:
  - 0A: Read from the joystick
  - 0B: Map joystick values

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
const int servoPin = 3;
const int buttonPin = 2;
const int joystickX = A0;
const int joystickY = A1;
const int ledPin = 13;

//state
int servoState = 0;
boolean
int servoCount = 1;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

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
  
  // Reading the joystick commands
}

void debounceButton()
{
  
  }

void switchState(){
  
  }
