#include "ds18b20.h"
#include <stdio.h>

static int g_ds18b20_initialized = 0;
static int g_resolution_bits = 12; // default

int ds18b20_init(void) {
    printf("[DS18B20] init...\n");
    g_ds18b20_initialized = 1;
    return 0;
}

float ds18b20_read_temp(void) {
    if(!g_ds18b20_initialized) {
        fprintf(stderr, "[DS18B20] Not initialized!\n");
        return -999.9f;
    }
    // Valeur fictive
    float temp = 25.3f;
    if(g_resolution_bits == 9) temp += 0.1f; // Juste un exemple
    return temp;
}

int ds18b20_set_resolution(int bits) {
    if(bits < 9 || bits > 12) {
        fprintf(stderr, "[DS18B20] invalid resolution\n");
        return -1;
    }
    g_resolution_bits = bits;
    return 0;
}
