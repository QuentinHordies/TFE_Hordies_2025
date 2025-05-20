#include "RPM.h"

unsigned int rpm = 0;

const int hallPin = 32;                 // Capteur Hall branché ici
volatile unsigned long pulseCount = 0;  // Compteur d’impulsions
unsigned long lastMeasure = 0;

void IRAM_ATTR countPulse() {
  pulseCount++;  // Incrémente à chaque impulsion (interruption)
}

void init_RPM() 
{
  Serial.begin(115200);
  pinMode(hallPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(hallPin), countPulse, FALLING);
}

void lecture_RPM() {
  if (millis() - lastMeasure >= 1000) { // Toutes les secondes
    noInterrupts();                     // On bloque pendant la lecture
    unsigned long count = pulseCount;
    pulseCount = 0;
    interrupts();

    rpm = count * 60;                  // Conversion en tours/min
    Serial.print("RPM: ");
    Serial.println(rpm);

    lastMeasure = millis();           // On redémarre le chrono
  }

}


