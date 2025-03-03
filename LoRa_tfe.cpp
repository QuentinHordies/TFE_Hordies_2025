
#include <SPI.h> // va avec lora
#include <LoRa.h> 

#define ss 5 // pin chip select
#define rst 14 // pin reset
#define dio0 2

int counter = 0;

int init_LoRa(void)
{
  Serial.println("Emeteur LoRa"); //setup émeteur LoRa 
  LoRa.setPins(ss, rst, dio0);
    if (!LoRa.begin(433E6)) 
  {
    Serial.println("échec démarage LoRa ");
    while (1);
  }
  else
  {
    Serial.println("réussite démarage LoRa ");
  }
 // LoRa.setSyncWord(0xF3);// code de synchronisation pour le receveur
  Serial.println("initialisation LoRa OK");

}