/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:06:58 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 15:37:55 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_memory_hexa(unsigned char *str, size_t *i)
{
	ft_printf("%hhx", str[*i] / 16);
	ft_printf("%hhx", str[*i] % 16);
	ft_putchar(' ');
	*i = *i + 1;
}

static void	print_memory_ascii(unsigned char *str, size_t *i)
{
	if (str[*i] > 31 && str[*i] < 127)
		ft_putchar(str[*i]);
	else
		ft_putchar('.');
	*i = *i + 1;
}

void		print_memory(unsigned char *str, size_t size)
{
	size_t start;
	size_t i;

	start = 0;
	while (start < size)
	{
		ft_printf("%.10x :", start);
		i = start;
		while (i < start + 16 && i < size)
			print_memory_hexa(str, &i);
		while (i < start + 16)
		{
			ft_putstr("   ");
			i++;
		}
		ft_putchar('|');
		i = start;
		while (i < start + 16 && i < size)
			print_memory_ascii(str, &i);
		ft_putchar('|');
		ft_putchar('\n');
		start += 16;
	}
}
