// C++ code
//

#include <Servo.h>

const int sig = 3;
const int sig2 = 5;
const int pot = A0;

Servo s;
Servo s2;
void setup()
{
  s.attach(sig);
  s2.attach(sig2);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int potVal = analogRead(pot);
  int angle = map(potVal, 0,1023,0,180);
  Serial.println(angle);
  s.write(angle);
  s2.write(180 - angle);
  delay(10);
}