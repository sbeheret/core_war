/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/12 17:49:04 by sbeheret         ###   ########.fr       */
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
	ft_printf("P\t%d | zjump %d (%d)\n", processus->processus_number,
	jump, processus->action.pc + jump);
}

void	ft_print_ldi(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P\t%d | ldi ", processus->processus_number);
	ft_printf("%d ", arg1);
	ft_printf("%d ", arg2);
	ft_printf("r%d\n", arg3);
}
