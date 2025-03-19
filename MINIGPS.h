#ifndef MINI_GPS_H     // Vérifie si  n'a pas encore été défini
  #define MINI_GPS_H

#include "TFE_Hordies_2025.h"

extern Adafruit_GPS GPS;

int init_GPS(const byte adresse_GPS);
void etat_GPS(void);
void mesure_GPS(void);
void affichage_GPS(void);

#endif