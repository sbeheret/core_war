/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:06:58 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/22 16:54:32 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_ram(unsigned char *ram)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (!(i % 64))
		{
			ft_printf("\n");
			ft_printf("%p : ",ram + i);
		}
		ft_printf("%hhx", ram[i] / 16);
		ft_printf("%hhx", ram[i] % 16);
		ft_printf(" ");
		i++;
	}
}

void	ft_print_memory(unsigned char *str, size_t size)
{
	size_t start;
	size_t i;

	start = 0;
	ft_printf("\n================ FT_PRINT_MEMORY =============\n");
	while (start < size)
	{
		ft_printf("%.10x :", start);
		i = start;
		while (i < start + 16 && i < size)
		{
			ft_printf("%hhx", str[i] / 16);
			ft_printf("%hhx", str[i] % 16);
			ft_putchar(' ');
			i++;
		}
		while (i < start + 16)
		{
			ft_putstr("   ");
			i++;
		}
		ft_putchar('|');
		i = start;
		while (i < start + 16 && i < size)
		{
			if (str[i] > 31 && str[i] < 127)
				ft_putchar(str[i]);
			else
				ft_putchar('.');
			i++;
		}
		ft_putchar('|');
		ft_putchar('\n');
		start += 16;
	}
	ft_printf("\n============= END FT_PRINT_MEMORY =============\n");
}
