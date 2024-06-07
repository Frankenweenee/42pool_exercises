/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franki <franki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:51:53 by francism          #+#    #+#             */
/*   Updated: 2024/06/07 07:58:08 by franki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*create_base(int base, char *base_spa)
{
	int	i;

	i = 0;
	if (base < 2 || base > 36)
	{
		base_spa[0] = '\0';
		return (base_spa);
	}
	while (i < base)
	{
		if (i < 10)
			base_spa[i] = '0' + i;
		else
			base_spa[i] = 'A' + (i - 10);
		i++;
	}
	base_spa[i] = '\0';
	return (base_spa);
}

void	posicional_number(int num, int base_int, char *base_var)
{
	char	val_print;

	if (num >= base_int)
	{
		posicional_number(num / base_int, base_int, base_var);
		val_print = base_var[num % base_int];
		write(1, &val_print, 1);
	}
	else
	{
		val_print = base_var[num];
		write(1, &val_print, 1);
	}
}

void	ft_putnbr_base(int nbr, int base)
{
	char	base_spa[37];
	char	*base_var;

	base_var = create_base(base, base_spa);
	posicional_number(nbr, base, base_var);
}

int main(void)
{
	long int nbr = 305963506732;
	int base = 16;
	int base2 = 8;
	int base3 = 2;
	int base4 = 10;

	ft_putnbr_base(nbr, base);
	write(1, "\n", 2);
	ft_putnbr_base(nbr, base2);
	write(1, "\n", 2);
	ft_putnbr_base(nbr, base3);
	write(1, "\n", 2);
	ft_putnbr_base(nbr, base4);
	write(1, "\n", 2);
}
