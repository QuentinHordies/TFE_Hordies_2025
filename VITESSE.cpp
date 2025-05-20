#include "VITESSE.h"

 float vitesse_kmh =0;

 const int pinCapteur = 33;
 const float circonference_m = 2.1;  // longueur d’un tour de roue en mètres
 unsigned long dernier_top ;

void determiner_vitesse() {
 unsigned long maintenant = millis();
  unsigned long temps_ecoule = maintenant - dernier_top;

  if (temps_ecoule > 50) { // Anti-rebond (50 ms mini entre deux tops)
    float temps_sec = temps_ecoule / 1000.0; // conversion en secondes
    float vitesse_ms = circonference_m / temps_sec; // en m/s
    vitesse_kmh = vitesse_ms * 3.6; // en km/h
    dernier_top = maintenant;

  }
}

void init_VITESSE() {
  pinMode(pinCapteur, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinCapteur), determiner_vitesse, FALLING);
}


 /*
 unsigned long contact_end=0;
 unsigned long contact_begin=0;
 int indicateur_vitesse=0 ;
 int temps_tour_roue=0;
 */

/*
#include "VITESSE.h"

 float vitesse_kmh =0;

volatile int impulsions = 0;
unsigned long lastMillis = 0;
const int interval = 1000; // ms

void incrementerImpulsions() {
  impulsions++;
}

void init_VITESSE() {

  pinMode(pinCapteur, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinCapteur), incrementerImpulsions, FALLING);
}

void lecture_VITESSE() {
  unsigned long maintenant = millis();
  if (maintenant - lastMillis >= interval) {
    lastMillis = maintenant;

    float tours = impulsions / (float)impulsionsParTour;
    float circonference = PI * diametreRoue;
    float vitesse_ms = (tours * circonference) / (interval / 1000.0); // m/s
    float vitesse_kmh = vitesse_ms * 3.6;

    Serial.print("Vitesse : ");
    Serial.print(vitesse_kmh);
    Serial.println(" km/h");

    impulsions = 0; // Reset pour la prochaine seconde
  }
}
*/
