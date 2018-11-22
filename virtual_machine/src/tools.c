/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:06:58 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/21 15:47:14 by rfibigr          ###   ########.fr       */
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
		ft_printf("%hhd", ram[i] / 16);
		ft_printf("%hhd", ram[i] % 16);
		ft_printf(" ");
		i++;
	}
}
