/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 14:25:59 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_and(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P% 5d | and r%d ", processus->processus_number, arg3);
	if ((*processus).action.type[ARG1] == REG)
		ft_printf("r");
	ft_printf("%d ", arg1);
	if ((*processus).action.type[ARG2] == REG)
		ft_printf("r");
	ft_printf("%d\n", arg2);
}

void	ft_print_or(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P% 5d | or r%d ", processus->processus_number, arg3);
	if ((*processus).action.type[ARG1] == REG)
		ft_printf("r");
	ft_printf("%d ", arg1);
	if ((*processus).action.type[ARG2] == REG)
		ft_printf("r");
	ft_printf("%d\n", arg2);
}

void	ft_print_xor(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P% 5d | xor %d ", processus->processus_number, arg1);
	ft_printf("%d ", arg2);
	ft_printf("r%d\n", arg3);
}

void	ft_print_zjump(t_processus *processus, int jump)
{
	if (processus->carry == 1)
		ft_printf("P% 5d | zjmp %d %s\n", processus->processus_number
		, jump, "OK\0");
	else
		ft_printf("P% 5d | zjmp %d %s\n", processus->processus_number, jump,
		"FAILED\0");
}

void	ft_print_ldi(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P% 5d | ldi ", processus->processus_number);
	ft_printf("%d ", arg1);
	ft_printf("%d ", arg2);
	ft_printf("r%d\n", arg3);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", arg1,
	arg2, arg1 + arg2,
	circular(processus->action.pc + ((arg1 + arg2) % IDX_MOD)));
}
