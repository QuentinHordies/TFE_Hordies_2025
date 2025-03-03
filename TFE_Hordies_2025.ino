//***********************************************
//TFE 6eme
//Quentin Hordies
//ESP32,MPU9250,BMP280,ADAFRUIT mini GPSpa 1010d , 
//début:20/02/25
//*******************NOTES***********************

//*****************librairies********************
#include <Wire.h>

#include <SPI.h> // va avec lora
#include <LoRa.h> 

#include <MPU.h>
#include <MINIGPS.h>
#include <BMP280.h>

//*****************CONSTANTE*********************
#define ss 5 // pin chip select
#define rst 14 // pin reset
#define dio0 2

//****************OBJETS*************************



//*****************VARIABLES*********************
int counter = 0;

//*****************SETUP*********************
void setup() {
  Serial.begin(115200);  // initialisation du port série
  while (!Serial);

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

 init_MPU();
 init_GPS();
 init_BMP();

}
//*****************FONCTIONS*****************






void loop() { //*****************LOOP*********************

//*****AFFICHAGE SUR PORT SERIE

// LECTURE DES DONNEES DU MPU9250

// LECTURE DES DONNEES DU GPS
mesure_GPS();
 // LECTURE DES DONNEES DU BMP280
mesure_BMP();

 // AFFICHAGE DES DONNEES DU MPU9250
mesure_MPU();

 // AFFICHAGE DES DONNEES DU GPS
 affichage_GPS();
// ENVOIS PAR LoRa

  LoRa.print("packet: ");
    LoRa.println(counter);

  LoRa.beginPacket();
 // AFFICHAGE DES DONNEES DU GPS
  LoRa.print("Satellites detected: ");
  LoRa.println(GPS.satellites);  // affichage du nombre de sattelites

  if (GPS.fix) {  // affichage des autres données GPS si elles sont disponibles

    LoRa.println("GPS Data:");// affichage lattitude
    LoRa.print("  Latitude: ");
    LoRa.print(GPS.latitude, 4);
    LoRa.print(GPS.lat);
    LoRa.print("  Longitude: ");
    LoRa.print(GPS.longitude, 4);
    LoRa.println(GPS.lon);
    LoRa.printf("Sattelites: %02d \n", GPS.satellites); // affichage des satellites
    LoRa.printf("Altitude: %.2f meters \n", GPS.altitude);// affichage de l'altitude
    LoRa.printf("Speed: %.2f knots \n", GPS.speed);// affichage de la vitesse
    LoRa.printf("Course: %.2f degrees \n", GPS.angle);
    LoRa.printf("Date: %02d / %02d / %02d \n", GPS.day, GPS.month, GPS.year);// affichage de la date
    LoRa.printf("Time: %02d:%02d:%02d \n", GPS.hour, GPS.minute, GPS.seconds);//affichage de l'heure
  }
   else 
  {
   LoRa.println("Waiting for GPS fix...");// affiché si ne trouve pas de sattelite
  }
  // AFFICHAGE DES VALEURS DU BMP280
  LoRa.printf(" Température : %.2f °C \n", temperature );// affichage température
  LoRa.printf(" Pression : %.2f hPa \n", pression);// affichage de la pression atmosphérique
  LoRa.printf(" Altitude estimée : %.2f m \n", altitude);// affichage de l'altitude
  LoRa.println("----------------------");//segmentation des infos ,inutile juste pour mieux visualiser

  LoRa.endPacket(true); // true = async / non-blocking mode

  counter++;


  delay(1000);  // Pause de 1 secondes entre chaque lecture
}
