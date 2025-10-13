#include <Arduino.h>

float avec_lm35(LM35_pin)
{
    int valeur = analogRead(LM35_pin);
    float tension = valeur * 5.0 / 1023.0;
    float temperature = tension * 100.0;
    return temperature;
}