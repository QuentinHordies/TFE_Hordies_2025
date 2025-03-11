#ifndef LORA_TFE_H     // Vérifie si  n'a pas encore été défini
  #define LORA_TFE_H

int init_LoRa(void);

int affichage_LoRa_BMP280(void);
int affichage_LoRa_GPS(void);
int affichage_LoRa_packet(void);

int LoRa_beginPacket (void);
int LoRa_endPacket (void);

#endif