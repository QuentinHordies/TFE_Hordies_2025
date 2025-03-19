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


 init_GPS(adresse_GPS);
 // etat_GPS();
 init_BMP(adresse_BMP);
 // etat_BMP();
 init_MPU(adresse_MPU);
 // etat_MPU();
 init_LoRa();

}


void loop() { 

 affichage ();
 mesures ();


 LoRa_beginPacket ();//essayer de fusioner avec affichage_lora_packet
 affichage_LoRa_packet(counter);

  affichage_LoRa_GPS();
  affichage_LoRa_BMP280();

LoRa_endPacket ();

 // delay_second(1);  // en secondes
}
