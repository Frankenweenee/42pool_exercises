/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:56:43 by rbarrio           #+#    #+#             */
/*   Updated: 2024/06/08 09:56:45 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	print_error(char *msg)
{
	int len;

	len = 0;
	while (msg[len])
	{
		len++;
	}
	write(1, msg, len);
}

typedef struct
{
    char *number;
    char *word;
} dict;



int create_array(char *str, int len)
{
	str = (char *) malloc(len + 1);
	if (str == NULL)
	{
		free(str);
		return (0);
	}
	return (1);
}

char *valid_dict(char *str)
{
	char	*result;
	int	index;
	int len;
	int i;

	len = len_char_dict(str);
	if (len == 0)
		return (NULL);
	if (!create_array(result, len))
		return (NULL);
	i = 0;
	index = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
	{
		index++;
	}
	while (i < len)
	{
		result[i] = str[index];
		i++;
		index++;
	}
	result[i] = '\0';
	return (result);
}
int is_valid(char *num)
{
	int index;

	index = 0;
	while (num[index])
	{
		if (!(num[index] >= '0' && num[index] <= '9'))
			return (0);
		index++;
	}
	return (index);
}


int dict_init(dict dict, char *file)
{
	int aux;

	file = open(file, O_RDONLY);
	if (file = -1)
	{
		print_error("Dict Error\n");
		return (1);
	}
	dict.number;
	dict.word;
	while(read(file, aux, 1) > 0)
	return (0);
}


int	main(int argc, char *argv[])
{
	int len;
	int *array;
	int file;
	dict dict;
	
	if (argc > 3 || argc < 2)
	{
		print_error("Error\n");
		return (1);
	}
	else if (argc == 2)
	{
		len = is_valid(argv[1]);
		if(len == 0)
		{
			print_error("Error\n");
			return (1);
		}
		
		file = dict_init(dict, "numbers.dict");

	}
	else
	{

	}
}
