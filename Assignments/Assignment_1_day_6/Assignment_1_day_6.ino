/*
TASK: ULTRASONIC SENSOR BASED LED BRIGHTNESS CONTROL

Objective:
Design and implement a circuit where the brightness of an LED is controlled based on the distance measured by an ultrasonic sensor.

Requirements:

1. Hardware:
   - Arduino board
   - HC-SR04 Ultrasonic Sensor
   - LED
   - Appropriate resistor for the LED
   - Breadboard
   - Jumper wires

2. Circuit:
   - The entire circuit must be built using a breadboard.
   - Wiring must be neat, properly routed, and easy to understand.
   - Use color-coded wires wherever possible.
   - Avoid unnecessarily long or tangled connections.

3. Ultrasonic Sensor:
   - Use the HC-SR04 ultrasonic sensor to measure distance.
   - Distance should be measured in centimeters.
   - Consider the usable distance range as 20 cm to 200 cm.

4. LED Brightness:
   - Use PWM to control the LED brightness.
   - Map the measured distance from:

       Distance: 20 cm → 200 cm
       Brightness: 0 → 255

   - Therefore:
       At 20 cm: LED brightness = 0
       At 200 cm: LED brightness = 255
       Values in between should be proportionally mapped.

5. Custom map() Function:
   - DO NOT copy the map() function from the Arduino IDE, Arduino documentation, Tinkercad, or any other source.
   - You must understand the mapping equation and build your OWN custom mapping function.
   - The custom mapping function must have a FLOAT return type.
   - Do not use the built-in Arduino map() function anywhere in the program.

6. Constraints:
   - Do not use Arduino's built-in map() function.
   - Create your own mapping logic.
   - Keep the code properly structured and commented.
   - Ensure the LED brightness changes according to the measured distance.
   - Handle distances outside the 20–200 cm range appropriately.

7. Submission:
   Submit the following in a single PDF submission:

   A. Circuit Screenshot:
      - Clear screenshot of the completed circuit.
      - Breadboard and all connections must be clearly visible.
      - Wiring should be neat and color-coded.

   B. Source Code:
      - Complete Arduino source code.
      - Include the self-written custom map function.
      - The custom map function must return FLOAT.
      - Do not submit code containing the Arduino built-in map() function.

   C. The circuit screenshot and source code should be clearly identifiable in the submission.

Expected Output:

As the object moves farther from the ultrasonic sensor, the LED brightness should increase.

Distance Range:
20 cm ─────────────────────── 200 cm

LED Brightness:
0 ────────────────────────── 255

The circuit should demonstrate a smooth and proportional relationship between distance and LED brightness.

Code by Rayan Raphy
*/

//declaring the pins
const int trig = 5;
const int echo = 6;

const int led = 3;

//custom map funciton:
float mapper(double value,double ini_min,double ini_max,double fin_min,double fin_max){
  if(value<ini_min || value > ini_max){
    return 0; // outside limit cases handled in this seciton
  }else{
    return (value - ini_min)*(fin_max - fin_min)/(ini_max - ini_min);  //maping is done here
  }
}
void setup()
{
  //declaring the input and output pins
  pinMode(led, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  //acquiring duration from hiding ht eobstacle
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  //clearing the trig pin of outputs
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  //fired the sound wave 
  long duration = pulseIn(echo,HIGH);
  
  
  //waiting untill the signal reach the echo 
  float distance = (duration*0.0343)/2.0;
  int bright = mapper(distance,20,200,0,255);
  //calculting the distance and mapping the 
  
  analogWrite(led,bright);
  
  Serial.print("Distance: "); 
  Serial.print(distance);
  Serial.print("  |  LED brigthness: ");
  Serial.println(bright);
}