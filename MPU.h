#ifndef MPU_H     // Vérifie si il n'a pas encore été défini
  #define MPU_H
#define adresse_MPU 0x68 
#include "TFE_Hordies_2025.h"
  
extern MPU9250 mpu;

int init_MPU(char MPU_adr);
void etat_MPU(char MPU_adresse);
void affichage_MPU(void);
int mesure_MPU(void); // mesure + affichage série
void lecture_MPU(void);

#endif