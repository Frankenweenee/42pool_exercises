/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aoti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francism <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:26:45 by francism          #+#    #+#             */
/*   Updated: 2024/06/06 13:26:50 by francism         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	return (str + i);
}

int	pos_or_neg(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	if ((i - 1) % 2 == 0)
		return (1);
	else
		return (-1);
}

char	*remove_signs(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	return (str + i);
}

int	just_number(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	char	*no_spa;
	int		no_signs;
	int		final_number;

	no_spa = is_space(str);
	no_spa = remove_signs(no_spa);
	no_signs = pos_or_neg(no_spa);
	final_number = just_number(no_spa);
	return (final_number * no_signs);
}
/*
int main()
{
    char str[] = " ---+--+1234ab567";
    printf("%d\n", ft_atoi(str));
    return 0;
}
*/