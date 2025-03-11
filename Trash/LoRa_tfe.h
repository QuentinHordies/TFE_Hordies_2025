#ifndef LORA_TFE_H     // Vérifie si  n'a pas encore été défini
  #define LORA_TFE_H

  #include "MPU.h"
  #include "MINIGPS.h"
  #include "BMP280.h"
  #include <SPI.h> // va avec lora
  #include <LoRa.h> 

int init_LoRa(void);

int affichage_LoRa_BMP280(void);
int affichage_LoRa_GPS(void);
int affichage_LoRa_packet(void);

int LoRa_beginPacket (void);
int LoRa_endPacket (void);

#endif