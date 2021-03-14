int input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (!Serial.available());
  input = Serial.readString().toInt();
  digitalWrite(13,input);
}
