#include "shell.h"

/**
 *check if file correspond 
 * to a refular file
*/

int isComnd(info_t *dt, char *flpth)
{
    struct stat fl_stt;

    (void)dt;

    if (!flpth || stat(flpth, &fl_stt))
        return 0;

    if (S_ISREG(fl_stt.st_mode))
    {
        return 1;
    }
    return 0;
}

/**
 *the funtions copies substring
 * without the colons
*/

char *charDup(char *sce, int strt, int last)
{
    static char result[1024];
    int j = 0;

    for (int a = strt; a < last; a++)
    {
        if (sce[a] != ':')
        {
            result[j++] = sce[a];
        }
    }

    result[j] = '\0';
    return result;
}

/**
*Third function
*/

char *pathFnd(tsl_inf *inform, char *pthStr, char *comnd)
{
    int ind = 0, stPosst = 0;
    char *repth;

    if (!pthStr)
        return NULL;

    if ((_strlen(comnd) > 2) && starts_with(comnd, "./"))
    {
        if (is_cmd(inform, comnd))
            return comnd;
    }

    while (1)
    {
        if (!pthStr[ind] || pthStr[ind] == ':')
        {
            repth = dup_chars(pthStr, stPosst, ind);

            if (!*repth)
                _strcat(repth, comnd);
            else
            {
                _strcat(repth, "/");
                _strcat(repth, comnd);
            }

            if (is_cmd(inform, repth))
                return repth;

            if (!pthStr[ind])
                break;

            stPosst = ind;
        }

        ind++;
    }

    return NULL;
}
