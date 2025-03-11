//***********************************************
//TFE 6eme
//Quentin Hordies
//ESP32,MPU9250,BMP280,ADAFRUIT mini GPSpa 1010d , 
//début:20/02/25
//*******************NOTES***********************

//*****************librairies********************

#include "TFE_Hordies_2025.h"


//*****************CONSTANTE*********************

//****************OBJETS*************************

//*****************VARIABLES*********************

//*****************SETUP*********************
void setup() {
  Serial.begin(115200);  // initialisation du port série
  while (!Serial);

/*
 init_LoRa();
 init_MPU();
 init_GPS();
 */
 init_BMP();

}
//*****************FONCTIONS*****************

void loop() { //*****************LOOP*********************
/*
 mesure_GPS();
 */
 //mesure_BMP(); 
/*
 affichage_MPU();
 affichage_GPS();
 */
 //*affichage_BMP();
/*
LoRa_beginPacket ();

  affichage_LoRa_packet();
  affichage_LoRa_GPS();
  affichage_LoRa_BMP280();

LoRa_endPacket ();
*/
  delay(1000);  // Pause de 1 secondes entre chaque lecture
}
