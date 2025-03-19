
#include "CARTE_SD.h"

SdFat sd;

/*   // carte SD cansat25
File logFile;
char fileName[32] = "";  // Tableau de caractères pour stocker le nom du fichier
bool loggingActive = false;
bool firstPacket = true;  // Indique si c'est le premier paquet
bool logInSD=true;


#define CS_PIN 15  // Broche CS pour la carte SD

// Détection automatique de la carte
#if defined(DOIT_ESP32_DEVKIT_1)  // Détection correcte de l'ESP32
    #define USE_DYNAMIC_JSON
#else
    #warning "Carte inconnue, utilisation de StaticJsonDocument par défaut"
    #define USE_STATIC_JSON  // Par défaut, on utilise StaticJsonDocument

// 📌 Vérifie si la carte SD est insérée et initialisée
int checkSDCard(bool verbose) 
    {
    if (!sd.begin(CS_PIN, SD_SCK_MHZ(8))) {
        if (verbose) Serial.println("❌ Carte SD absente ou non initialisée !");
        loggingActive = false;
       // deviceStatus |= idSDcard;  // Met à 1 le bit ICM (flag erreur)
       // return idSDcard; 
    }
    if (verbose) Serial.println("✅ Carte SD initialisée !");
       // deviceStatus &= ~idSDcard; // Met à zéro le bit ICM (flag OK)
        loggingActive = true;
    return 0;
}

// 📌 Ferme le fichier proprement en ajoutant la fin du tableau JSON
void closeLogFile() 
{
  if (!loggingActive) return;
    if (checkSDCard(false)) return;

    logFile = sd.open(fileName, FILE_WRITE);
    if (!logFile) {
        Serial.println("❌ Erreur : impossible de fermer le fichier !");
        return;
    }

    logFile.flush();
    logFile.close();
    
    Serial.println("✅ Fichier fermé proprement.");
    loggingActive = false;
}

// 📌 Crée un nouveau fichier pour les logs
void createNewLogFile() 
{   
    if((deviceStatus & idSDcard)) return;
    closeLogFile();  // Ferme le fichier précédent si ouvert
    if (checkSDCard(false)) return;

    // Génère le nom du fichier en fonction de l'heure RTC ou GPS
    if (!GetDataRtc(deviceStatus & idRTC)) 
    {
        snprintf(fileName, sizeof(fileName), "%s.json", filenamertc);
    } else if (!GetDataGPS(deviceStatus & idGPS))
    {
        snprintf(fileName, sizeof(fileName), "%s.json", filenamegps);
    } 
    else 
    {
        snprintf(fileName, sizeof(fileName), "25xxxx.json");  // Nom par défaut
    }
    
    logFile = sd.open(fileName, FILE_WRITE);// Crée le nouveau fichier
    if (logFile) 
    {
        Serial.printf("✅ Nouveau fichier : %s\n", fileName);
        loggingActive = true;
        firstPacket = true;  // Réinitialise le drapeau du premier paquet
    } 
    else 
    {
        Serial.println("❌ Erreur : impossible de créer le fichier !");
        loggingActive = false;
    }
}

// 📌 Écrit des données JSON dans le fichier
bool writeLogData(String payload) 
{
    
    if (checkSDCard(false)) 
      {
        //Serial.println("❌ Erreur : SD-Card Check connections!"); 
        return false;
      }
    if (!loggingActive) return false;
    logFile = sd.open(fileName, FILE_WRITE);
    if (!logFile) {
        Serial.println("❌ Erreur : impossible d'ouvrir le fichier !\n");
        return false;
    }

    long fileSize = logFile.size();
    if (fileSize == 0) {
        // Si le fichier est vide, on initialise le tableau JSON
        logFile.print("[");
    } else {
        // Lire le dernier caractère du fichier
        logFile.seekEnd(-1);
        char lastChar = logFile.read();

        if (lastChar == ']') {
            logFile.seekEnd(-1);  // Supprime le `]`
            logFile.print(",");    // Ajoute une virgule pour séparer les entrées
        }
    }

    logFile.print(payload);  // Ajoute la nouvelle entrée JSON
    logFile.print("]");      // Referme toujours le tableau JSON
    logFile.flush();
    logFile.close();
    deviceStatus &= ~idSDcard; // Met à zéro le bit ICM (flag OK)
    Serial.printf("✅ Donnée enregistrée -> RTC time : %02d:%02d:%02d\n", rtc_hour, rtc_minute, rtc_second);
    return true;
}
*/







