#ifndef VITESSE_H     // Vérifie si  n'a pas encore été défini
  #define VITESSE_H

#include "TFE_Hordies_2025.h"

#define nextion Serial1

extern float vitesse_kmh;

void init_VITESSE(void);
void determiner_vitesse(void);

  #endif