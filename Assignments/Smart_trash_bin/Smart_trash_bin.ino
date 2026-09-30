/*
Code developed by Rayan Raphy
*/

#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//createing the lcd object
LiquidCrystal_I2C lcd(0x27,16,2);

//Servo Objects
Servo ser1;
Servo ser2;

// Pin Definitions
const int but= 12;
const int sw1 = 8;
const int ser1_pin = 5;
const int ser2_pin= 6; 
const int trig = 3;
const int echo = 4;
const int pir = 7;

//bin dimensions
double bin_height  = 120;
//miscellanious vars
double percent = 50;

// custom Ultrasonic Sensor Class
class UltSensor {
  private:
    int trigPin;
    int echoPin;

  public:
    // fixed constructor spelling and initialized member variables
    UltSensor(int trig, int echo) {
      trigPin = trig;
      echoPin = echo;
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }

    double measure() {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      long duration = pulseIn(echoPin, HIGH);
      double distance = (duration * 0.0343) / 2.0; //Distance in cm
      return distance;
    }
};

// Make it a gloabl instance..
UltSensor ults1(trig, echo);

// Custom map function for checking the limits
float mapper(double value, double ini_min, double ini_max, double fin_min, double fin_max) {
  if (value < ini_min || value > ini_max) {
    return 0;
  } else {
    return (value - ini_min) * (fin_max - fin_min) / (ini_max - ini_min);
  }
}

  

void setup()
{
  Serial.begin(9600);

  // attaching the servos
  ser1.attach(ser1_pin);
  ser2.attach(ser2_pin);

  // seting up the switches and buttons
  pinMode(sw1, INPUT);
  pinMode(but, INPUT);
  pinMode(pir,INPUT);

  // Initialize LCD display
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Starting...     ");
  delay(500);
  
  lcd.setCursor(0, 1);
  lcd.print("Smart Trash Bin ");
  delay(1000);
  lcd.clear();
  
  
}

void loop()
{
  lcd.setCursor(0, 0);
  if(digitalRead(sw1)){
    double height = ults1.measure();
    double occupied = bin_height - height;
    percent = mapper(occupied,0,bin_height,0,100);
    
    bool state = (digitalRead(pir) || digitalRead(but)) && percent;

    if(percent == 0.0){
      lcd.print("Garbage: Full   ");
    }else if (state) {
      lcd.print("Garbage: OPEN   ");
	  lcd.setCursor(0,1);
      lcd.print("                ");
      ser1.write(90); // Open lid
      ser2.write(90);
      delay(2000);
    } else {
      lcd.print("Garbage: CLOSED ");
      ser1.write(180);  // Close lid
      ser2.write(0);
    }
    lcd.setCursor(0,1);
    lcd.print("SPACE LEFT:");
    lcd.print(100-percent);
  }else{
    lcd.print("Garbage Locked ");
  }
  delay(100); // Short stabilization delay
  
}