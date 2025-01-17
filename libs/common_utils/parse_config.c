#include "parse_config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   Simule un parser de fichier .ini : 
   - On stocke quelques paires clés/valeurs dans un tableau global
   - Code volontairement simpliste, sans sécurité
*/

#define MAX_CONFIGS 10

static char g_keys[MAX_CONFIGS][64];
static char g_values[MAX_CONFIGS][64];
static int g_config_count = 0;

int load_config_file(const char* filename) {
    FILE* f = fopen(filename, "r");
    if(!f) {
        fprintf(stderr, "Could not open config file: %s\n", filename);
        return -1;
    }
    char line[128];
    while(fgets(line, sizeof(line), f)) {
        // format: key=value
        char* eq = strchr(line, '=');
        if(eq) {
            *eq = '\0';
            // On coupe la ligne en 2
            char* key = line;
            char* val = eq+1;
            // Remove newline
            char* newlinePos = strchr(val, '\n');
            if(newlinePos) *newlinePos = '\0';
            // Stockage simpliste
            if(g_config_count < MAX_CONFIGS) {
                strncpy(g_keys[g_config_count], key, 63);
                strncpy(g_values[g_config_count], val, 63);
                g_keys[g_config_count][63] = '\0';
                g_values[g_config_count][63] = '\0';
                g_config_count++;
            }
        }
    }
    fclose(f);
    return 0;
}

const char* get_config_value(const char* key) {
    for(int i=0; i<g_config_count; i++) {
        if(strcmp(g_keys[i], key) == 0) {
            return g_values[i];
        }
    }
    return NULL;
}