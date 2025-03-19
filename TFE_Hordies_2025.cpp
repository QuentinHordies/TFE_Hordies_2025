#include "TFE_Hordies_2025.h"

void delay_second(int secondes){

  delay (1000*secondes);
}

void mesures (void)
{
 mesure_GPS();
 mesure_BMP(); 
 //mesure_MPU();
}

void affichage (void)
{
 affichage_GPS();
 affichage_BMP();
 //affichage_MPU();

}


