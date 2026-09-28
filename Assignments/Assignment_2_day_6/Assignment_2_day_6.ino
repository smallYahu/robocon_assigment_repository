/*
2. TASK: TWO LEDs WITH POTENTIOMETER

Objective:
Control the brightness of two LEDs using a potentiometer.

Requirements:
- Use an Arduino, breadboard, potentiometer, two LEDs, and suitable resistors.
- LED 1 brightness should increase as the potentiometer is turned up.
- LED 2 brightness should decrease as the potentiometer is turned up.
- Use PWM pins for both LEDs.
- Build the circuit neatly on a breadboard.
- Use color-coded wiring and keep connections clean and organized.

Submission:
- Circuit screenshot
- Complete Arduino code
- Submit in PDF

Expected:
Potentiometer LOW → LED 1 OFF/LOW, LED 2 HIGH
Potentiometer HIGH → LED 1 HIGH, LED 2 OFF/LOW

code By Rayan Raphy
*/
const int led_1 = 5;
const int led_2 = 6;

const int pot = A0;

void setup()
{
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  
  pinMode(pot, INPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  int potVal = analogRead(pot);
  
  int bright = map(potVal,0,1023,0,255);
  
  analogWrite(led_1,bright);
  analogWrite(led_2,(255-bright));
  
  Serial.print("Led 1 brightness: ");
  Serial.print(bright);
  Serial.print("  |  Led 2 brightness: ");
  Serial.println(255-bright);
  
}