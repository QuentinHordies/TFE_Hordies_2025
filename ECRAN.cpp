
#include "MINIGPS.h"

void init_ECRAN() {

  Serial1.begin(9600, SERIAL_8N1, 16, 17);
  nextion.begin(9600);  // TX = 17, RX = 16 (à adapter selon ton câblage)
}

void affichage_ECRAN_RPM(int rpm_calcule) {
  // Conversion : suppose que 4000 RPM = 100% de la jauge
  int valeurRPM= map(rpm_calcule, 0, 5000, 0, 100);  // À adapter selon ton moteur et jauge

  // Envoie la commande au Nextion pour mettre à jour la jauge j0
  nextion.print("j0.val=");
  nextion.print(valeurRPM);
  nextion.write(0xFF);
  nextion.write(0xFF);
  nextion.write(0xFF);

}
void affichage_ECRAN_VITESSE(int VITESSE_calcule) {
  // Conversion : suppose que 80Km/h = 100% de la jauge
  int valeurVITESSE= map(VITESSE_calcule, 0, 80, 0, 100);  // À adapter selon ton moteur et jauge

  // Envoie la commande au Nextion pour mettre à jour la jauge z0
  nextion.print("z0.val=");
  nextion.print(valeurVITESSE);
  nextion.write(0xFF);
  nextion.write(0xFF);
  nextion.write(0xFF);

}