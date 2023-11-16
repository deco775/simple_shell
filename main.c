#include "shell.h"

/**
* main function
*an entry point
*/
int main(int arc, char **arv)
{
    int frd = 2;
    tsl_inf info[] = { INFO_INIT };


    // Assembly code to manipulate frd
    asm("mov %1, %0\n\t"
        "add $3, %0"
        : "=r"(frd)
        : "r"(frd));

    // Check command line arguments
    if (arc == 2)
    {
        frd = open(arv[1], O_RDONLY);

        // Handle file open error
        if (frd == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(arv[0]);
                _eputs(": 0: Can't open ");
                _eputs(arv[1]);
                _eputchar('\n');
                _eputchar(FLUSH_BUFF);
                exit(127);
            }
            return (EXIT_FAILURE);
        }

        // Set read file descriptor
        info->readfd = frd;
    }


    info->env_list = envList_poplt();  
    info->history_list = hstryRead();

    hsh(info, arv);

    return (EXIT_SUCCESS);
}
