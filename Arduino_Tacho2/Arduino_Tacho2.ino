/*
  Counts rev per second
*/
const int sensorPin = 2;
unsigned long prevTime;
unsigned long currentTime;
volatile int count;
const int logTime = 500; //count the number of revolutions per 500 ms

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), magnetNearby, RISING);
  count = 0;
  prevTime = 0;
  currentTime = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis(); //do this once per loop

  // if we've measured half a second
  if (currentTime - prevTime >= logTime) {
    Serial.println(count);//print the number of revolutions in that 500ms
    count = 0;
    prevTime = currentTime;
  }
}

void magnetNearby() {
  count++;
}
