/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/13 14:52:49 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_live(int processus, unsigned int champion)
{
	ft_printf("P\t%d | live %d\n", processus, champion);
}

void	ft_print_ld(t_processus *processus, int arg1, int arg2)
{
	ft_printf("P\t%d | ld %d r%d\tcarry = %d\n", processus->processus_number
	, arg1, arg2, processus->carry);
}

void	ft_print_st(t_processus *processus, int arg1, int arg2)
{
	ft_printf("P\t%d | st r%d (%#x)\t", processus->processus_number, arg1,
	processus->reg[arg1]);
	if ((*processus).action.type[ARG2] == REG)
		ft_printf("r");
	ft_printf("%hd\tcarry = %d\n", arg2, processus->carry);
}

void	ft_print_add(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P\t%d | add r%d r%d r%d | r3 = r1 + r2 (%d = %d + %d)\n",
	processus->processus_number, arg1, arg2, arg3,
	(*processus).reg[arg3], (*processus).reg[arg1], (*processus).reg[arg2]);
}

void	ft_print_sub(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P\t%d | sub r%d r%d r%d | r3 = r1 - r2 (%d = %d - %d)\n",
	processus->processus_number, arg1, arg2, arg3,
	(*processus).reg[arg3], (*processus).reg[arg1], (*processus).reg[arg2]);
}
