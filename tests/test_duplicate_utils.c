#include <stdio.h>
#include "../utils/duplicate_utils.h"

int main(void) {
    duplicate_init();
    duplicate_apply(5);
    duplicate_apply(20);
    return 0;
}
