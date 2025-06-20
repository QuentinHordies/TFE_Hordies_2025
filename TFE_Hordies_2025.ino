//***********************************************
//TFE 6eme
//Quentin Hordies ඞ
//ESP32,MPU9250,BMP280,ADAFRUIT mini GPSpa 1010d , capteur a effet hall ,capteur inductif, lecteur de carte SD MSD-7-A
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

 init_RPM();
 init_LoRa();
 init_ECRAN();
 init_VITESSE();

 etat_GPS(adresse_GPS);
 etat_BMP(adresse_BMP);
 etat_MPU(adresse_MPU);
 
}

void loop() { 


 lecture_GPS();
 lecture_BMP(); 
 lecture_MPU();
 lecture_RPM();

 
affichage_ECRAN_RPM(rpm);
affichage_ECRAN_VITESSE(vitesse_kmh);

 LoRa_beginPacket ();//création du paquet pour l'envoie par LoRa
 affichage_LoRa_packet(counter);

  affichage_LoRa_RPM ();
  affichage_LoRa_VITESSE ();
  affichage_LoRa_GPS();
  affichage_LoRa_BMP280();

LoRa_endPacket ();
// delay_second(1);  // en secondes !!!! A SUPPRIMER , POUR LES TESTS
}
