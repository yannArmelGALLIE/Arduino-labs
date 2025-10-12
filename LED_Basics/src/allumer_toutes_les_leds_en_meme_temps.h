#include <Arduino.h>

void allumer_toutes_les_leds_en_meme_temps(const int leds[], int taille)
{
    for (int i = 0; i < 5; i++)
    {
        digitalWrite(leds[i], HIGH);
        delay(200);
    }
}