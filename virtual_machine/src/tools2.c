/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:52:03 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/29 15:17:22 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_processus(t_processus *pcs)
{
	t_processus		*tmp;
	int				breaker;

	breaker = 1;
	tmp = pcs;
	while (tmp != pcs || breaker)
	{
		breaker = 0;
		ft_printf("---------Processus-----------\n");
		ft_printf("PC = %d\n", tmp->PC);
		ft_printf("Carry = %d\n", tmp->carry);
		ft_printf("Registres 1 to 8: %d-%d-%d-%d-%d-%d-%d-%d\n", tmp->reg[0],
				tmp->reg[1], tmp->reg[2], tmp->reg[3], tmp->reg[4],
				tmp->reg[5], tmp->reg[6], tmp->reg[7]);
		ft_printf("Cycles to wait = %d\n", tmp->cycles_wait);
		ft_printf("Lives = %d\n", tmp->lives);
		print_action(tmp->action);
		tmp = tmp->next;
	ft_printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	}
}

void	print_action(t_action *act)
{
	t_action	*tmp;
	int			i;

	i = -1;
	if (act == NULL)
		return ;
	tmp = act;
	ft_printf("----------ACTION-----------\n");
	ft_printf("op_code = %d\n", tmp->op_code);
	ft_printf("nb_args = %d\n", tmp->nb_arg);
	while (++i < tmp->nb_arg)
		ft_printf("argument %d = %d\n", i, tmp->args[i]);
	ft_printf("4 types %d - %d - %d - %d\n", tmp->type[0], tmp->type[1],
			tmp->type[2], tmp->type[3]);
	ft_printf("size read = %d\n", tmp->size_read);
	return ;
}
