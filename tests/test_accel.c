#include <stdio.h>
#include "../libs/driver_accel/adxl345.h"
#include "../libs/driver_accel/adxl345_utils.h"

int main(void) {
    if(adxl345_init() != 0) {
        printf("[TEST] ADXL345 init failed!\n");
        return -1;
    }
    adxl345_data_t data;
    if(adxl345_read_accel(&data) == 0) {
        printf("[TEST] Accel => X:%d Y:%d Z:%d\n", data.accel_x, data.accel_y, data.accel_z);
    }
    adxl345_calibrate();
    adxl345_calibrate_redundant();
    return 0;
}
