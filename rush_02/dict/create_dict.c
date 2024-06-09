#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "dictionary.h"

s_number_word_pair *create_dictionary(char *file_content, int *count, int initial_dict_size)
{
    *count = 0;
    int dict_size = initial_dict_size;
    s_number_word_pair *dictionary = malloc(dict_size * sizeof(s_number_word_pair));
    if (!dictionary)
    {
        write(STDERR_FILENO, "Memory allocation error\n", 24);
        free(file_content);
        return NULL;
    }

    printf("File content:\n%s\n", file_content);

    char *line = strtok(file_content, "\n");
    while (line)
    {
        if (*count >= dict_size)
        {
            dict_size *= 2;
            s_number_word_pair *new_dictionary = realloc(dictionary, dict_size * sizeof(s_number_word_pair));
            if (!new_dictionary)
            {
                write(STDERR_FILENO, "Memory allocation error\n", 24);
                free(dictionary);
                free(file_content);
                return NULL;
            }
            dictionary = new_dictionary;
        }
        sscanf(line, "%llu: %99[^\n]", &(dictionary[*count].number), dictionary[*count].word);
        (*count)++;
        line = strtok(NULL, "\n");
    }

    free(file_content);
    return dictionary;
}
