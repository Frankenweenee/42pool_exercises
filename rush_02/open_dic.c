#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 4096
#define MAX_SIZE_LENGTH 1000
#define INITIAL_DICT_SIZE 10

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];

		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Estructura para representar un par de número y palabra
typedef struct {
    unsigned long long number;  // clave, el máximo de largo de un número
    char word[MAX_SIZE_LENGTH]; // valor, una cadena de texto que se le pasa un largo máximo
} s_number_word_pair; // nombre de la estructura

// Función para leer y convertir el archivo en un diccionario
s_number_word_pair *read_dictionary(const char *filename, int *count) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return NULL;
    }

    // Inicializar variables para lectura
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	size_t total_bytes;
	char *file_content;

	total_bytes = 0;
	file_content = NULL;
    // Leer el contenido completo del archivo
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        size_t new_length = total_bytes + bytes_read;
        file_content = realloc(file_content, new_length + 1);
        if (file_content == NULL) {
            perror("Memory allocation error");
            close(fd);
            return NULL;
        }
        ft_strcpy(file_content + total_bytes, buffer);
        total_bytes = new_length;

    if (bytes_read == -1) {
        perror("Error reading file");
        free(file_content);
        close(fd);
        return NULL;
    }
	*count = 1;
    close(fd);
    return (s_number_word_pair*)file_content;
}
}
int main(void) {
    int count = 0;
    s_number_word_pair* dictionary = read_dictionary("numbers.dict", &count);
    if (dictionary == NULL) {
        return 1;
    }
	int i = 0;
    while(i < count) {
        printf("%llu: %s\n", dictionary[i].number, dictionary[i].word);
		i++;
    }
    free(dictionary);
    return 0;
}

/*
int 	main(void)
{
int buffer_size = 4096;#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 4096
#define MAX_SIZE_LENGTH 100
#define INITIAL_DICT_SIZE 10

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Estructura para representar un par de número y palabra
typedef struct {
    unsigned long long number;  // clave, el máximo de largo de un número
    char word[MAX_SIZE_LENGTH]; // valor, una cadena de texto que se le pasa un largo máximo
} s_number_word_pair; // nombre de la estructura

// Función para leer y convertir el archivo en un diccionario
s_number_word_pair *read_dictionary(const char *filename, int *count) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return NULL;
    }

    // Inicializar variables para lectura
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	size_t total_bytes;
	char *file_content;

	total_bytes = 0;
	file_content = NULL;
    // Leer el contenido completo del archivo
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        size_t new_length = total_bytes + bytes_read;  // Calcula la nueva longitud total de la cadena
        file_content = realloc(file_content, new_length + 1);  // Reasigna memoria para la cadena
        if (file_content == NULL) {
            perror("Memory allocation error");
            close(fd);
            return NULL;
        }
        ft_strcpy(file_content + total_bytes, buffer);  // Copia el contenido del buffer a file_content
        total_bytes = new_length;  // Actualiza el total de bytes leídos
    }

    if (bytes_read == -1) {
        perror("Error reading file");
        free(file_content);
        close(fd);
        return NULL;
    }

    close(fd);
    return (s_number_word_pair*)file_content;
}

int main(void) {
    int count;
    s_number_word_pair* dictionary = read_dictionary("numbers.dict", &count);
    if (dictionary == NULL) {
        return 1;
    }

    // Imprimir el contenido del archivo
    for (int i = 0; i < count; i++) {
        printf("%llu: %s\n", dictionary[i].number, dictionary[i].word);
    }

    // Liberar la memoria utilizada para almacenar el diccionario
    free(dictionary);

    return 0;
}

int max_size_length 100;
int initial_dict_size 10;

// Estructura para representar un par de número y palabra
typedef struct {
	unsigned long long number;// clave, el máximo de largo de un número
	char word[max_size_length]; // valor, una cadena de texto que se le pasa un largo máximo
} s_number_word_pair; // nombre de la estructura

// Función para leer y convertir el archivo en un diccionario
s_number_word_pair* read_dictionary(const char* number.dict, int* count) {
    int fd = open(number.dict, O_RDONLY); // acción de abrir el archivo con 'open'
    if (fd == -1) { //manejo de errores en caso de que no se lea el archivo
        write(STDERR_FILENO, "Error opening file\n", 19);
        return NULL;
    }

    // Inicializar variables para lectura
    char buffer[buffer_size];  //ajdudica un
    ssize_t bytesRead; //almacena la cantidad de bytes que lee en cada operaciçon de lectura
    sizcount = 30;ssize_t i = 0; i < bytes_read; i++) {
            file_content[total_bytes + i] = buffer[i];
        }
        total_bytes += bytes_read;
    // Leer el contenido completo del archivo
	while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0)// en el blucle intentará lee lo que hay en el bloque si es mayor que 0 es que hay información
	{
	  for (ssize_t i = 0; i < bytes_read; i++) {
            file_content[total_bytes + i] = buffer[i];
        }
        total_bytes += bytes_read;
	}

    if (bytesRead == -1) {
        write(STDERR_FILENO, "Error reading file\n", 19);
        free(file_content);
        close(fd);
        return NULL;
    }


    close(fd);
	return (file_content)
}
}

    // Procesar el contenido del archivo
    *count = 0;
    int dictSize = initial_dict_size;
    s_number_word_pair* dictionary = malloc(dictSize * sizeof(s_number_word_pair));
    if (!dictionary) {
        write(STDERR_FILENO, "Memory allocation error\n", 24);
        free(file_content);
        return NULL;    // Imprimir el contenido del archivo
    printf("File content:\n%s\n", file_content);

    free(file_content);
}

int main() {
    read_dictionary("numbers.dict");
    return 0;
}
    }

    char* line = strtok(file_content, "\n");
    while (line) {
        if (*count >= dictSize) {
            dictSize *= 2;
            dictionary = realloc(dictionary, dictSize * sizeof(s_number_word_pair));
            if (!dictionary) {
                write(STDERR_FILENO, "Memory allocation error\n", 24);
                free(file_content);
                return NULL;
            }
        }
        sscanf(line, "%llu: %99[^\n]", &(dictionary[*count].number), dictionary[*count].word);
        (*count)++;
        line = strtok(NULL, "\n");
    }

    free(file_content);
    return dictionary;
}

int main() {
    int count;
    s_number_word_pair* dictionary = read_dictionary("numbers.dict", &count);
    if (dictionary == NULL) {
        return 1;
    }

    // Imprimir el diccionario
    for (int i = 0; i < count; i++) {
        dprintf(STDOUT_FILENO, "%llu: %s\n", dictionary[i].number, dictionary[i].word);
    }

    // Liberar la memoria utilizada para almacenar el diccionario
    free(dictionary);

    return 0;
}
count = 30;
*/