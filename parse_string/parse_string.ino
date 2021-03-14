int bottom_value = 0;
int top_value = 0;
int current_int;
bool state = false;

void setup() {
  Serial.begin(9600);
//  Serial.setTimeout(15);
}

void loop() {
  if (Serial.available()){
    current_int = Serial.parseInt();
    if (current_int != 0){
      if (!state){
        Serial.print("Bottom Value: ");
        Serial.println(current_int);
      }
      else{
        Serial.print("Top Value: ");
        Serial.println(current_int);
      }
      state = !state;
    }
  }
}
