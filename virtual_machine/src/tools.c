/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:06:58 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 14:48:41 by rfibigr          ###   ########.fr       */
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
			ft_printf("0X");
			ft_printf("%.4X : ", i);
		}
		ft_printf("%hhx", ram[i] / 16);
		ft_printf("%hhx", ram[i] % 16);
		ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

void	print_memory(unsigned char *str, size_t size)
{
	size_t start;
	size_t i;

	start = 0;
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
}

void	print_action(t_action act)
{
	int			i;

	i = -1;
	ft_printf("----------ACTION-----------\n");
	ft_printf("op_code = %d\n", act.op_code);
	ft_printf("PC = %d\n", act.pc);
	ft_printf("nb_args = %d\n", act.nb_arg);
	while (++i < act.nb_arg)
		ft_printf("argument %d = %d\n", i, act.args[i]);
	ft_printf("4 types %d / %d / %d / %d\n", act.type[0], act.type[1],
			act.type[2], act.type[3]);
	ft_printf("size read = %d\n", act.size_read);
	return ;
}

void	print_processus(t_processus *pcs)
{
	t_processus		*tmp;
	int				breaker;

	breaker = 1;
	tmp = pcs;
	while ((tmp != pcs || breaker) && tmp)
	{
		breaker = 0;
		ft_printf("---------Processus-----------\n");
		ft_printf("Number = %d\n", tmp->processus_number);
		ft_printf("PC = %d\n", tmp->pc);
		ft_printf("Carry = %d\n", tmp->carry);
		ft_printf("Registres 1 to 8: %#d-%d-%d-%d-%d-%d-%d-%d\n",
				tmp->reg[1], tmp->reg[2], tmp->reg[3], tmp->reg[4],
				tmp->reg[5], tmp->reg[6], tmp->reg[7], tmp->reg[8]);
		ft_printf("Registres 9 to 16: %#d-%d-%d-%d-%d-%d-%d-%d\n", tmp->reg[9],
				tmp->reg[10], tmp->reg[11], tmp->reg[12], tmp->reg[13],
				tmp->reg[14], tmp->reg[15], tmp->reg[16]);
		ft_printf("Cycles to wait = %d\n", tmp->cycles_wait);
		ft_printf("Lives = %d\n", tmp->lives);
		print_action(tmp->action);
		tmp = tmp->next;
		ft_printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	}
}
