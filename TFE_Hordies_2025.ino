//***********************************************
//TFE 6eme
//Quentin Hordies ඞ
//ESP32,MPU9250,BMP280,ADAFRUIT mini GPSpa 1010d , 
//début:20/02/25
//*******************NOTES***********************

//*****************librairies********************
#include "TFE_Hordies_2025.h"
//*****************CONSTANTE*********************

//****************OBJETS*************************

//*****************VARIABLES*********************
int counter =0;
//*****************SETUP*********************
void setup() {
  Serial.begin(115200);  // initialisation du port série
  while (!Serial);
  Wire.begin();


 init_LoRa();

 //etat_GPS(adresse_GPS);
 //etat_BMP(adresse_BMP);
 etat_MPU(adresse_MPU);
 
}

void loop() { 


 //mesure_GPS();
 //mesure_BMP(); 
 //mesure_MPU();

 //affichage_GPS();
 //affichage_BMP();
 //affichage_MPU();

 LoRa_beginPacket ();//essayer de fusioner avec affichage_lora_packet
 affichage_LoRa_packet(counter);

  affichage_LoRa_GPS();
  affichage_LoRa_BMP280();

LoRa_endPacket ();
 delay_second(1);  // en secondes
}
