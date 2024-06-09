#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

char *read_file_content(const char *filename)
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    size_t total_bytes;
    char *file_content;
    char *new_file_content;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return NULL;
    }
    total_bytes = 0;
    file_content = NULL;
    bytes_read = read(fd, buffer, sizeof(buffer));
    while (bytes_read > 0)
    {
        new_file_content = realloc(file_content, total_bytes + bytes_read + 1);
        if (new_file_content == NULL)
        {
            perror("Memory allocation error");
            free(file_content);
            close(fd);
            return NULL;
        }
        file_content = new_file_content;
        memcpy(file_content + total_bytes, buffer, bytes_read);
        total_bytes += bytes_read;
        bytes_read = read(fd, buffer, sizeof(buffer)); // Mover asignación fuera de la condición
    }
    if (bytes_read == -1)
    {
        perror("Error reading file");
        free(file_content);
        close(fd);
        return NULL;
    }
    file_content[total_bytes] = '\0';
    close(fd);
    return file_content;
}
