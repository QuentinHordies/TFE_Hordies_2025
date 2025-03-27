/*

unsigned int passage_aimant = 0;
unsigned long Time_ms;
int RPM;
bool flag_aimant;

#define NOMBRE_AIMANT 2
#define LIMITE_SUP 500
#define LIMITE_INF 100
void CAPTEUR_HALL(void)
 {
  if (capteur_1 <= LIMITE_INF) 
  {
    flag_aimant = 1;
    if(capteur_1 >= LIMITE_SUP) 
    {
      flag_aimant = 0;
    }
  }
}

void calcul_RPM(void)
{
  if (flag_aimant) passage_aimant++;
  if (millis() = Time_ms+1000)
  {
    RPM = (passage_aimant*NOMBRE_AIMANT)*60;
    Time_ms = millis();
    passage_aimant = 0;
  }
}

*/