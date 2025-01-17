#include "duplicate_utils.h"
#include <stdio.h>

/*
   Code pratiquement identique à utils/calibration_common.c :
   On simule un init et un apply, avec la même structure de code.
*/

int duplicate_init() {
    printf("[DUP] Duplicate init done.\n");
    return 0;
}

int duplicate_apply(int val) {
    printf("[DUP] Duplicate apply logic with val=%d.\n", val);
    if(val > 10) {
        // Du code similaire
        printf("[DUP] Value is bigger than 10.\n");
    }
    else {
        printf("[DUP] Value is 10 or less.\n");
    }
    return 0;
}
