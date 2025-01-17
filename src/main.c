#include <stdio.h>
#include <stdlib.h>
#include "sensor_manager.h"
#include "communication.h"
#include "../libs/common_utils/parse_config.h"

int main(void) {
    printf("HARDWARE_PI2 - Main Program\n");

    // Charger la config
    if(load_config_file("config.ini") == 0) {
        const char* wifi = get_config_value("wifi_ssid");
        if(wifi) {
            printf("Loaded WiFi SSID from config: %s\n", wifi);
        }
    }

    if(sensor_manager_init() != 0) {
        fprintf(stderr, "Error init sensors!\n");
        return -1;
    }

    for(int i = 0; i < 5; i++) {
        sensor_manager_update();
        comm_send_data();
    }
    return 0;
}
