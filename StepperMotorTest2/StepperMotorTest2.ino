#include <Stepper.h>
#include <LiquidCrystal.h>

const int potPin = A1;
int prevVal;
const int stepsPerRevolution = 200;
int stepCount;

//LCD pin to Arduino
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 11; // making room for myStepper
const int pin_d5 = 12; // making room for myStepper
const int pin_d6 = 6;
const int pin_d7 = 7;
const int pin_BL = 10;
LiquidCrystal lcd(pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);
Stepper myStepper(stepsPerRevolution,2,3,4,5);

void setup() {
  stepCount = 0;
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Electrospeak.com");
  prevVal = analogRead(potPin);
  lcd.setCursor(0,1);
  lcd.print(prevVal);
}
  

void loop() {

  int potVal = analogRead(potPin);
  int motorSpeed = map(potVal, 0, 1023,0,100);
  if(motorSpeed > 0){
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution / 100);
    }
  // if changed, then update
  if(potVal != prevVal){
    lcd.setCursor(0,1);
    lcd.print("    "); // overwrite blank
    lcd.setCursor(0,1);
    lcd.print(potVal);
    prevVal = potVal; // update prevVal;
    }

  Serial.println(potVal);
  delay(1500);

}
