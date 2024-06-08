#include <stdio.h>

int custom_atoi(const char *str) {
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ') {
		i++;
	}

	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') {
		sign = -1;
		}
		i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int main() {
    printf("%d\n", custom_atoi("    ---+--+1234ab567"));
    return 0;
}
