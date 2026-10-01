// C++ code
//
#include <Servo.h>
Servo ser;
//setingup the ultra
const int trig = 5;
const int echo = 4;

const int ser_pin = 3;

const int in1 = 7;
const int in2 = 8;
const int ena = 9;//pwm


void setup()
{
  ser.attach(ser_pin);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //motor conrol
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
  Serial.begin(9600);
   
  
}

void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long duration = pulseIn(echo,HIGH);
  
  double distance = (duration*0.0343)/2;
  //consider the distance range of 0,200
  int ang = map(distance,0,200,0,180);
  int speed = map(distance,0,200,0,255);
  ser.write(ang);
  //set direction
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
 
  
  Serial.println(speed);
  analogWrite(ena,speed);
  delay(50);//stabilization
  
}