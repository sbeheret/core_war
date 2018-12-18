/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/17 12:01:01 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Faire dans get action la verificaiton Nb_arg
*/

#include "corewar.h"

void	ft_live(t_vm *vm, t_processus *processus)
{
	int			champion;
	t_action	action;

	action = processus->action;
	champion = ft_octet_to_int2((*vm).ram, 4, circular(action.pc + 1));
	update_lives(champion, vm, vm->champion);
	if ((*vm).flag_operand)
		ft_print_live(processus->processus_number, champion);
	processus->lives++;
}

void	ft_ld(t_vm *vm, t_processus *processus)
{
	int				arg1;
	int				arg2;
	int				address;

	arg2 = (*processus).action.args[ARG2];
	arg1 = (*processus).action.args[ARG1];
	if ((*processus).action.type[ARG1] == IND)
	{
		address = circular((*processus).action.pc + ((short)arg1 % IDX_MOD));
		arg1 = ft_octet_to_int2((*vm).ram, REG_SIZE, address);
	}
	if ((processus->reg[arg2] = arg1) == 0)
		processus->carry = 1;
	else
		processus->carry = 0;
	if ((*vm).flag_operand)
		ft_print_ld(processus, arg1, arg2);
}

void	ft_st(t_vm *vm, t_processus *processus)
{
	int				address;
	t_action		action;

	action = processus->action;
	if (action.type[1] == REG)
		processus->reg[action.args[1]] = processus->reg[action.args[0]];
	else
	{
		address = circular(action.pc + ((short)action.args[1] % IDX_MOD));
		ft_int_to_octet((*vm).ram, processus->reg[action.args[0]], address);
		if (vm->visu)
			write_in_ram(vm->ram, processus, address);
	}
	if ((*vm).flag_operand)
		ft_print_st(processus, action.args[0], action.args[1]);
}

void	ft_add(t_vm *vm, t_processus *processus)
{
	int				arg1;
	int				arg2;
	int				arg3;

	arg1 = processus->action.args[0];
	arg2 = processus->action.args[1];
	arg3 = processus->action.args[2];
	processus->reg[arg3] = processus->reg[arg1] + processus->reg[arg2];
	if (!processus->reg[arg3])
		processus->carry = 1;
	else
		processus->carry = 0;
	if ((*vm).flag_operand)
		ft_print_add(processus, arg1, arg2, arg3);
}

void	ft_sub(t_vm *vm, t_processus *processus)
{
	int				arg1;
	int				arg2;
	int				arg3;

	arg1 = processus->action.args[0];
	arg2 = processus->action.args[1];
	arg3 = processus->action.args[2];
	processus->reg[arg3] = processus->reg[arg1] - processus->reg[arg2];
	if (!processus->reg[arg3])
		processus->carry = 1;
	else
		processus->carry = 0;
	if ((*vm).flag_operand)
		ft_print_sub(processus, arg1, arg2, arg3);
}
