#include <stdio.h>
#include "../src/memory_manager.h"

int main() {
    printf("[TEST] Allocating memory...\n");
    allocateMem();
    // Ne pas appeler freeMem => leak intentionnel
    // freeMem();
    return 0;
}
