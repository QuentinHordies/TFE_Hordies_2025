#ifndef BMP280_H     // Vérifie si  n'a pas encore été défini
  #define BMP280_H

#include "TFE_Hordies_2025.h"

int init_BMP(void);
int mesure_BMP(void);
int affichage_BMP(void);

  extern float temperature;
  extern float pression;
  extern float altitude;

  #endif