#include <Adafruit_GPS.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>

Adafruit_GPS GPS(&Wire);
Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(115200);  // initialisation du port série
  while (!Serial);

  Serial.println("Initialisation du GPS...");
  if (!GPS.begin(0x10)) {// définition de l'adresse du GPS
    Serial.println("Could not find GPS on I2C at address 0x10. Check connections!");
    while (1);
  }
  Serial.println(" GPS initié avec succès !");

  Serial.println("Initialisation du capteur BMP280...");
  if (!bmp.begin(0x77)) {// définition de l'adresse du BMP280
    Serial.println(" Impossible de détecter le BMP280. Vérifiez les connexions !");
    while (1);
  }
  Serial.println(" BMP280 initié avec succès !");
// j'aime le poulet
  //configuration du GPS
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);  // fréquence de mise a jour du GPS 1Hz
  GPS.sendCommand(PMTK_API_SET_FIX_CTL_1HZ);

  // Configuration du capteur BMP280
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,      // Mode normal
                  Adafruit_BMP280::SAMPLING_X2,      // Suréchantillonnage x2 pour la température
                  Adafruit_BMP280::SAMPLING_X16,     // Suréchantillonnage x16 pour la pression
                  Adafruit_BMP280::FILTER_X16,       // Filtrage x16
                  Adafruit_BMP280::STANDBY_MS_500);  // Temps de repos de 500ms
}

void loop() {

 // LECTURE DES DONNEES DU GPS
  GPS.read();  
  if (GPS.newNMEAreceived()) { //si de nouvelles données sont reçu
    if (!GPS.parse(GPS.lastNMEA())) {  // analyse du NMEA reçue
      return;                          // erreur d'analyse
    }
  }
 // LECTURE DES DONNEES DU BMP280
  float temperature = bmp.readTemperature();
  float pression = bmp.readPressure() / 100.0F;  // Convertir en hPa
  float altitude = bmp.readAltitude(1013.25);    // 1013.25 hPa = pression moyenne au niveau de la mer

 // AFFICHAGE DES DONNEES DU GPS
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
  // AFFICHAGE DES VALEURS DU BMP280
  Serial.printf(" Température : %.2f °C \n", temperature );// affichage température
  Serial.printf(" Pression : %.2f hPa \n", pression);// affichage de la pression atmosphérique
  Serial.printf(" Altitude estimée : %.2f m \n", altitude);// affichage de l'altitude
  Serial.println("----------------------");//segmentation des infos ,inutile juste pour mieux visualiser

  delay(1000);  // Pause de 1 secondes entre chaque lecture
}
