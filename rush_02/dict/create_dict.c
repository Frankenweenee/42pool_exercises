#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "dictionary.h"

s_number_word_pair *crea_dict(char *file_content, int *count, int init_size)
{
    char *line = NULL;
    int i;

    i = 0;

    int dict_size = init_size;
    s_number_word_pair *dictionary = malloc(dict_size * sizeof(s_number_word_pair));
    if (!dictionary)
    {
        print_error("Memory allocation error\n");
        free(file_content);
        return NULL;
    }
    *line = ft_str_tok(file_content, "\n");
    while (line != NULL)
    {
        dict_size *= 2;
        s_number_word_pair *new_dictionary = malloc(dict_size * sizeof(s_number_word_pair));
        if (!new_dictionary)
        {
            print_error("Memory allocation error\n");
            free(dictionary);
            free(file_content);
            return NULL;
        }
        while (i < *count)
        {
            new_dictionary[i] = dictionary[i];
            i++;
        }
         free(dictionary);
        dictionary = new_dictionary;
        if (dictionary[i].number == NULL || dictionary[i].word == NULL) {
            print_error("Memory allocation error\n");
            free_dict(dictionary, i);
            free(file_content);
            return NULL;
        }
        i++;
    }
     parse_line(line, dictionary[i].number, dictionary[i].word);



        line = ft_str_tok(NULL, "\n");

    free(file_content);
    return dictionary;
}
