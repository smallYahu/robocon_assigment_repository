/*
Control the speed of a DC motor using a potentiometer and L293D motor driver in Tinkercad.
Arduino Uno
L293D motor driver IC
DC motor
Breadboard
Neat and color-coded wiring
Build the circuit in Tinkercad using the above components.
Use the potentiometer to control the speed of the DC motor.
Use PWM to vary the motor speed from 0% to 100%.
The motor should stop at the minimum potentiometer value and run at maximum speed at the maximum value.
Tinkercad circuit screenshotArduino code
Submit in PDF format.
NO AI TO BE USED.

Code by Rayan 
*/

//initializint the pins


const int in1 = 1;
const int in2 = 2;
const int en = 3;
//additionaly pseed viewing features
const int led = 5;

const int pot = A0;

void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en, OUTPUT);
  
  pinMode(led, OUTPUT);
  
  pinMode(pot,INPUT);
  
  
}

void loop()
{
  //acquiring value from potentiometer
  int potVal = analogRead(pot);
  int speed = map(potVal,0,1023,0,255);
  
  //setting up the direction
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  //setting up the speed
  analogWrite(en,speed);
  analogWrite(led,speed);
}