
#include "MPU.h"

MPU9250 mpu;

  float yaw;
  float pitch;
  float roll;
  byte status_MPU =1;

int init_MPU(char MPU_adr) //********INITIALISATION
{
  if (!mpu.setup( MPU_adr)) 
  {   
   status_MPU =1;// echec init
  }
  else
  { 
   status_MPU =0;// réussite init
  }
  return status_MPU;
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

yaw= mpu.getYaw();
pitch = mpu.getPitch();
roll= mpu.getRoll();


  /*
  if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            affichage_MPU();
            prev_ms = millis();
        }
    } 
  */
}


void affichage_MPU(void)//**********AFFICHAGE
{

 Serial.printf(" Roulis : %.2f °C \n", yaw );// gauche droite
 Serial.printf(" Tangage : %.2f °C \n", pitch );// haut bas
 Serial.printf(" Lacet : %.2f °C \n", roll );// tonneau


  /*
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(mpu.getYaw(), 2); //gauche droite
    Serial.print(", ");
    Serial.print(mpu.getPitch(), 2);// haut bas
    Serial.print(", ");
    Serial.println(mpu.getRoll(), 2);//tonneau
   */
}

void lecture_MPU(void)
{
 if(status_MPU ==0)
 {
  mesure_MPU();
  affichage_MPU();
 }
}
