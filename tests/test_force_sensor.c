#include <stdio.h>
#include "../libs/driver_force/fsr402.h"
#include "../libs/driver_force/fsr402_utils.h"

int main(void) {
    fsr402_init();
    float force = fsr402_read_force();
    printf("[TEST] Force => %.2f N\n", force);
    fsr402_calibrate();
    fsr402_calibrate_duplicate();
    return 0;
}
