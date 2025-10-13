#include <Arduino.h>

float avec_lm35()
{
    int pinLM35 = analogRead(A0);
    float temperature = pinLM35 * (5.0 / 1024.0) * 100.0;
    return temperature;
}