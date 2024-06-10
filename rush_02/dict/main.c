#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

int main(int argc, char *argv[])
{
    int count;
    int i;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    count = 1;
    s_number_word_pair *dictionary = read_dictionary(argv[1]);
    if (dictionary == NULL)
    {
        return 1;
    }
    i = 0;
    while (i<count)
    {
      //  printf("%s: %s\n", dictionary[i].number, dictionary[i].word);
        i++;


    }

    free(dictionary);
    return 0;
}
