/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 14:26:28 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_sti(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P% 5d | sti r%d ", processus->processus_number, arg1);
	ft_printf("%d ", arg2);
	ft_printf("%d\n", arg3);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", arg2,
	arg3, arg3 + arg2, processus->action.pc + (arg3 + arg2));
}

void	ft_print_fork(t_processus *processus, int arg)
{
	ft_printf("P% 5d | fork %d (%d)\n", processus->processus_number, arg
	, arg + processus->action.pc);
}

void	ft_print_lld(t_processus *processus, int arg1, int arg2)
{
	ft_printf("P% 5d | lld %d r%d\n", processus->processus_number, arg1, arg2);
}

void	ft_print_lldi(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P% 5d | ldi r%d ", processus->processus_number, arg3);
	if ((*processus).action.type[ARG1] == REG)
		ft_printf("r");
	ft_printf("%d ", arg1);
	if ((*processus).action.type[ARG2] == REG)
		ft_printf("r");
	ft_printf("%d\n", arg2);
}

void	ft_print_lfork(t_processus *processus, int arg)
{
	ft_printf("P% 5d | lfork %d (%d)\n", processus->processus_number, arg
	, arg + processus->action.pc);
}
