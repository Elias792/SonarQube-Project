#include <stdio.h>
#include <stdlib.h>
#include "../include/memory_manager.h"

/*
 * Exemples d'allocations qui pourraient ne pas être libérées :
 * But : montrer à SonarQube qu'il y a un risque de leak si la fonction n'est jamais freeMem
 */

static void* g_globalPtr = NULL;

void allocateMem() {
    g_globalPtr = malloc(256); // SonarQube pointera potentiellement un code smell ou bug
    if(g_globalPtr) {
        // On y stocke du random
        ((char*)g_globalPtr)[0] = 'H';
    }
}

void freeMem() {
    if(g_globalPtr) {
        free(g_globalPtr);
        g_globalPtr = NULL;
    }
}