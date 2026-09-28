const int led_1 = 4;
const int sw_1 = 7;
void setup(){
  pinMode(led_1,OUTPUT);
  pinMode(sw_1,INPUT);
}
void loop(){
  bool swIn = digitalRead(sw_1);
  digitalWrite(led_1,swIn);
}