
#include "MPU.h"

MPU9250 mpu;

int init_MPU(const byte adresse_MPU) //********INITIALISATION
{
   int state_MPU;

  if (!mpu.setup(adresse_MPU)) {  // adresse a verifier 0x68
      //Serial.println("echec démarage MPU9250");
      //while (1) ;      
        state_MPU =1;
    }
  Serial.println(" initialisation MPU9250 OK");
   state_MPU =0;
   return state_MPU;

   etat_MPU();
}

void etat_MPU(void)
{
 if (init_MPU(adresse_MPU) ==1)
 {
  Serial.println("échec démarage MPU ");
 }
 else 
 {
  Serial.println(" initialisation MPU OK");
 }

}

int mesure_MPU(void)//**********MESURE
{
  if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            affichage_MPU();
            prev_ms = millis();
        }
    } 
    
}


void affichage_MPU(void)//**********AFFICHAGE
{
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(mpu.getYaw(), 2); //gauche droite
    Serial.print(", ");
    Serial.print(mpu.getPitch(), 2);// haut bas
    Serial.print(", ");
    Serial.println(mpu.getRoll(), 2);//tonneau
   
}


