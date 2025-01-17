#include "fsr402.h"
#include <stdio.h>
#include <math.h>

static int g_fsr402_inited = 0;
static int g_fsr402_sensitivity = 1;

int fsr402_init(void) {
    g_fsr402_inited = 1;
    return 0;
}

float fsr402_read_force(void) {
    if(!g_fsr402_inited) {
        fprintf(stderr, "[FSR402] not initialized!\n");
        return -1.0f;
    }
    // Valeur fictive
    int analog_val = 300;
    float voltage = (3.3f * analog_val) / 1024.0f;
    float force = voltage * 10.0f * g_fsr402_sensitivity;
    return force;
}

int fsr402_configure(int sensitivity) {
    if(sensitivity < 1 || sensitivity > 5) {
        return -1;
    }
    g_fsr402_sensitivity = sensitivity;
    return 0;
}
