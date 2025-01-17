#include "sensor_manager.h"
#include "../libs/driver_accel/adxl345.h"
#include "../libs/driver_force/fsr402.h"
#include "../libs/driver_temp/ds18b20.h"
#include <stdio.h>

static adxl345_data_t g_accel_data;
static float g_force_val;
static float g_temp_val;

int sensor_manager_init(void) {
    if(adxl345_init() < 0) {
        return -1;
    }
    fsr402_init();
    ds18b20_init();
    adxl345_configure_range(8);
    fsr402_configure(2);
    ds18b20_set_resolution(12);
    return 0;
}

int sensor_manager_update(void) {
    if(adxl345_read_accel(&g_accel_data) == 0) {
        printf("[SENSOR] Accel => X:%d Y:%d Z:%d\n",
            g_accel_data.accel_x, g_accel_data.accel_y, g_accel_data.accel_z);
    }
    g_force_val = fsr402_read_force();
    g_temp_val  = ds18b20_read_temp();

    printf("[SENSOR] Force => %.2f N, Temp => %.2f C\n", g_force_val, g_temp_val);
    return 0;
}

adxl345_data_t sensor_manager_get_accel(void) {
    return g_accel_data;
}

float sensor_manager_get_force(void) {
    return g_force_val;
}

float sensor_manager_get_temp(void) {
    return g_temp_val;
}
