/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/10 15:38:02 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_and(t_vm *vm, t_processus *processus)
{
	// ft_printf("~~~AND~~~\n");
	int			error;
	t_action	*action;

	action = &(processus->action);
	error = 0;
	if (action->type[0] == REG)
		action->args[ARG1] = ft_get_reg(processus, ARG1, &error);
	else if (action->type[0] == IND)
		action->args[ARG1] = ft_get_ind(vm, processus, ARG1);
	if (action->type[1] == REG)
		action->args[ARG2] = ft_get_reg(processus, ARG2, &error);
	else if (action->type[1] == IND)
		action->args[ARG2] = ft_get_ind(vm, processus, ARG2);
	if (error == 0 && action->args[2] >= 1 && action->args[2] <= 16)
	{
		processus->reg[action->args[2]] = action->args[0] & action->args[1];
		processus->carry = 1;
		if ((*vm).verbose)
			ft_print_add(processus, action->args[0], action->args[1], action->args[2]);
	}

}

void	ft_or(t_vm *vm, t_processus *processus)
{
	int			error;
	t_action	*action;

	action = &(processus->action);
	error = 0;
	if (action->type[0] == REG)
		action->args[ARG1] = ft_get_reg(processus, ARG1, &error);
	else if (action->type[0] == IND)
		action->args[ARG1] = ft_get_ind(vm, processus, ARG1);
	if (action->type[1] == REG)
		action->args[ARG2] = ft_get_reg(processus, ARG2, &error);
	else if (action->type[1] == IND)
		action->args[ARG2] = ft_get_ind(vm, processus, ARG2);
	if (error == 0 && action->args[2] >= 1 && action->args[2] <= 16)
	{
		processus->reg[action->args[2]] = action->args[0] | action->args[1];
		processus->carry = 1;
		if ((*vm).verbose)
			ft_print_or(processus, action->args[0], action->args[1], action->args[2]);
	}
}

void	ft_xor(t_vm *vm, t_processus *processus)
{
	int			error;
	t_action	*action;

	action = &(processus->action);
	error = 0;
	if (action->type[0] == REG)
		action->args[ARG1] = ft_get_reg(processus, ARG1, &error);
	else if (action->type[0] == IND)
		action->args[ARG1] = ft_get_ind(vm, processus, ARG1);
	if (action->type[1] == REG)
		action->args[ARG2] = ft_get_reg(processus, ARG2, &error);
	else if (action->type[1] == IND)
		action->args[ARG2] = ft_get_ind(vm, processus, ARG2);
	if (error == 0 && action->args[2] >= 1 && action->args[2] <= 16)
	{
		processus->reg[action->args[2]] = action->args[0] ^ action->args[1];
		processus->carry = 1;
		if ((*vm).verbose)
			ft_print_xor(processus, action->args[0], action->args[1], action->args[2]);
	}
}

void	ft_zjump(t_vm *vm, t_processus *processus)
{
	short	a;

	(void)vm;
	// ft_printf("~~~JUMP~~~\n");
	if (processus->carry == 1)
	{
		a = processus->action.args[0];
		a = (a % IDX_MOD);
		processus->PC = circular(processus->action.pc + a);
		if ((*vm).verbose)
			ft_print_zjump(processus, a);
	}
}


void	ft_ldi(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 bytes
	// ft_printf("~~~LD~~~\n");
	int			error;
	int			address;
	t_action	*action;

	action = &(processus->action);
	error = 0;
	if (action->type[0] == REG)
		action->args[ARG1] = ft_get_reg(processus, ARG1, &error);
	else if (action->type[0] == IND)
		action->args[ARG1] = ft_get_ind(vm, processus, ARG1);
	if (action->type[1] == REG)
		action->args[ARG2] = ft_get_reg(processus, ARG2, &error);
	else if (action->type[1] == IND)
		action->args[ARG2] = ft_get_ind(vm, processus, ARG2);
	if (error == 0 && action->args[2] >= 1 && action->args[2] <= 16)
	{
		address = circular(action->pc + (action->args[0] + action->args[1]));
		processus->reg[action->args[2]] = ft_octet_to_int2((*vm).ram, REG_SIZE, address);
		processus->carry = 1;
		if ((*vm).verbose)
			ft_print_ldi(processus, action->args[0], action->args[1], action->args[2]);
	}
}
