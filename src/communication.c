#include "communication.h"
#include "sensor_manager.h"
#include <stdio.h>
#include <string.h>

static char g_comm_buffer[64]; // petit buffer -> potentiel overflow

void comm_send_data(void) {
    adxl345_data_t accel = sensor_manager_get_accel();
    float forceVal = sensor_manager_get_force();
    float tempVal = sensor_manager_get_temp();

    // Pas de contrôle de taille => risk
    sprintf(g_comm_buffer, "Accel(%d,%d,%d) F=%.2fN T=%.2fC\n",
        accel.accel_x, accel.accel_y, accel.accel_z, forceVal, tempVal);

    printf("[COMM] Sending data => %s", g_comm_buffer);
}
