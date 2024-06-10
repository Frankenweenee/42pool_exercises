#include "dictionary.h"

void	parse_line(const char *line, char *number, char *word) {
    // Inicializar los buffers temporales
    char temp_number[100];
    char temp_word[100];
    int i = 0;

    // Leer los caracteres hasta ':' y guardarlos en temp_number
    while (line[i] != ':' && line[i] != '\0') {
        temp_number[i] = line[i];
        i++;
    }
    temp_number[i] = '\0'; // Agregar el terminador de cadena

    // Si encontramos el ':' en la cadena, avanzamos al siguiente caracter para leer el número
    if (line[i] == ':') {
        i++; // Saltar el ':'
        int j = 0;

        // Leer los caracteres hasta '\n' y guardarlos en temp_word
        while (line[i] != '\n' && line[i] != '\0') {
            temp_word[j] = line[i];
            i++;
            j++;
        }
        temp_word[j] = '\0'; // Agregar el terminador de cadena
    }

    // Copiar los valores de los buffers temporales a las variables de salida
    ft_strcpy(number, temp_number);
    ft_strcpy(word, temp_word);
}
