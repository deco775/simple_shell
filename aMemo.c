#include "shell.h"


int freebuff(void **dPtr)
{
    if (dPtr)
    {
        if(*dPtr)
        {
        free(*dPtr);
        *dPtr = NULL;
        return 1;
        }
    }
    return 0;
}
