const int hallOut = 2;
const int ledPin = 13;
int sensorState;

void setup() {
  // put your setup code here, to run once:
  pinMode(hallOut, INPUT);
  pinMode(ledPin, OUTPUT);
  sensorState = 0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorState = digitalRead(hallOut);
//  Serial.println(sensorState);
  if (sensorState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else if (sensorState == HIGH) {
    digitalWrite(ledPin, LOW);
  }
  
}
