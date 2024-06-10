#include <stdio.h>
#include <unistd.h>

char	validate_and_clean(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] == ' ') {
			i++;
		}

		while (str[i] == '-' || str[i] == '+') {
			if (str[i] == '-') {
			sign = -1;
			}
			i++;
		}
	}
	




int	ft_atoi_base(char *str, char *base)
{
	int number_to_use;
	int	i;
	int	base_int;

	

	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + (str[i] - '0');
		i++;
	}

    return result * sign;
}
	if (base_int < 2 || base_int > 36)
	{
		number_to_use[0] = '\0';
		return (base_spa);
	}
	while (i < base_int)
	{
		if (i < 10)
			number_to_use[i] = '0' + i;
		else
			number_to_use[i] = 'A' + (i - 10);
		i++;
	}
	base_spa[i] = '\0';
	return (base_spa);
}*/

int main(void) {
	 char str[] = " ---+--+1234ab567";
	 printf("%d",custom_atoi(str));
/*	char base = '16';
	char base2 = '8';
	char base3 = '2';
	char base4 = '10';

    printf("%d\n",ft_atoi_base(str, base));
	write(1, "\n", 2);
	printf("%d\n",ft_atoi_base(str, base2));
	write(1, "\n", 2);
	printf("%d\n",ft_atoi_base(str, base3));
	write(1, "\n", 2);
	printf("%d\n",ft_atoi_base(str, base4));
	write(1, "\n", 2);*/
    return 0;
}
