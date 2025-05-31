[How-to-order-PCB.txt](https://github.com/user-attachments/files/20533355/How-to-order-PCB.txt)Système de mesures et d'affichage d'un kart

# Projet en cours de réalisation par : 
- **Nom,Prénom :** Hordies Quentin
- **Ecole :** étudiant a l' INRACI
- **Annee :** 6 eme tq électronique
- **Promoteur :** Mr Kapita

# Sommaire :
- [Définition du projet](#Définition-du-projet)
- [Liste des composants](#Liste-des-composants)
- [Les caractéristiques](#Les-caractéristiques)
- [Schéma de bloc](#Le-schéma-bloc)
- [Schéma de principe](#Schéma-de-principe)
- [le PCB](#le-PCB)
- [Ordinogramme](#Ordinogramme)
- [3D](#3D)
- [Bibliothèques nécessaires](#Bibliothèques-nécessaires)
- [Sources](#Sources)

# Définition du projet :

Le principe de mon TFE est d’utiliser une batterie de capteurs brancher au véhicules et d’ensuite traiter les donner récupérées afin de l’afficher au pilote sur un écran fixé à son volant, en parallèle les données seront envoyées à un pc via un système Lora qui, couplé à une antenne, aura une portée d’environ 10Km. 

J’utilise : un capteur inductif qui accompagné d'une roue entourée d’aimant pourra donner le nombre de rotation de celle-ci et ainsi permettre d’en déduire la vitesse du kart ,1 autre capteur inductif attaché à la bobine (ou à la bougie) qui me donnera les RPM du moteur ,deux capteurs de températures (un pour l’huile, et 1 pour la température du moteur) , un système GPS pour avoir la position du kart a tout moment ,un BMP280 pour connaitre l'altitude et pour finir un mpu9250 qui me fournira les différentes accélérations lors des mouvements du véhicule. 

Tous ces capteurs seront interchangeables et n'auront pas de place définie ce qui permettra une plus grande modularité ainsi qu’un risque de commettre des erreurs diminuer. 

# Liste des omposants :

* ESP32
* MPU9250
* BMP280
* ADAFRUIT mini GPS pa1010d 
* capteur a effet hall KY-003
* capteur inductif
* lecteur de carte SD MSD-7-A

# Caractéristique générale:

## Général :

* Station de mesure des données d’un kart et de transmission de données sans fil 

* Écran Nextion 3,5” avec connecteur pour branchement au boîtier 

* Capteur de régime moteur (RPM) externe 

* Capteur de vitesse externe 

## Electronique :

* 1x GPS, sensibilité :  -165 dBm  

* 1x accéléromètre/gyromètre  

* 1x thermomètre, -40 à 85°C, ± 1°C 

*1x baromètre, 300 a 1100hPa, ±1 hPa 

* 1x lecteur de carte microSD 

* 5x connecteurs RJ45 (pour les capteurs externes) 

* Émetteur LoRa avec Antenne 433MHz, >1 Km de porté 

## Mécanique :

* L140 x l 101 x h 40 mm 

* Face avant et arrière imprimées en 3D avec du PLA 

* Plaque de base et latérales découpées dans de l’ABS de 3 mm 

* Face supérieur découpée dans du plexiglass de 3 mm 

* Support anti-vibration en dessous du boitier 

* Capteur à effet Hall avec support imprimé en 3D avec du PLA et avec un câble de 2,50 m 

* Capteur inductif avec support imprimé en 3D avec du PLA et roue fixée sur l’axe de rotation des roues du kart et un câble de 1,50 m 

* Support d’écran pour le volant du kart imprimé en 3D en PLA avec câble de 3 m  

* PCB = 95x125 mm 


# Schéma bloc :
## Schéma :
![schema_bloc_tfe](https://github.com/user-attachments/assets/d5ea8f93-70b2-4856-8670-0e0002b1ba1c)


## explications

* ESP32 : microcontrôleur qui gère la réception des données, leur traitement, ainsi que l’affichage. 

* Baromètre / Thermomètre : permet de mesurer l’altitude et la température du véhicule. 

* GPS : permet d’obtenir la position GPS du véhicule. 

* Gyromètre / Accéléromètre : permet de mesurer l’inclinaison et la force appliquée sur le véhicule. 

* LoRa : permet d’envoyer les données du boîtier vers un ordinateur externe par ondes radio. 

* Capteur de vitesse : capteur externe qui permet de calculer la vitesse du kart. 

* Capteur de RPM : capteur externe qui mesure le nombre de tours par minute du moteur. 

* M5Stack : microcontrôleur qui gère uniquement le récepteur LoRa et fait le lien avec le PC. 

* Écran : permet d’afficher les informations utiles (vitesse et RPM dans mon cas) au pilote. 

* Carte SD : permet de stocker les données recueillies. 


# Schéma de principe :

## Avec bornier :
![Schematic_tfe-3_2025-05-25](https://github.com/user-attachments/assets/d6afc564-cd08-464f-86fa-488744d71397)

## Sans bornier :
![Schematic_schéma-tfe-sans-connecteur_2025-05-25](https://github.com/user-attachments/assets/317248a9-d3a4-4712-8aa3-22eccb1ef7bf)

# PCB : 
![PCB_PCB_tfe-3_2025-05-24](https://github.com/user-attachments/assets/7efe2e0b-2c54-4392-a998-0235023a358a)
![PCB_PCB_tfe-3_2025-05-25 (2)](https://github.com/user-attachments/assets/6acaccaa-88e2-4d1c-960e-69a1e8b3d095)
![PCB_PCB_tfe-3_2025-05-25 (3)](https://github.com/user-attachments/assets/ff181334-5df8-4db9-829c-75c55dc06d3a)

## gerber : 
[Upl[Uploading Drill_NPTH_Through.DRL…]()oading How-to-order-PCB.txt…]()

# Ordinogramme
![ordinogramme_TFE drawio](https://github.com/user-attachments/assets/4a0fea33-a250-4fb4-83b8-3d964d151ec4)

# Plans 3D :

![Capture d'écran 2025-05-24 172450](https://github.com/user-attachments/assets/4a7dee53-469a-41eb-9686-b25ffe5682e9)

![Capture d'écran 2025-05-24 172505](https://github.com/user-attachments/assets/ede9b11d-d925-430e-94c0-2644ca085b9f)

![Capture d'écran 2025-05-25 172518](https://github.com/user-attachments/assets/5e738b44-f4f2-494e-b1f4-517c273d0f55)
![Capture d'écran 2025-05-25 172458](https://github.com/user-attachments/assets/8a235d12-590e-4280-a529-a828a31826cd)

# Bibliothèques nécessaires
* Adafruit BMP280 Library by Adafruit 2.6.8
* MPU9250 by hideakitai 0.4.8
* Adafruit GPS Library by Adafruit 1.7.5
* LoRa by Sandeep Mistry 0.8.0

# Sources

L'ensemble des datasheets, dont les liens se trouvent dans un chapitre dédié. 

## L'ensemble des livres d’électronique et d’informatique de Monsieur Mazzeo : 

* Electronique 1,2 et 3 ,5èmeEo édition 2018 par R.Mazzeo 

* Informatique Embarqué 5èmeEo édition 2023 par R.Mazzeo 

* Informatique Embarqué 6èmeEo édition 2024 par R.Mazzeo 

## L'ensemble de tous les cours donnés à l’INRACI : 

* Le cours de mathématique de 6ème par Monsieur Senga 

* Le cours de C.P de 6ème par Monsieur Pochet 

* Le cours d’électronique de 6ème par Monsieur Pochet 

## GPS (tous reconsulté le 20/05/2025) : 

https://www.schoolmouv.fr/cours/geolocalisation/fiche-de-cours 

https://fr.wikipedia.org/wiki/Global_Positioning_System 

https://fr.wikipedia.org/wiki/Horloge_atomique 

https://gisgeography.com/trilateration-triangulation-gps/ 

https://www.bateaux.com/article/22398/comprendre-fonctionne-gps 

https://fr.wikipedia.org/wiki/Global_Positioning_System#Principe_de_fonctionnement 

## ESP32 (25/05/2025) : 

https://fr.wikipedia.org/wiki/ESP32 

## LoRa (26/05/2025) : 

https://fr.wikipedia.org/wiki/LoRaWAN 

https://www.tactis.fr/iot-lora/  

## Écran Nextion (17/03/2025) : 

https://nextion.tech/instruction-set/ 
