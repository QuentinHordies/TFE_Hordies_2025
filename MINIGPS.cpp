
#include "MINIGPS.h"

Adafruit_GPS GPS(&Wire);

int init_GPS(void)
{
  int state_GPS ;

  Serial.println("GPS");
  if (!GPS.begin(0x10)) {// définition de l'adresse du GPS
    //Serial.println("échec démarage GPS ");
    state_GPS =1;
    while (1);
  }
  //Serial.println(" initialisation GPS OK");
   state_GPS =0;
    //configuration du GPS
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);  // fréquence de mise a jour du GPS 1Hz
  GPS.sendCommand(PMTK_API_SET_FIX_CTL_1HZ);

return state_GPS;
}

void etat_GPS(void)
{
 if (init_GPS() ==1)
 {
  Serial.println("échec démarage GPS ");
 }
 else 
 {
  Serial.println(" initialisation GPS OK");
 }

}

void mesure_GPS(void)
{
  GPS.read();  
  if (GPS.newNMEAreceived()) { //si de nouvelles données sont reçu
    if (!GPS.parse(GPS.lastNMEA())) {  // analyse du NMEA reçue
      Serial.println("erreur d'analyse");                          // erreur d'analyse
    }
  }
}

void affichage_GPS(void)
{
 Serial.print("Satellites detected: ");
 Serial.println(GPS.satellites);  // affichage du nombre de sattelites

  if (GPS.fix) {  // affichage des autres données GPS si elles sont disponibles

    Serial.println("GPS Data:");// affichage lattitude
    Serial.print("  Latitude: ");
    Serial.print(GPS.latitude, 4);
    Serial.print(GPS.lat);
    Serial.print("  Longitude: ");
    Serial.print(GPS.longitude, 4);
    Serial.println(GPS.lon);
    Serial.printf("Sattelites: %02d \n", GPS.satellites); // affichage des satellites
    Serial.printf("Altitude: %.2f meters \n", GPS.altitude);// affichage de l'altitude
    Serial.printf("Speed: %.2f knots \n", GPS.speed);// affichage de la vitesse
    Serial.printf("Course: %.2f degrees \n", GPS.angle);
    Serial.printf("Date: %02d / %02d / %02d \n", GPS.day, GPS.month, GPS.year);// affichage de la date
    Serial.printf("Time: %02d:%02d:%02d \n", GPS.hour, GPS.minute, GPS.seconds);//affichage de l'heure
  }
   else 
  {
    Serial.println("Waiting for GPS fix...");// affiché si ne trouve pas de sattelite
  }
}