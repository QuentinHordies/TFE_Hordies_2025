
#include <SPI.h> // va avec lora
#include <LoRa.h> 
#include "LoRa_tfe.h"
#include "MPU.h"
#include "MINIGPS.h"
#include "BMP280.h"

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

int affichage_LoRa_BMP280 (void)
{
  LoRa.printf(" Température : %.2f °C \n", temperature );// affichage température
  LoRa.printf(" Pression : %.2f hPa \n", pression);// affichage de la pression atmosphérique
  LoRa.printf(" Altitude estimée : %.2f m \n", altitude);// affichage de l'altitude
  LoRa.println("----------------------");//segmentation des infos ,inutile juste pour mieux visualiser
}

int affichage_LoRa_GPS (void)
{
LoRa.print("Satellites detected: "); // AFFICHAGE DES DONNEES DU GPS
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

}

int affichage_LoRa_packet (void)
{
  LoRa.print("packet: "); // ENVOIS PAR LoRa
  LoRa.println(counter);
  counter++;
}

int LoRa_beginPacket (void)
{
  LoRa.beginPacket();
}

int LoRa_endPacket (void)
{
  LoRa.endPacket(true); // true = async / non-blocking mode
}