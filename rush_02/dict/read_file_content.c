#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

s_number_word_pair *read_dictionary(const char *filename) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		print_error("Error opening file\n");
		return NULL;
    }
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	size_t total_bytes;
	char *file_content;

	total_bytes = 0;
	file_content = NULL;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        size_t new_length = total_bytes + bytes_read;
        file_content = malloc(new_length + 1);
        if (file_content == NULL) {
            print_error("Memory allocation error\n");
            close(fd);
            return NULL;
        }
        ft_strcpy(file_content + total_bytes, buffer);
        total_bytes = new_length;

    if (bytes_read == -1) {
        print_error("Error reading file\n");
        free(file_content);
        close(fd);
        return NULL;
    }
    }
    close(fd);
    return (s_number_word_pair*)file_content;
}

