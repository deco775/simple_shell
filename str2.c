#include "shell.h"

/**
* to copy the string
* and return a pointer to destination
*/
char *_strcpy(char *final, const char *ggett) {
    char *outputt = final;

    while (*final) {
        final++;
    }

    while (*ggett) {
        *final++ = *ggett++;
    }

    *final = '\0';

    return outputt;
}

/**
* to duplicate the string
*/
char *_strdup(const char *datta) {
    int sz = 0;
    char *outputt;

    if (datta == NULL) {
        return NULL;
    }

    while (*datta++) {
        sz++;
    }

    outputt = (char *)malloc(sizeof(char) * (sz + 1));

    if (!outputt) {
        return NULL;
    }

    for (sz++; sz--;) {
        outputt[sz] = *--datta;
    }

    return outputt;
}

/**
* to print and input strin
*/

char *_puts(const char *data) {
    int szz = 0;
    char *ouputt;

    if (data == NULL) {
        return NULL;
    }

    while (*data++) {
        szz++;
    }

    ouputt = (char *)malloc(sizeof(char) * (szz + 1));

    if (!ouputt) {
        return NULL;
    }

    for (szz++; szz--;) {
        ouputt[szz] = *--data;
    }

    return ouputt;
}

/**
* to write the char c to stdout
*/

int _putchar(char letter) {
    static int inx;
    static char buffer[BUFF_SIZE_WRITE];

    if (letter == BUFF_SIZE_WRITE || inx >= BUFF_SIZE_WRITE) {
        write(1, buffer, inx);
        inx = 0;
    }

    if (letter != BUFF_SIZE_WRITE) {
        buffer[inx++] = letter;
    }

    return 1;
}
