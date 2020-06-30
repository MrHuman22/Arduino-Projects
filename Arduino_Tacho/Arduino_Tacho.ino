
/*
Arduino Hall Effect Sensor Project
by Arvind Sanjeev and adapted by Peter Newman
Please check out  http://diyhacking.com for the tutorial of this project.
DIY Hacking
*/


 volatile byte revTime;
 unsigned float rpm;
 unsigned long prevTime;
 const int sensorPin = 2;
 void setup()
 {
   Serial.begin(115200);
   pinMode(sensorPin, INPUT);
   attachInterrupt(0, magnet_detect, RISING); //Initialize the intterrupt pin (Arduino digital pin 2)
   revTime = 0;
   rpm = 0;
   prevTime= 0;
 }
 void loop()//Measure RPM
 {
   if (half_revolutions >= 2) { 
     rpm = 60*1000/(millis() - prevTime)*half_revolutions;
     prevTime = millis();
     half_revolutions = 0;
     Serial.println(rpm,DEC);
   }
 }
 void magnet_detect()//This function is called whenever a magnet/interrupt is detected by the arduino
 {
   half_revolutions++;
   Serial.println("detect");
 }
