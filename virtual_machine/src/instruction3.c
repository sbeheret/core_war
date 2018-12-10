/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/10 15:35:23 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sti(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 bytes
	int			error;
	t_action	action;
	int			address;

	action = processus->action;
	if (action.type[1] == REG)
		action.args[ARG2] = ft_get_reg(processus, ARG2, &error);
	else if (action.type[1] == IND)
		action.args[ARG2] = ft_get_ind(vm, processus, ARG2);
	if (action.type[2] == REG)
		action.args[ARG3] = ft_get_reg(processus, ARG3, &error);
	if (error == 0 && action.args[0] >= 1 && action.args[0] <= 16)
	{
		address = circular(action.pc + ((action.args[ARG2] + action.args[ARG3]) % IDX_MOD));
		ft_int_to_octet((*vm).ram, processus->reg[action.args[ARG1]], address);
		if (vm->visu)
			write_in_ram(vm->ram, processus, address);
		if ((*vm).verbose)
			ft_print_sti(processus, action.args[0], action.args[1], action.args[2]);
		processus->carry = 1;
	}
}

void	ft_fork(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 BYTES
	t_processus *copy;
	int	i;

	if (processus->action.type[ARG1] != 2)
		return;
	copy = new_processus(0,(circular(processus->action.pc +
	(short)processus->action.args[ARG1]) % IDX_MOD), processus->color);
	i = 0;
	while (++i <= 16)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;
	get_action(vm, copy);
	push_front_pcs(&(*vm).processus, copy);
	processus->PC = circular(processus->action.pc + 3);
	if ((*vm).verbose)
		ft_print_fork(processus, processus->action.args[ARG1] % IDX_MOD);
}

void	ft_lld(t_vm *vm, t_processus *processus)
{
	int				arg1;
	int				arg2;
	int				address;

	if ((*processus).action.nb_arg != 2 || (*processus).action.type[ARG1] == REG
		|| (*processus).action.type[ARG2] != REG)
		return ;
	arg2 = (*processus).action.args[ARG2];
	if (arg2 < 1 || arg2 > 16)
		return ;
	arg1 = (*processus).action.args[ARG1];
	if ((*processus).action.type[ARG1] == IND)
	{
		address = circular((*processus).action.pc + (short)arg1);
		arg1 = ft_octet_to_int2((*vm).ram, REG_SIZE, address);
	}
	processus->reg[arg2] = arg1;
	processus->carry = 1;
	if ((*vm).verbose)
		ft_print_lld(processus, arg1, arg2);
}

void	ft_lldi(t_vm *vm, t_processus *processus)
{
	int			error;
	int			address;
	t_action	*action;

	action = &(processus->action);
	error = 0;
	if (action->type[0] == REG)
		action->args[ARG1] = ft_get_reg(processus, ARG1, &error);
	else if (action->type[0] == IND)
		action->args[ARG1] = ft_get_lind(vm, processus, ARG1);
	if (action->type[1] == REG)
		action->args[ARG2] = ft_get_reg(processus, ARG2, &error);
	else if (action->type[1] == IND)
		action->args[ARG2] = ft_get_lind(vm, processus, ARG2);
	if (error == 0 && action->args[2] >= 1 && action->args[2] <= 16)
	{
		address = circular(action->pc + (action->args[0] + action->args[1]));
		processus->reg[action->args[2]] = ft_octet_to_int2((*vm).ram, REG_SIZE, address);
		processus->carry = 1;
		if ((*vm).verbose)
			ft_print_lldi(processus, action->args[0], action->args[1], action->args[2]);
	}
}

void	ft_lfork(t_vm *vm, t_processus *processus)
{
	t_processus *copy;
	int	i;

	if (processus->action.type[ARG1] != 2)
		return;
	copy = new_processus(0,(circular(processus->action.pc +
	(short)processus->action.args[ARG1])), processus->color);
	i = 0;
	while (++i <= 16)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;
	get_action(vm, copy);
	push_front_pcs(&(*vm).processus, copy);
	processus->PC = circular(processus->action.pc + 3);
	if ((*vm).verbose)
		ft_print_fork(processus, processus->action.args[ARG1]);
}
