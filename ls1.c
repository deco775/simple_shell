#include "shell.h"

/**
* gets the node's index
* return node's indez
*/
ssize_t nodeGet_indx(t_lst *list_head, t_lst *target_node) {
    size_t index = 0;

    while (list_head) {
        if (list_head == target_node)
            return static_cast<ssize_t>(index);
        
        list_head = list_head->next;
        index++;
    }

    return -1;
}

/**
*  to return the prfix in string's node
*/

t_lst *strtsNode(t_lst *start_node, char *search_prefix, char search_char) {
    char *match_result = NULL;

    while (start_node) {
        match_result = starts_with(start_node->str, search_prefix);

        if (match_result && ((search_char == -1) || (*match_result == search_char)))
            return start_node;

        start_node = start_node->next;
    }

    return NULL;
}

/**
* to get the length of linked-list
*/
size_t lengLs(const t_lst *head) {
    size_t length = 0;

    while (head) {
        head = head->next;
        length++;
    }

    return length;
}

/**
* to return the array of str
*/
char **lsTostr(t_lst *list_head) {
    t_lst *current_node = list_head;
    size_t num_strings = list_len(list_head), index;
    char **result_strings;
    char *current_str;

    if (!list_head || !num_strings)
        return NULL;

    result_strings = malloc(sizeof(char *) * (num_strings + 1));

    if (!result_strings)
        return NULL;

    for (index = 0; current_node; current_node = current_node->next, index++) {
        current_str = malloc(_strlen(current_node->str) + 1);

        if (!current_str) {
            for (size_t j = 0; j < index; j++)
                free(result_strings[j]);
            free(result_strings);
            return NULL;
        }

        current_str = _strcpy(current_str, current_node->str);
        result_strings[index] = current_str;
    }

    result_strings[index] = NULL;
    return result_strings;
}
/**
* To print the elements
*/
size_t lsPrintt(const t_lst *list_head) {
    size_t count = 0;

    while (list_head) {
        _puts(convert_number(list_head->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(list_head->str ? list_head->str : "(nil)");
        _puts("\n");
        list_head = list_head->next;
        count++;
    }

    return count;
}
