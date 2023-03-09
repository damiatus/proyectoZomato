#include "Ultrasonic.h"
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

Ultrasonic ultrasonic(7);
void setup() {
  myservo.attach(8);  // attaches the servo on pin 8 to the servo object
    Serial.begin(9600);
}
void loop() {
    myservo.write(0); 

    long RangeInCentimeters;
    int position = 0;
    delay(5000);
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    Serial.print(RangeInCentimeters);//0~400cm
    Serial.println(" cm");

    if (RangeInCentimeters < 10) { // if distance is less than 10 cm
      position = 1;
      digitalWrite(9, LOW);  // turn off UV light light
      }  

    while (position == 1){

      RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
      delay(1000);
      Serial.print(position);                     
      if(RangeInCentimeters > 10) {
        
        for (pos = 0; pos < 1; pos += 1) { // goes from 0 degrees to 90 degrees
          myservo.write(90);
          delay(1000);                     // waits 1s for the servo to reach the position
          myservo.write(0);               // tell servo to go to position 0 degrees
          delay(1000);                       // waits 1s for the servo to reach the position
        }  
        
        position = 0;   
      }
    }
    digitalWrite(9, HIGH);          // Turns on the UV light
    Serial.print(position);
    }
