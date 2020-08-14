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
  - 0C: Adjust values based on max joystick positions

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
const int joystickX = A1;
const int joystickY = A0;
const int ledPin = 13;

//values
int jX;
int jY;
int xServoDelay = 1000;
int yServoMovement = 45;

//control flow variables
const int debounceTime = 200;

//button reading variables
boolean registeredButtonPress = false;
int buttonValue;

//state variables
int servoState = 0;
int servoCount = 2;
boolean registerX = false;
boolean registerY = false;



Servo myServo;

void setup() {
  //Establish serial connection
  Serial.begin(9600);
  while (!Serial)
  {
    delay(10);
  }

  //  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // testing the servo;
  //  myServo.write(0);
  //  delay(1000);
  //  myServo.write(180);
  //  delay(1000);
  //  myServo.write(90);
  //  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Reading the joystick commands
  jX = analogRead(joystickX);
  delay(10);
  jY = analogRead(joystickY);
  delay(10);
  handleX();
  handleY();

  // Reading the button
  debounceButton();




  delay(1000);
  registerX = false;
  registerY = false;
  registeredButtonPress = false;

  //  debugging modes
  //  displayJoystickValues();
  displayMovementAndTimingValues();
  displayServoState();
}

void displayServoState()
{
  Serial.print("Current Controlling Servo ");
  Serial.println(servoState);
}


void debounceButton()
{
  // should increment the servoState each time the button is pressed on the joystick
  buttonValue = digitalRead(buttonPin);
  if (!registeredButtonPress && buttonValue == HIGH) {
    registeredButtonPress = true;
    servoState ++;
    // cycle servoState
    if (servoState >= servoCount)
    {
      servoState = 0;
    }
  }
}



void handleX()
{

  if (!registerX)
  {
    registerX = true;
    switch (jX)
    {
      case 0:
        xServoDelay -= 200;
        flashRegisterLED(0);
        break;
      case 1023:
        xServoDelay += 200;
        flashRegisterLED(0);
        break;
      default:
        break;
    }
  }
}

void handleY()
{
  if (!registerY)
  {
    registerY = true;
    switch (jY)
    {
      case 0:
        yServoMovement += 5;
        flashRegisterLED(1);
        break;
      case 1023:
        yServoMovement -= 5;
        flashRegisterLED(1);
        break;
      default:
        break;
    }
  }

}

void flashRegisterLED(int axis)
{
  switch (axis) {
    // single flash to denote a registered signal in X
    case 0:
      digitalWrite(ledPin, HIGH);
      delay(250);
      digitalWrite(ledPin, LOW);
      break;
    // double flash to denote a registered signal in Y
    case 1:
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(50);
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
  }

}

void displayMovementAndTimingValues()
{
  Serial.print("Delay: ");
  Serial.print(xServoDelay);
  Serial.print(", Movement: ");
  Serial.println(yServoMovement);
}

void displayJoystickValues()
{
  Serial.print("jX: ");
  Serial.print(jX);
  Serial.print(", jY: ");
  Serial.println(jY);
}

void switchState() {

}
