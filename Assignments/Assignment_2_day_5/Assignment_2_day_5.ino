/*
2. You are designing a simple warning system for a robotic vehicle using an Arduino. The robot has one ultrasonic sensor to detect obstacles and one potentiometer to adjust the warning distance. Three LEDs — Green, Yellow, and Red — are used to indicate how close the robot is to an obstacle.

Your task is to connect the ultrasonic sensor, potentiometer, and three LEDs to the Arduino and write a program that reads the distance from the ultrasonic sensor and the value of the potentiometer and controls the LEDs according to the following conditions:

Use the potentiometer to set a warning distance between 10 cm and 50 cm.
When the obstacle is farther than the warning distance:
Green LED should be ON.
Yellow LED should be OFF.
Red LED should be OFF.
The robot is at a safe distance.
When the obstacle is within the warning distance but more than half of the warning distance:
Green LED should be OFF.
Yellow LED should be ON.
Red LED should be OFF.
The robot is getting close to the obstacle.
When the obstacle is at or below half of the warning distance:
Green LED should be OFF.
Yellow LED should be OFF.
Red LED should be ON.


The robot is dangerously close to the obstacle.
Display the following on the Serial Monitor:
Distance measured by the ultrasonic sensor.
Warning distance set by the potentiometer.
Current status of the robot.

3.Make your own map function instead of using the inbuilt function which returns a float and implement it in code

*/
int trigPin = 9;
int echoPin = 10;
int potPin = A0;

int greenLed = 2;
int yellowLed = 3;
int redLed = 4;

long duration;
float distance;
int potValue;
float warningDist;

float customMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;
  
  potValue = analogRead(potPin);
  warningDist = customMap(potValue, 0, 1023, 10.0, 50.0);
  
  digitalWrite(greenLed, distance > warningDist);
  digitalWrite(yellowLed, (distance <= warningDist) && (distance > (warningDist / 2.0)));
  digitalWrite(redLed, distance <= (warningDist / 2.0));
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm  Warning Distance: ");
  Serial.print(warningDist);
  Serial.print(" cm  Status: ");
  if (distance > warningDist) {
    Serial.println("Safe Distance");
  } else if(distance > (warningDist / 2.0)) {
    Serial.println("Getting Close");
  } else {
    Serial.println("Dangerously Close");
  }
  
  delay(100);
}