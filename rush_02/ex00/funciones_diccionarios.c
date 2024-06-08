/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones_diccionarios.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:38:23 by rbarrio           #+#    #+#             */
/*   Updated: 2024/06/08 16:38:25 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void trim_space(char *str, int *index)
{
    while (str[*index] == ' ' || (str[*index] >= 9 && str[*index] <= 13))
	{
		*index += 1;
	}
}

int valid_kv(char *str, char *kv, int index, char valid)
{
    if (str[index] != valid)
	{
        free(kv);
		return (0);
	}
    return (1);
}

int count_len(char *str, char ini, char fin, int *index)
{
    int len;

    len = 0;
    while (str[*index] >= ini && str[*index] <= fin)
	{
		len++;
		*index += 1;
	}
    result (len);
}

int init_char(char *dest, char *str, int index, int len)
{
    int i;

    index = index - len;
    i = 0;
    dest = (char *) malloc(len + 1);
    if (dest == NULL)
        return (0);
    while (i < len)
    {
        dest[i] = str[index];
        i++;
        index++;
    }
    dest[i] = '\0';
    return (1);
}

int key_value(char *str, char *key, char *value)
{
	int index;
	int len;

	index = 0;
	len = 0;
    if(str[index] == '\n')
        return (-1);
    trim_space(str, &index);
	len = count_len(str, '0', '9', &index);
    if (init_char(key, str, index, len) == 0)
        return (0);
	trim_space(str, &index);
	if (valid_kv(str, value, index, ':') == 0)
		return (0);
    index++;
    trim_space(str, &index);
    len = count_len(str, ' ', '~', &index);
    if (init_char(value, str, index, len) == 0)
        return (0);
	trim_space(str, &index);
    if (valid_kv(str, value, index, '\0') == 0)
		return (0);
	return (1);
}

int count_lines(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
    while (str[i][0])
    {
		if (str[i][0] != '\n')
			count++;
		i++;
    }
	return (count);
}

/*
int create_array(char *str, int len)
{
	str = (char *) malloc(len + 1);
	if (str == NULL)
	{
		free(str);
		return (0);
	}
	return (1);
}*/