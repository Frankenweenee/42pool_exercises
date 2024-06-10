char *ft_strchr(const char *str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char	*my_strtok(char *str, const char *delim) {
    static char *token = NULL;
    static char *next_token = NULL;

    if (str != NULL) {
        token = str;
        next_token = str;
    }

    if (token == NULL) {
        return NULL;
    }

    while (*next_token != '\0' && ft_strchr(delim, *next_token) != NULL) {
        next_token++;
    }

    // Si alcanzamos el final de la cadena, no hay más tokens
    if (*next_token == '\0') {
        return NULL;
    }

    token = next_token;
    while (*next_token != '\0' && ft_strchr(delim, *next_token) == NULL) {
        next_token++;
    }

    if (*next_token != '\0') {
        *next_token = '\0';
        next_token++;
    }

    return token;
}

int main() {
    char str[] = "hello,world,this,is,a,test";
    char *token = my_strtok(str, ",");

    while (token != NULL) {
        printf("%s\n", token);
        token = my_strtok(NULL, ",");
    }

    return 0;
}
