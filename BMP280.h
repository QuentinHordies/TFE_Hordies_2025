#ifndef BMP280_H     // Vérifie si  n'a pas encore été défini
  #define BMP280_H
#define adresse_BMP 0x77 

#include "TFE_Hordies_2025.h"

extern Adafruit_BMP280 bmp;

int init_BMP( char BMP_adr );
void etat_BMP(char BMP_adresse);
void mesure_BMP(void);
void affichage_BMP(void);
void lecture_BMP(char BMP_adres);

  extern float temperature;
  extern float pression;
  extern float altitude;

  #endif