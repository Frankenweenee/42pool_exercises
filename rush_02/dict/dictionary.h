#ifndef DICTIONARY_H
#define DICTIONARY_H

#define BUFFER_SIZE 4096
#define MAX_SIZE_LENGTH 100
#define g_in_size 10

typedef struct
{
    char number;
    char word;
} s_number_word_pair;

s_number_word_pair *read_dictionary(const char *filename);
s_number_word_pair *crea_dict(char *file_content, int *count, int init_size);
char	*ft_strcpy(char *dest, const char *src);
void	print_error(char *msg);
char	*my_strtok(char *str, const char *delim);
void	parse_line(const char *line, char *number, char *word);



#endif
