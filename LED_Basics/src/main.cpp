#include <Arduino.h>

#include "allumer_toutes_les_leds_une_a_une.h"
#include "allumer_toutes_les_leds_en_meme_temps.h"

int leds[5] = {2, 3, 4, 5, 6};
int taille = sizeof(leds) / sizeof(leds[0]);

void setup()
{
  for (int i = 0; i < taille; i++)
  {
    pinMode(leds[i], OUTPUT);
  };
}

void loop()
{
  // Allumer toutes les leds une à une
  allumer_toutes_les_leds_une_a_une(leds, taille);

  // Allumer toutes les leds en même temps
  allumer_toutes_les_leds_en_meme_temps(leds, taille);
}
