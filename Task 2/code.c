#include <Servo.h>

Servo s;

void setup() {
  s.attach(9);       
  pinMode(12, OUTPUT); 
}

void loop() {

  int val = analogRead(A0);   
  int angle = val / 6;        

  if (angle > 68) {
    angle = 68;               
    digitalWrite(12, HIGH);   
  } else {
    digitalWrite(12, LOW);    
  }

  s.write(angle);             

  delay(20);
}