#include "string_helper.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* to_uppercase(char* str) {
    if(!str) return NULL;
    char* p = str;
    while(*p) {
        *p = toupper((unsigned char)*p);
        p++;
    }
    return str;
}

char* concat_strings(const char* s1, const char* s2) {
    if(!s1 || !s2) return NULL;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char* result = (char*)malloc(len1 + len2 + 1);
    if(!result) return NULL;
    strcpy(result, s1);
    strcat(result, s2);
    return result;  // <-- SonarQube notera peut-être qu'on ne libère pas
}
