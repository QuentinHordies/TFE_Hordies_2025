#ifndef MPU_H     // Vérifie si  n'a pas encore été défini
  #define MPU_H

#include "TFE_Hordies_2025.h"
  
extern MPU9250 mpu;

int init_MPU(const byte adresse_MPU);
void etat_MPU(void);
void affichage_MPU(void);
int mesure_MPU(void);

#endif