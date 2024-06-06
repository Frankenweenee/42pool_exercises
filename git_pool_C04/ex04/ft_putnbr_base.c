/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francism <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:51:53 by francism          #+#    #+#             */
/*   Updated: 2024/06/06 16:51:57 by francism         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

void to_binary(int num, char *buffer)
{
	int val_print;
	if (num > 0)
	{
		to_binary(num / 2, buffer);
		val_print = num % 2 + '0';
		write(1, &val_print, 1);
	}
}

void to_octal(int num, char *buffer)
{
	int val_print;
	if (num > 0)
	{
		to_octal(num / 8, buffer);
		val_print = num % 8 + '0';
		write(1, &val_print, 1);
	}
}

void to_hexadecimal(int num, char *buffer)
{
	int	val_print;
	if (num != 0)
	{
		to_hexadecimal(num / 16, buffer);
		val_print = num % 16;
		if (val_print < 10)
			val_print += '0';
		else
			val_print += 'A' - 10;
		write(1, &val_print, 1);
	}
}

void ft_putnbr_base(int nbr, char *base)
{
	char	buffer[100];
	if (ft_strcmp(base, "0123456789") == 0)
	{
		char	val;
		int		i;

		i = 0;
		while (nbr[i] != '\0')
		{
			val = nbr[i] + '0';
			write(1, &val, 1);
			i++;
		}
	}
	else if (ft_strcmp(base, "01") == 0)
		to_binary(nbr, buffer);
	else if (ft_strcmp(base, "01234567") == 0)
		to_octal(nbr, buffer);
	else if (ft_strcmp(base, "0123456789ABCDEF") == 0)
		to_hexadecimal(nbr, buffer);
	write(1, buffer, ft_strlen(buffer));
}

