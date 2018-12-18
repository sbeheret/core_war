/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:07:21 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 18:16:47 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_octet_to_int(unsigned char **binary, int nb_octect)
{
	int		value;

	value = 0;
	value = value | **binary;
	*binary = *binary + 1;
	value = value << 8;
	value = value | **binary;
	if (nb_octect == 4)
	{
		*binary = *binary + 1;
		value = value << 8;
		value = value | **binary;
		*binary = *binary + 1;
		value = value << 8;
		value = value | **binary;
	}
	*binary = *binary + 1;
	return (value);
}

int		ft_octet_to_int2(unsigned char *binary, int nb_octect, int index)
{
	int		value;
	int		i;

	i = 0;
	value = 0;
	while (i < nb_octect)
	{
		value = value << 8;
		value = value | binary[index];
		index = circular(index + 1);
		i++;
	}
	return (value);
}

char	*ft_octet_to_char(unsigned char **binary, size_t lenght_max)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)ft_strnew(lenght_max)))
		ft_exit_malloc();
	i = 0;
	while (i < lenght_max)
	{
		str[i] = **binary;
		i++;
		*binary = *binary + 1;
	}
	if (str[0] == 0)
	{
		if (lenght_max == PROG_NAME_LENGTH)
			ft_strcpy(str, "No name");
		if (lenght_max == COMMENT_LENGTH)
			ft_strcpy(str, "No comment");
	}
	return (str);
}

void	ft_int_to_octet(unsigned char *binary, int value, int id)
{
	binary[circular(id)] = value >> 24;
	binary[circular(id + 1)] = (value & 0x00FF0000) >> 16;
	binary[circular(id + 2)] = (value & 0x0000FF00) >> 8;
	binary[circular(id + 3)] = value & 0x000000FF;
}

int		circular(int i)
{
	if (i < 0)
		return (MEM_SIZE + i % MEM_SIZE);
	return (i % MEM_SIZE);
}
