
#include "BMP280.h"

Adafruit_BMP280 bmp;

  float temperature;
  float pression;
  float altitude;
  byte status_BMP =1;

  
int init_BMP( char BMP_adr)
{

  if (!bmp.begin(BMP_adr)) // définition de l'adresse du BMP280 0x77
  {
   status_BMP =1;// echec init
  }
  else
  {
  status_BMP =0; // init reussie
  }

  // Configuration du capteur BMP280 Reprise de l'exemple test de la librairie
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,      // Mode normal
                  Adafruit_BMP280::SAMPLING_X2,      // Suréchantillonnage x2 pour la température
                  Adafruit_BMP280::SAMPLING_X16,     // Suréchantillonnage x16 pour la pression
                  Adafruit_BMP280::FILTER_X16,       // Filtrage x16
                  Adafruit_BMP280::STANDBY_MS_500);  // Temps de repos de 500ms

  return status_BMP;

}

void etat_BMP(char BMP_adresse)
{

 if (init_BMP(BMP_adresse) ==1)
 {
  Serial.println("échec démarage BMP ");
 }
 else 
 {
  Serial.println(" initialisation BMP OK");
 }

}

void mesure_BMP(void)
{
  temperature = bmp.readTemperature();
  pression = bmp.readPressure() / 100.0F;  // Convertir en hPa
  altitude = bmp.readAltitude(1013.25);    // 1013.25 hPa = pression moyenne au niveau de la mer

}

void affichage_BMP(void)
{
  Serial.printf(" Température : %.2f °C \n", temperature );// affichage température
  Serial.printf(" Pression : %.2f hPa \n", pression);// affichage de la pression atmosphérique
  Serial.printf(" Altitude estimée : %.2f m \n", altitude);// affichage de l'altitude
  Serial.println("----------------------");//segmentation des infos ,inutile juste pour mieux visualiser
}

void lecture_BMP(void)
{
 if(status_BMP ==0)
 {
  mesure_BMP();
  affichage_BMP();
 }
}