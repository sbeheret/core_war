/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:07:21 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/29 18:34:32 by rfibigr          ###   ########.fr       */
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
	return (str);
}

int		circular(int i)
{
	return (i % MEM_SIZE);
}
