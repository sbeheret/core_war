/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/13 10:43:47 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_and(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P\t%d | and r%d ", processus->processus_number, arg3);
	if ((*processus).action.type[ARG1] == REG)
		ft_printf("r");
	ft_printf("%d ",arg1);
	if ((*processus).action.type[ARG2] == REG)
		ft_printf("r");
	ft_printf("%d\n",arg2);

}

void	ft_print_or(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P\t%d | or r%d ", processus->processus_number, arg3);
	if ((*processus).action.type[ARG1] == REG)
		ft_printf("r");
	ft_printf("%d ",arg1);
	if ((*processus).action.type[ARG2] == REG)
		ft_printf("r");
	ft_printf("%d\n",arg2);

}

void	ft_print_xor(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P\t%d | zor r%d ", processus->processus_number, arg3);
	if ((*processus).action.type[ARG1] == REG)
		ft_printf("r");
	ft_printf("%d ",arg1);
	if ((*processus).action.type[ARG2] == REG)
		ft_printf("r");
	ft_printf("%d\n",arg2);
}

void	ft_print_zjump(t_processus *processus, int jump)
{
	if (processus->carry == 1)
		ft_printf("P\t%d | zjump %d %s (%d)\n", processus->processus_number
		,jump, "OK\0", processus->action.pc + jump);
	else
		ft_printf("P\t%d | zjump %d %s\n", processus->processus_number, jump,
		"FAIL\0");

}

void	ft_print_ldi(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P\t%d | ldi ", processus->processus_number);
	ft_printf("%d ", arg1);
	ft_printf("%d ", arg2);
	ft_printf("r%d\n", arg3);
}
