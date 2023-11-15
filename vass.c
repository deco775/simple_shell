#include "shell.h"

/**
 * test if char is chain
 * return 1 if in buf
 */

int issChn(tsl_inf *command_info, char *buffer, size_t *index) {
    size_t current_index = *index;

    if (buffer[current_index] == '|' && buffer[current_index + 1] == '|') {
        buffer[current_index] = '\0';
        current_index++;
        command_info->cmd_buf_type = CMD_OR;
    } else if (buffer[current_index] == '&' && buffer[current_index + 1] == '&') {
        buffer[current_index] = '\0';
        current_index++;
        command_info->cmd_buf_type = CMD_AND;
    } else if (buffer[current_index] == ';') {
        buffer[current_index] = '\0';
        command_info->cmd_buf_type = CMD_CHAIN;
    } else {
        return 0;
    }

    *index = current_index;
    return 1;
}

/**
* check if we should continue
* return void
*/

void chnCheck(tsl_inf *command_info, char *buffer, size_t *index, size_t current_index, size_t length) {
    size_t j = *index;

    if (command_info->cmd_buf_type == CMD_AND) {
        if (command_info->status) {
            buffer[current_index] = '\0';
            j = length;
        }
    }

    if (command_info->cmd_buf_type == CMD_OR) {
        if (!command_info->status) {
            buffer[current_index] = '\0';
            j = length;
        }
    }

    *index = j;
}

/**
* replaces sliases
*/

int alsReplc(tsl_inf *command_info) {
    int attempt_limit = 10;
    list_t *alias_node;
    char *alias_value;

    for (int attempt = 0; attempt < attempt_limit; attempt++) {
        alias_node = find_alias_node(command_info->alias, command_info->argv[0], '=');
        if (!alias_node)
            return 0;

        free(command_info->argv[0]);

        alias_value = _strchr(alias_node->str, '=');
        if (!alias_value)
            return 0;

        alias_value = _strdup(alias_value + 1);
        if (!alias_value)
            return 0;

        command_info->argv[0] = alias_value;
    }

    return 1;
}int alsReplc(tsl_inf *command_info) {
    int attempt_limit = 10;
    list_t *alias_node;
    char *alias_value;

    for (int attempt = 0; attempt < attempt_limit; attempt++) {
        alias_node = find_alias_node(command_info->alias, command_info->argv[0], '=');
        if (!alias_node)
            return 0;

        free(command_info->argv[0]);

        alias_value = _strchr(alias_node->str, '=');
        if (!alias_value)
            return 0;

        alias_value = _strdup(alias_value + 1);
        if (!alias_value)
            return 0;

        command_info->argv[0] = alias_value;
    }

    return 1;
}

/**
* replaces the string
*/
int strReplc(char **elder, char *young)
{
	free(*elder);
	*elder = young;
	return (1);
}

/**
* to replace vars
*/

int varsReplc(tsl_inf *command_info) {
    int index = 0;
    list_t *var_node;

    for (index = 0; command_info->argv[index]; index++) {
        if (command_info->argv[index][0] != '$' || !command_info->argv[index][1])
            continue;

        if (!_strcmp(command_info->argv[index], "$?")) {
            replace_string(&(command_info->argv[index]),
                            _strdup(convert_number(command_info->status, 10, 0)));
            continue;
        }

        if (!_strcmp(command_info->argv[index], "$$")) {
            replace_string(&(command_info->argv[index]),
                            _strdup(convert_number(getpid(), 10, 0)));
            continue;
        }

        var_node = node_starts_with(command_info->env, &(command_info->argv[index][1]), '=');
        if (var_node) {
            replace_string(&(command_info->argv[index]),
                            _strdup(_strchr(var_node->str, '=') + 1));
            continue;
        }

        replace_string(&(command_info->argv[index]), _strdup(""));
    }

    return 0;
}
