// C++ code
//
int led = 3;
int pot = A0;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int potval = analogRead(pot);
  analogWrite(led,((long) potval*255)/1023);
  Serial.println(((long) potval*255)/1023);
}