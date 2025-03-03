#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

int init_BMP(void)
{

  Serial.println(" BMP280");
  if (!bmp.begin(0x77)) {// définition de l'adresse du BMP280
    Serial.println(" échec démarage BMP280 ");
    while (1);
  }
  Serial.println(" initialisation BMP280 OK");

  // Configuration du capteur BMP280
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,      // Mode normal
                  Adafruit_BMP280::SAMPLING_X2,      // Suréchantillonnage x2 pour la température
                  Adafruit_BMP280::SAMPLING_X16,     // Suréchantillonnage x16 pour la pression
                  Adafruit_BMP280::FILTER_X16,       // Filtrage x16
                  Adafruit_BMP280::STANDBY_MS_500);  // Temps de repos de 500ms

}

int mesure_BMP(void)
{
  float temperature = bmp.readTemperature();
  float pression = bmp.readPressure() / 100.0F;  // Convertir en hPa
  float altitude = bmp.readAltitude(1013.25);    // 1013.25 hPa = pression moyenne au niveau de la mer
}

int affichage_BMP(void)
{

}