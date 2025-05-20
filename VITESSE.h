#ifndef VITESSE_H     // Vérifie si  n'a pas encore été défini
  #define VITESSE_H

#include "TFE_Hordies_2025.h"

#define nextion Serial1

extern float vitesse_kmh;
/*
const float diametreRoue = 0.3; // metres
const int impulsionsParTour = 2; //nombre de contacts
const int pinCapteur = 33;
*/
void init_VITESSE(void);
void determiner_vitesse(void);

//void lecture_VITESSE(void);

  #endif