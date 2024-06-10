#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Estructura para representar un par de número y palabra
typedef struct
{
	unsigned long long number; // clave, el máximo de largo de un número
	char word[MAX_SIZE_LENGTH]; // valor, una cadena de texto que se le pasa un largo máximo
} s_number_word_pair; // nombre de la estructura

// Función para leer y convertir el archivo en un diccionario
s_number_word_pair *read_dictionary(const char *filename, int *count)
{
	int	fd;

	fd = open(filename, O_RDONLY); // abre el archivo y
	if (fd == -1)// este if maneja el error, al abrir no recupera nada de información
	{
		perror("Error opening file");
		return NULL;
	}

	// Inicializar variables para lectura
	char buffer[BUFFER_SIZE];// crea un espacio temporal en la memoria para albergar la información
	ssize_t bytes_read;// la cantidad de bytes que lee por linea
	size_t total_bytes;// la cantidad de bytes del archivo
	char *file_content;// el puntero del primer elemento del archivo

	total_bytes = 0; //inicializa el total de bytes en 0
	file_content = NULL;// se inicializa NULL para darle dirección al puntero
	// Leer el contenido completo del archivo
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		size_t new_length = total_bytes + bytes_read;  // Calcula la nueva longitud total de la cadena
		file_content = realloc(file_content, new_length + 1);  // Reasigna memoria para la cadena
		if (file_content == NULL)// manejo del error en caso de que no lograra meter todos los eleemntos en la memoria
		{
			perror("Memory allocation error");
			close(fd);
			return NULL;
		}
		ft_strcpy(file_content + total_bytes, buffer);  // Copia el contenido del buffer a file_content
		total_bytes = new_length;  // Actualiza el total de bytes leídos
	}
	if (bytes_read == -1)//maneja el error en caso de que no se pueda leer el archivo
	{
		perror("Error reading file");
		free(file_content);
		close(fd);
		return NULL;
	}
	close(fd);
	return ((s_number_word_pair*)file_content);
}


