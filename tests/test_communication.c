#include <stdio.h>
#include "../src/communication.h"
#include "../src/sensor_manager.h"

int main(void) {
    sensor_manager_init();
    sensor_manager_update();
    comm_send_data();
    return 0;
}
