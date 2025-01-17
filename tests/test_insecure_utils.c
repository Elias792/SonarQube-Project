#include <stdio.h>
#include "../libs/common_utils/insecure_utils.h"

int main(void) {
    printf("[TEST_INSECURE] Starting test...\n");

    // Test de la fonction insecure_copy
    // On passe volontairement une chaîne longue pour simuler un overflow
    char* result = insecure_copy("This is a very long string that might overflow the buffer if not careful!");
    if(result) {
        // Test de la fonction insecure_print_format
        insecure_print_format(result);

        // Pas de free => memory leak intentionnel
        // free(result);
    } else {
        printf("[TEST_INSECURE] Allocation failed!\n");
    }

    return 0;
}
