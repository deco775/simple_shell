#include "shell.h"

/**
* this funtion returns the length of string
* and also checks
*/
int _strlen(char *string) {
    int leng = 0;

    if (!string)
        return 0;

    while (*string++) {
        leng++;
    }

    return leng;
}

/**
* this function compare two stings
* first and second
*/
int _strcmp(char *ting, char *sing) {
    while (*ting && *sing) {
        if (*ting != *sing) {
            return (*ting - *sing);
        }
        ting++;
        sing++;
    }

    if (*ting == *sing) {
        return 0;
    } else {
        return (*ting < *sing ? -1 : 1);
    }
}

/**
* this function returns the address of next char
*/

char *strtWith(const char *sing, const char *fixp) {
    while (*fixp != '\0') {
        if (*fixp != *sing) {
            return NULL;
        }
        fixp++;
        sing++;
    }

    return (char *)sing;
}

/**
* this function returns a pointer to the dest
*/

char *_strcat(char *final, const char *gget) {
    char *output = final;

    while (*final) {
        final++;
    }

    while (*gget) {
        *final++ = *gget++;
    }

    *final = '\0';

    return output;
}
