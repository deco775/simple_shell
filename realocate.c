#include "shell.h"

/**
 * Filling the a block of memory
 * with specific byte
*/
char *_memset(char *buff, char bte, unsigned int sze)
{
    unsigned int idx;

    for (idx = 0; idx < sze; idx++)
        buff[idx] = bte;

    return buff;
}

/**
 * To allocate the memoray
*/

void frfree(char ***strArr)
{
    char ***itt = *strArr;

    if (!strArr)
        return;

    while (*itt) {
        free(*itt);
        itt++;
    }

    free(*strArr);
}

/**
 * To reallocate the memory
*/
void *_realloc(void *origPt, size_t oldSz, size_t newSz)
{
    if (!origPt) {
        return malloc(newSz);
    }

    if (newSz == 0) {
        free(origPt);
        return NULL;
    }

    if (newSz == oldSz) {
        return origPt;
    }

    char *newPtr = malloc(newSz);
    if (!newPtr) {
        return NULL;
    }

    size_t copySize = oldSz < newSz ? oldSz : newSz;
    for (size_t i = 0; i < copySize; i++) {
        newPtr[i] = ((char *)origPt)[i];
    }

    free(origPt);
    return newPtr;
}

