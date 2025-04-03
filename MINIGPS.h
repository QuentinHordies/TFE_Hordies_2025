#ifndef MINI_GPS_H     // Vérifie si  n'a pas encore été défini
  #define MINI_GPS_H

#define adresse_GPS 0x10 

#include "TFE_Hordies_2025.h"

extern Adafruit_GPS GPS;

int init_GPS(char GPS_adr);
void etat_GPS(char GPS_adresse);
void mesure_GPS(void);
void affichage_GPS(void);
void lecture_GPS(void) ;

#endif