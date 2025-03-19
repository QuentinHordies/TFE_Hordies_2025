#ifndef BMP280_H     // Vérifie si  n'a pas encore été défini
  #define BMP280_H

#include "TFE_Hordies_2025.h"

extern Adafruit_BMP280 bmp;

int init_BMP( const byte adresse_BMP);
void etat_BMP(void);
void mesure_BMP(void);
void affichage_BMP(void);

  extern float temperature;
  extern float pression;
  extern float altitude;

  #endif