# HARDWARE_PI2

Ce projet a pour objectif de réaliser un système embarqué de mesure de paramètres de musculation 
(accélération des mouvements, forces exercées) sur une machine de musculation.

- **Raspberry Pi 4** : interagit via un script C/C++ pour la gestion des données, le stockage local 
  et la communication réseau.
- **ESP32** : effectue l'acquisition bas-niveau des capteurs (accéléromètre ADXL345 et capteur de force FSR 402), 
  puis communique ces données vers la Raspberry Pi via UART ou Wi-Fi (selon configuration).
- **Accéléromètre ADXL345** : lecture I2C (ou SPI) pour récupérer l’accélération sur 3 axes.
- **Capteur de force FSR 402** : mesure la pression exercée, transformée en force approximative.
- Une portion de code d'assembleur a également été intégrée pour le bootloader ESP32 et une routine 
  de clignotement de LED sur Raspberry Pi 4 (juste à titre d’exemple).

## Installation

1. Cloner le repo : 
