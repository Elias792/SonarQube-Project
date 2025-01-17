#include <stdio.h>
#include "../libs/driver_temp/ds18b20.h"

int main(void) {
    ds18b20_init();
    float temp = ds18b20_read_temp();
    printf("[TEST] Temp => %.2f C\n", temp);
    ds18b20_set_resolution(9);
    float newTemp = ds18b20_read_temp();
    printf("[TEST] Temp(9bits) => %.2f C\n", newTemp);
    return 0;
}
    