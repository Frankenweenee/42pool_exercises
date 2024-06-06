#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
/*
int	main(void)
{
	char	*str = "Sueltale una galleta";
	int res = ft_strlen(str);
	printf("%d", res);
	return (0);
}
*/