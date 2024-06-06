#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
/*
int	main(void)
{
	char	*ex = "matame camión";
	ft_putstr(ex);

	return (0);
}
*/