/*
3. Problem Statement:

You are designing a simple control system for a robotic vehicle using an Arduino. The robot has two switches that control its movement. Three LEDs — Green, Yellow, and Red — are used to indicate what the robot is currently doing.

Your task is to connect the two switches and three LEDs to the Arduino and write a program that reads the state of both switches and controls the LEDs according to the following conditions:

• When both switches are ON:
  - Green LED should be ON.
  - Yellow LED should be OFF.
  - Red LED should be OFF.
  - The robot is moving forward.

• When the first switch is OFF and the second switch is ON:
  - Green LED should be OFF.
  - Yellow LED should be OFF.
  - Red LED should be ON.
  - The robot is moving backward.

• When the second switch is OFF, regardless of the state of the first switch:
  - Green LED should be OFF.
  - Yellow LED should be ON.
  - Red LED should be OFF.
  - The robot is stopped.

Implement a tinkercad circuit for the above problem statement

code by Rayan Raphy
*/
int led_1 = 8;
int led_2 = 9;
int led_3 = 10;

int sw_1 = 2;
int sw_2 = 3;

void setup()
{
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  
  pinMode(sw_1, INPUT);
  pinMode(sw_2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  bool sw_1_state = digitalRead(sw_1);
  bool sw_2_state = digitalRead(sw_2);
  digitalWrite(led_1,(sw_1_state && sw_2_state));//The robot is moving forward.
  digitalWrite(led_2,(!sw_2_state));//The robot is stopped.
  digitalWrite(led_3,(!sw_1_state && sw_2_state));//The robot is moving backward.
}