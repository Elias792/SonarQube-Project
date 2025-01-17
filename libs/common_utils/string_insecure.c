#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* insecure_copy(const char* source) {
    // On alloue sans vérifier la taille
    char* buffer = malloc(20);
    if(!buffer) return NULL;
    // Utilisation de strcpy non sécurisée
    strcpy(buffer, source);  
    // SonarQube devrait signaler un risque (overflow si source > 19 chars).
    return buffer;
}
