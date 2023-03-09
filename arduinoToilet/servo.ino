#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(90);
    delay(3000); 
    myservo.write(0);               // tell servo to go to position in variable 'pos'
    delay(3000);                       // waits 15ms for the servo to reach the position
  }                     // waits 15ms for the servo to reach the position
  
}