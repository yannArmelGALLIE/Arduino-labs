#include <Arduino.h>

void allumer_toutes_les_leds_une_a_une(const int leds[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        digitalWrite(leds[i], HIGH);
        delay(200);
        digitalWrite(leds[i], LOW);
    }

    for (int i = taille - 1; i >= 0; i--)
    {
        digitalWrite(leds[i], HIGH);
        delay(200);
        digitalWrite(leds[i], LOW);
    };
}