#include <Servo.h>

Servo bottom_servo;
Servo top_servo;

void setup() {
  bottom_servo.attach(5);
  top_servo.attach(6);
  bottom_servo.write(0);
  top_servo.write(0);
  delay(500);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  bottom_servo.write(180);
  top_servo.write(180);
  delay(500);

  bottom_servo.write(0);
  top_servo.write(0);
  delay(500);
}
