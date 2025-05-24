#include "VITESSE.h" // avec l'aide de ChatGPT

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

