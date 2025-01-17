#include "adxl345.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int g_adxl345_init_done = 0;

int adxl345_init(void) {
    g_adxl345_init_done = 1;
    return 0;
}

int adxl345_read_accel(adxl345_data_t* data) {
    if (!g_adxl345_init_done) {
        fprintf(stderr, "[ADXL345] Not initialized!\n");
        return -1;
    }
    if (data == NULL) {
        return -2;
    }
    // Valeurs factices
    data->accel_x = 100;
    data->accel_y = -50;
    data->accel_z = 200;
    return 0;
}

int adxl345_configure_range(int range) {
    if(range != 2 && range != 4 && range != 8 && range != 16) {
        fprintf(stderr, "[ADXL345] Invalid range: %d\n", range);
        return -1;
    }
    return 0;
}

int adxl345_self_test(void) {
    // Code minimal
    if (!g_adxl345_init_done) return -1;
    printf("[ADXL345] Self-test performed.\n");
    return 0;
}
