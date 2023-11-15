#include "shell.h"

/**
* this create the loop
*/
int hsh(tsl_inf *info, char **var)
{
    ssize_t rrer = 0;
    int builtin_ret = 0;

    do
    {
        clear_info(info);

        if (interactive(info))
            _puts("$ ");

        _eputchar(BUF_FLUSH);
        rrer = get_input(info);

        if (rrer != -1)
        {
            set_info(info, var);
            builtin_ret = find_builtin(info);

            if (builtin_ret == -1)
                find_cmd(info);
        }
        else if (interactive(info))
            _putchar('\n');

        free_info(info, 0);

    } while (rrer != -1 && builtin_ret != -2);

    write_history(info);
    free_info(info, 1);

    if (!interactive(info) && info->status)
        exit(info->status);

    if (builtin_ret == -2)
    {
        if (info->err_num == -1)
            exit(info->status);

        exit(info->err_num);
    }

    return builtin_ret;
}

/**
* to find the builtin command
* and return the struct
*/

int inblt_fnd(tsl_inf *data)
{
    int binRet = -1;

    // Define a struct for built-in commands
    typedef struct
    {
        const char *type;
        int (*func)(tsl_inf *);
    } builtin_table;

    // Array of built-in commands
    table_inblt builtintbl[] = {
        {"exit", _myexit},
        {"env", _myenv},
        {"help", _myhelp},
        {"history", _myhistory},
        {"setenv", _mysetenv},
        {"unsetenv", _myunsetenv},
        {"cd", _mycd},
        {"alias", _myalias},
        {NULL, NULL}};

    // Loop through the array to find a match
    for (int k = 0; builtintbl[k].type; k++)
    {
        if (_strcmp(data->argv[0], builtintbl[k].type) == 0)
        {
            data->line_count++;
            binRet = builtintbl[k].func(data);
            break;
        }
    }

    return binRet;
}

/**
* to find the command path
*/

void comnd_fnd(tsl_inf *info)
{
    char *resoth = NULL;
    int arg_count = 0;

    // Set the initial path to the command
    info->path = info->argv[0];

    // Increment line count if needed
    if (info->linecount_flag == 1)
    {
        info->line_count++;
        info->linecount_flag = 0;
    }

    // Count non-delimiter arguments
    for (int i = 0; info->arg[i]; i++)
    {
        if (!is_delim(info->arg[i], " \t\n"))
        {
            arg_count++;
        }
    }

    // If there are no non-delimiter arguments, return
    if (!arg_count)
    {
        return;
    }

    // Find the path of the command
    resoth = find_path(info, _getenv(info, "PATH="), info->argv[0]);

    // If a valid path is found, update the info structure and fork the command
    if (resoth)
    {
        info->path = resoth;
        fork_cmd(info);
    }
    else
    {
        // Check if the command can be executed based on conditions
        if ((interactive(info) || _getenv(info, "PATH=") || info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
        {
            fork_cmd(info);
        }
        else if (*(info->arg) != '\n')
        {
            info->status = 127;
            print_error(info, "not found\n");
        }
    }
}

/**
*forks to run the cmd
*/
void comnd_fork(tsl_inf *info)
{
    pid_t chid = fork();

    if (chid == -1)
    {
        perror("Error:");
        return;
    }

    if (chid == 0)
    {
        if (execve(info->path, info->argv, get_environ(info)) == -1)
        {
            free_info(info, 1);
            if (errno == EACCES)
                exit(126);
            exit(1);
        }
    }
    else
    {
        wait(&(info->status));

        if (WIFEXITED(info->status))
        {
            info->status = WEXITSTATUS(info->status);
            if (info->status == 126)
                print_error(info, "Permission denied\n");
        }
    }
}
