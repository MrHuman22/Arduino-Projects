#include <LiquidCrystal.h>

const int potPin = A1;
int prevVal;

//LCD pin to Arduino
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;
const int pin_BL = 10;
LiquidCrystal lcd(pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);

void setup() {
  
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
