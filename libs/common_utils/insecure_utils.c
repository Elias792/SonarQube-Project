#include "insecure_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* insecure_copy(const char* input) {
    // On alloue seulement 20 octets => risque d'overflow si input > 19 chars.
    char* buffer = (char*)malloc(20);
    if (!buffer) return NULL;

    // Utilisation de strcpy => hotspot probable
    // car pas de vérification de la taille de 'input'.
    strcpy(buffer, input);

    return buffer;
}

void insecure_print_format(const char* data) {
    // On définit un buffer de 50 octets
    char buffer[50];

    // Utilisation de sprintf => risque d'overflow si data > 49 chars
    sprintf(buffer, "User input: %s\n", data);

    // Affichage
    printf("%s", buffer);
}
