/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/11 12:35:33 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_aff(t_vm *vm, t_processus *processus)
{
	(void)vm;
	t_action		action;
	int				arg1;

	action = processus->action;
	arg1 = action.args[0];
	if (arg1 < 1 || arg1 > 16)
		return;
	if (action.type[1] == REG && arg1 > 1 && arg1 < 16)
	{
		if (!vm->visu)
			ft_printf("%c", processus->reg[arg1] % 256);
		return;
	}
}

int		ft_get_reg(t_processus *processus, int arg, int *error)
{
	if (processus->action.args[arg] < 1 || processus->action.args[arg] > 16)
		*error = 1;
	return(processus->reg[processus->action.args[arg]]);
}

int		ft_get_ind(t_vm *vm, t_processus *processus, int arg)
{
	int				address;
	short			argument;
	(void)*vm;

//	ft_printf("action args = %d \n", processus->action.args[arg]);
	argument = (short)(*processus).action.args[arg];
//	ft_printf("argument = %hd \n", argument);
	address = circular((*processus).action.pc + (argument % IDX_MOD));
//	ft_printf("adress = %hd \n", address);
	// return(ft_octet_to_int2((*vm).ram, REG_SIZE, address));
	return(address);
}

int		ft_get_lind(t_vm *vm, t_processus *processus, int arg)
{
	int				address;
	int				argument;

	argument = (*processus).action.args[arg];
	address = circular((*processus).action.pc + (short)argument);
	return(ft_octet_to_int2((*vm).ram, REG_SIZE, address));
}
