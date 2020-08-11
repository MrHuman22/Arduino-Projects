#include <Servo.h>

const int potPin = A1;
const int servoPin = 5;
const int restPoint = 90;
const int maxPoint = 120;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);

  myServo.write(0);
  delay(500);
  myServo.write(180);
  delay(500);
  myServo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.println(potVal);
  myServo.write(maxPoint);
  delay(300);
  myServo.write(restPoint);
  delay(300);
}
