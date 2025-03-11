#ifndef MINI_GPS_H     // Vérifie si  n'a pas encore été défini
  #define MINI_GPS_H
  #include <Adafruit_GPS.h>
int init_GPS(void);
int mesure_GPS(void);
int affichage_GPS(void);

#endif