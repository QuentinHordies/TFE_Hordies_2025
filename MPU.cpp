
#include "MPU.h"

MPU9250 mpu;

int init_MPU(char MPU_adr) //********INITIALISATION
{
  int state_MPU;

  if (!mpu.setup( MPU_adr)) 
  {   
   state_MPU =1;// echec init
  }
  else
  { 
   state_MPU =0;// réussite init
  }
  return state_MPU;
}

void etat_MPU(char MPU_adresse)
{
 if (init_MPU( MPU_adresse) ==1)
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


