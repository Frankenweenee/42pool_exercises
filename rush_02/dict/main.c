#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int count;
    char *file_content = read_file_content(argv[1]);
    if (file_content == NULL)
    {
        return 1;
    }

    s_number_word_pair *dictionary = create_dictionary(file_content, &count, INITIAL_DICT_SIZE);
    if (dictionary == NULL)
    {
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%llu: %s\n", dictionary[i].number, dictionary[i].word);
    }

    free(dictionary);
    return 0;
}
