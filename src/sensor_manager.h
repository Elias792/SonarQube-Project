#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../libs/driver_accel/adxl345.h"

int sensor_manager_init(void);
int sensor_manager_update(void);

adxl345_data_t sensor_manager_get_accel(void);
float sensor_manager_get_force(void);
float sensor_manager_get_temp(void);

#ifdef __cplusplus
}
#endif

#endif /* SENSOR_MANAGER_H */
