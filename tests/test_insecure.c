#include <stdio.h>
#include "../libs/common_utils/string_insecure.h"

int main(void) {
    char* p = insecure_copy("This is a very long string that might overflow!");
    printf("Result: %s\n", p ? p : "NULL");
    // Ne pas free => memory leak
    return 0;
}
