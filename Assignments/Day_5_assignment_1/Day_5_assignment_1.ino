/*
1. You are designing a simple lighting control system for a robotic vehicle using an Arduino. The system has one potentiometer that controls the brightness of three LEDs — Green, Yellow, and Red.

Your task is to connect the potentiometer and three LEDs to the Arduino and write a program that reads the value of the potentiometer and controls the LEDs according to the following conditions:

When the potentiometer value is between 0 and 340:
Green LED should be ON.
Yellow LED should be OFF.
Red LED should be OFF.

The Green LED should have brightness proportional to the potentiometer value.
When the potentiometer value is between 341 and 680:
Green LED should be OFF.
Yellow LED should be ON.
Red LED should be OFF.

The Yellow LED should have brightness proportional to the potentiometer value within this range.
When the potentiometer value is between 681 and 1023:
Green LED should be OFF.
Yellow LED should be OFF.
Red LED should be ON.

The Red LED should have brightness proportional to the potentiometer value within this range.
Display the potentiometer value and the current LED state on the Serial Monitor.

Code by Rayan Raphy
*/
const int led_1 = 3;
const int led_2 = 5;
const int led_3 = 6;

const int pot = A0;

void setup()
{
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int green_bright = 0;
  int yellow_bright = 0;
  int red_bright = 0;
  int potVal = analogRead(pot);
  if(potVal>=0 && potVal <= 340){
    green_bright = map(potVal,0,340,0,255);
    analogWrite(led_1,green_bright);
    digitalWrite(led_2,LOW);
    digitalWrite(led_3,LOW);
  }else if(potVal >=341 && potVal <=680){
    yellow_bright = map(potVal,341,680,0,255);
    analogWrite(led_2,yellow_bright);
    digitalWrite(led_1,LOW);
    digitalWrite(led_3,LOW);
  }else if(potVal >= 681 && potVal<=1023){
    red_bright = map(potVal,681,1023,0,255);
    analogWrite(led_3,red_bright);
    digitalWrite(led_1,LOW);
    digitalWrite(led_2,LOW);
  }
  Serial.print("Green:");
  Serial.print(green_bright);
  Serial.print("	");
  Serial.print("Yellow:");
  Serial.print(yellow_bright);
  Serial.print("	");
  Serial.print("Red:");
  Serial.print(red_bright);
  Serial.print("	");
  Serial.print("The potentialmeter Values: ");
  Serial.println(potVal);
  
  
}