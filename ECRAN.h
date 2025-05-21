#ifndef ECRAN_H     // Vérifie si  n'a pas encore été défini
  #define ECRAN_H

#include "TFE_Hordies_2025.h"

#define nextion Serial1 // Port série dédié à l'écran Nextion (UART2)

void init_ECRAN(void);
void affichage_ECRAN_RPM(int rpm_calcule);
void affichage_ECRAN_VITESSE(int VITESSE_calcule);

  #endif
