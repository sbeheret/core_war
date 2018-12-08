/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexatob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:36:00 by esouza            #+#    #+#             */
/*   Updated: 2018/12/08 12:29:25 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				binary_char_to_int(char *s)
{
	int			nb;

	nb = 0;
	while (*s)
	{
		nb <<= 1;
		if (*s++ == '1')
			nb ^= 1;
	}
	return (nb);
}

int32_t			swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}

unsigned int	hexatob(const char *ptr)
{
	unsigned int	value;
	char			ch;

	ch = *ptr;
	value = 0;
	while (ch == ' ' || ch == '\t')
		ch = *(++ptr);
	while (*ptr)
	{
		if (ch >= '0' && ch <= '9')
			value = (value << 4) + (ch - '0');
		else if (ch >= 'A' && ch <= 'F')
			value = (value << 4) + (ch - 'A' + 10);
		else if (ch >= 'a' && ch <= 'f')
			value = (value << 4) + (ch - 'a' + 10);
		else
			return (value);
		ch = *(++ptr);
	}
	return (value);
}
