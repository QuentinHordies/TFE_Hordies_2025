#ifndef TFE_Hordies_2025_H
 # define TFE_Hordies_2025_H

extern int counter ;

// carte sd
#include <SdFat.h>//2.3.0
#include <ArduinoJson.h>  //7.3.0


#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <MPU9250.h>
#include <Adafruit_GPS.h>
#include <LoRa.h> 
#include <RPM.h>

#include "MPU.h"
#include "MINIGPS.h"
#include "BMP280.h"
#include "LoRa_tfe.h"
#include "RPM.h"
//#include "CARTE_SD.h"



void delay_second(int secondes);


 #endif