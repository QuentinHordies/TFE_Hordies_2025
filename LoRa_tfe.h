#ifndef LORA_TFE_H     // Vérifie si  n'a pas encore été défini
  #define LORA_TFE_H

#include "TFE_Hordies_2025.h"

extern unsigned int rpm;

int init_LoRa(void);
void etat_LoRa(void);
void affichage_LoRa_RPM (void);
void affichage_LoRa_VITESSE (void);
void affichage_LoRa_BMP280(void);
void affichage_LoRa_GPS(void);
int affichage_LoRa_packet(int packet_number);

void LoRa_beginPacket (void);
void LoRa_endPacket (void);

#endif