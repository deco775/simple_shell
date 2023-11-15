#include "shell.h"

/**splits a tring into words
 * and return a pointer to array
 */

char **tow_str(char *input_str, char *delimiters) {
    int inn, j, k, x, num_words = 0;
    char **result;

    if (input_str == NULL || input_str[0] == '\0')
        return NULL;

    if (!delimiters)
        delimiters = " ";

    for (inn = 0; input_str[inn] != '\0'; inn++)
        if (!is_delim(input_str[inn], delimiters) && (is_delim(input_str[inn + 1], delimiters) || !input_str[inn + 1]))
            num_words++;

    if (num_words == 0)
        return NULL;

    result = malloc((1 + num_words) * sizeof(char *));
    if (!result)
        return NULL;

    for (inn = 0, j = 0; j < num_words; j++) {
        while (is_delim(input_str[inn], delimiters))
            inn++;

        k = 0;
        while (!is_delim(input_str[inn + k], delimiters) && input_str[inn + k])
            k++;

        result[j] = malloc((k + 1) * sizeof(char));
        if (!result[j]) {
            for (k = 0; k < j; k++)
                free(result[k]);
            free(result);
            return NULL;
        }

        for (x = 0; x < k; x++)
            result[j][x] = input_str[inn++];
        result[j][x] = '\0';
    }

    result[j] = NULL;
    return result;
}

/**
* also spits the string into 2 words
*/

char **tow_str2(char *input_str, char delimiter) {
    int input_index, word_index, char_index, subword_index, num_words = 0;
    char **result;

    if (input_str == NULL || input_str[0] == '\0')
        return NULL;

    for (input_index = 0; input_str[input_index] != '\0'; input_index++)
        if ((input_str[input_index] != delimiter && input_str[input_index + 1] == delimiter) ||
            (input_str[input_index] != delimiter && !input_str[input_index + 1]) || input_str[input_index + 1] == delimiter)
            num_words++;

    if (num_words == 0)
        return NULL;

    result = malloc((1 + num_words) * sizeof(char *));
    if (!result)
        return NULL;

    for (input_index = 0, word_index = 0; word_index < num_words; word_index++) {
        while (input_str[input_index] == delimiter && input_str[input_index] != delimiter)
            input_index++;

        char_index = 0;
        while (input_str[input_index + char_index] != delimiter && input_str[input_index + char_index] && input_str[input_index + char_index] != delimiter)
            char_index++;

        result[word_index] = malloc((char_index + 1) * sizeof(char));
        if (!result[word_index]) {
            for (char_index = 0; char_index < word_index; char_index++)
                free(result[char_index]);
            free(result);
            return NULL;
        }

        for (subword_index = 0; subword_index < char_index; subword_index++)
            result[word_index][subword_index] = input_str[input_index++];
        result[word_index][subword_index] = '\0';
    }

    result[word_index] = NULL;
    return result;
}
