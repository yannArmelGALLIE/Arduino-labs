#include <Arduino.h>
#include <LiquidCrystal.h>

#include <avec_lm35.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float temperature = avec_lm35(A0);
  Serial.println(temperature);
  delay(500);
}