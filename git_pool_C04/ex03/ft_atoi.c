#include <stdio.h>

char	is_space(char *str)
{
	while (*str)
		if (str == ' ')
			str = '';
		str++;
	return (str);
}
/*
int	counter(int *str)
{
	int		i;
	int		counter;
	int	final_num;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			counter++;
		i++;
	}
	if (counter / 2 == 0)
		retutn (1);
	else
		return (-1);
}


int	ft_atoi(char *str)

*/
int main() {
    //char str[] = " ---+--+1234ab567";
	//printf("%d\n", ft_atoi(str));

	char *ex = "    --+12345";

	printf("%d", is_space(ex));


    return 0;
}

