#include <Servo.h>;
Servo bottom_servo;
Servo top_servo;

int bottom_value = 0;
int top_value = 0;
int current_int;
bool state = false;

void setup() {
  Serial.begin(9600);
  bottom_servo.attach(5);
  top_servo.attach(6);
  bottom_servo.write(0);
  top_servo.write(0);
  Serial.setTimeout(10);
}

void loop() {
  if (Serial.available()) {
    current_int = Serial.parseInt();
    if (current_int != 0) {
      if (!state) {
        //        Serial.print("Bottom Value: ");
        //        Serial.println(current_int);
        bottom_value = current_int;
        //        delay(300);
      }
      else {
        //        Serial.print("Top Value: ");
        //        Serial.println(current_int);
        top_value = current_int;
        bottom_servo.write(bottom_value);
        top_servo.write(top_value);
//        delay(0);
      }
      state = !state;
    }
  }
}
