
#include "MPU.h"

MPU9250 mpu;

int init_MPU(void) //********INITIALISATION
{

  Wire.begin();
    delay(500);

  if (!mpu.setup(0x68)) {  // adresse a verifier
      Serial.println("echec démarage MPU9250");
      while (1) ;      
        
    }
  Serial.println(" initialisation MPU9250 OK");
}

int mesure_MPU(void)//**********MESURE
{
  if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            print_roll_pitch_yaw();
            prev_ms = millis();
        }
    } 
}

int affichage_MPU(void)//**********AFFICHAGE
{
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(mpu.getYaw(), 2);
    Serial.print(", ");
    Serial.print(mpu.getPitch(), 2);
    Serial.print(", ");
    Serial.println(mpu.getRoll(), 2);
   
}
