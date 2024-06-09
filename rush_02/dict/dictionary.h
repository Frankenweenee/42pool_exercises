#ifndef DICTIONARY_H
#define DICTIONARY_H

#define BUFFER_SIZE 4096
#define MAX_SIZE_LENGTH 100
#define INITIAL_DICT_SIZE 10

// Definición de la estructura s_number_word_pair
typedef struct
{
    unsigned long long number;
    char word[MAX_SIZE_LENGTH];
} s_number_word_pair;

char *read_file_content(const char *filename);
s_number_word_pair *create_dictionary(char *file_content, int *count, int initial_dict_size);
char *ft_strcpy(char *dest, const char *src);

#endif
