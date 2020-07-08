const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  Serial.println("LED On!");
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  Serial.println("LED Off!");
}
