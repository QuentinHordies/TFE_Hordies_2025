
#include "MINIGPS.h"

void init_ECRAN() {


  Serial1.begin(9600, SERIAL_8N1, 16, 17);
  nextion.begin(9600);  // TX = 17, RX = 16 (à adapter selon ton câblage)
}

void affichage_ECRAN(int rpm_calcule) {
  // Conversion : suppose que 8000 RPM = 100% de la jauge
  int progressValue = map(rpm_calcule, 0, 8000, 0, 100);  // À adapter selon ton moteur et jauge

  // Envoie la commande au Nextion pour mettre à jour la jauge j0
  nextion.print("j0.val=");
  nextion.print(progressValue);
  nextion.write(0xFF);
  nextion.write(0xFF);
  nextion.write(0xFF);

}
