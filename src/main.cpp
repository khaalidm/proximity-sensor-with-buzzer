#include <Arduino.h>
#include <NewPing.h>

const int pin9 = 9;
const int pin10 = 10;
const int pin11 = 11;
const int maxDistance = 400;

NewPing sonar(pin9, pin10, maxDistance);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin11, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (sonar.ping_cm() <= 5)
  {
    digitalWrite(pin11, HIGH);
    delay(500);
    Serial.println("proximity alert!");
    digitalWrite(pin11, LOW);
    // delay(500);
  }
  else
  {
    Serial.print("Distance = ");
    Serial.print(sonar.ping_cm());
    Serial.println(" cm");
  }
  delay(500);
}