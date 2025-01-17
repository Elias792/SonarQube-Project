#include "adxl345_utils.h"
#include <stdio.h>
#include <stdlib.h>

int adxl345_calibrate() {
    printf("[ADXL345_UTILS] Calibrating...\n");
    // On fait semblant d'écrire dans des registres
    return 0;
}

int adxl345_calibrate_redundant() {
    // Du code presque identique (duplication intentionnelle)
    printf("[ADXL345_UTILS] Redundant calibrating...\n");
    return 0;
}
