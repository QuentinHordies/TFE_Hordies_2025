#ifndef TFE_Hordies_2025_H
 # define TFE_Hordies_2025_H

extern int counter ;
extern unsigned int rpm;
extern float vitesse_kmh;

// carte sd
#include <SdFat.h>//2.3.0
#include <ArduinoJson.h>  //7.3.0


#include <Wire.h> //
#include <SPI.h> //
#include <Adafruit_BMP280.h> // Adafruit BMP280 Library by Adafruit 2.6.8
#include <MPU9250.h> // MPU9250 by hideakitai 0.4.8
#include <Adafruit_GPS.h> // Adafruit GPS Library by Adafruit 1.7.5
#include <LoRa.h>  // LoRa by Sandeep Mistry 0.8.0
// #include <RPM.h> //
#include <Arduino.h>//ecran


#include "MPU.h"
#include "MINIGPS.h"
#include "BMP280.h"
#include "LoRa_tfe.h"
#include "RPM.h"
#include "ECRAN.h"
#include "VITESSE.h"
//#include "CARTE_SD.h"

void delay_second(int secondes);


 #endif