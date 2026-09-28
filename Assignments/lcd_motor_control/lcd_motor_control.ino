#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int potPin = A0;

int enablePin = 5;
int input1 = 7;
int input2 = 8;

void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(enablePin, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  int potValue = analogRead(potPin);

  
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);

  
  analogWrite(enablePin, motorSpeed);
  
  Serial.print("Potentiometer: ");
  Serial.print(potValue);

  Serial.print(" | Motor Speed (PWM): ");
  Serial.println(motorSpeed);

  lcd.setCursor(0, 0);
  lcd.print("p:    ");
  lcd.setCursor(0, 0);
  lcd.print("p:");
  lcd.print(potValue);
  
  lcd.setCursor(2, 1);
  lcd.print("m:    ");
  lcd.setCursor(2, 1);
  lcd.print("m:");
  lcd.print(motorSpeed);

 

}