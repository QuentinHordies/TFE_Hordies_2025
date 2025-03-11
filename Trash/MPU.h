#ifndef MPU_H     // Vérifie si  n'a pas encore été défini
  #define MPU_H
  #include <MPU9250.h>
  
int init_MPU(void);
int mesure_MPU(void);
int affichage_MPU(void);

#endif