#define LoRa_tfe.h

int init_LoRa(void);

int affichage_LoRa_BMP280(void);
int affichage_LoRa_GPS(void);
int affichage_LoRa_packet(void);

int LoRa_beginPacket (void);
int LoRa_endPacket (void);