/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/17 13:11:26 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_and(t_vm *vm, t_processus *pcs)
{
	int			value1;
	int			value2;
	t_action	*action;

	action = &(pcs->action);
	value1 = get_content_value(vm->ram, pcs, action->type[0], action->args[0]);
	value2 = get_content_value(vm->ram, pcs, action->type[1], action->args[1]);
	if ((pcs->reg[action->args[2]] = value1 & value2) == 0)
		pcs->carry = 1;
	else
		pcs->carry = 0;
	if ((*vm).flag_operand)
		ft_print_and(pcs, action->args[0], action->args[1], action->args[2]);
}

void	ft_or(t_vm *vm, t_processus *pcs)
{
	int			value1;
	int			value2;
	t_action	*action;

	action = &(pcs->action);
	value1 = get_content_value(vm->ram, pcs, action->type[0], action->args[0]);
	value2 = get_content_value(vm->ram, pcs, action->type[1], action->args[1]);
	if ((pcs->reg[action->args[2]] = value1 | value2) == 0)
		pcs->carry = 1;
	else
		pcs->carry = 0;
	if ((*vm).flag_operand)
		ft_print_or(pcs, action->args[0], action->args[1], action->args[2]);
}

void	ft_xor(t_vm *vm, t_processus *pcs)
{
	int			value1;
	int			value2;
	t_action	*action;

	action = &(pcs->action);
	value1 = get_content_value(vm->ram, pcs, action->type[0], action->args[0]);
	value2 = get_content_value(vm->ram, pcs, action->type[1], action->args[1]);
	if ((pcs->reg[action->args[2]] = value1 ^ value2) == 0)
		pcs->carry = 1;
	else
		pcs->carry = 0;
	if ((*vm).flag_operand)
		ft_print_xor(pcs, value1, value2, action->args[2]);
}

void	ft_zjump(t_vm *vm, t_processus *processus)
{
	short	a;

	a = (short)processus->action.args[0];
	a = (a % IDX_MOD);
	if (processus->carry == 1)
		processus->pc = circular(processus->action.pc + a);
	if ((*vm).flag_operand)
		ft_print_zjump(processus, (short)processus->action.args[0]);
}

void	ft_ldi(t_vm *vm, t_processus *pcs)
{
	t_action	*action;
	int			value1;
	int			value2;
	int			addrs;

	action = &(pcs->action);
	value1 = get_content_value(vm->ram, pcs, action->type[0], action->args[0]);
	value2 = get_content_value(vm->ram, pcs, action->type[1], action->args[1]);
	if (action->type[0] != 1)
		value1 = (short)value1;
	if (action->type[1] != 1)
		value2 = (short)value2;
	addrs = circular(pcs->action.pc + ((value1 + value2) % IDX_MOD));
	pcs->reg[pcs->action.args[2]] = ft_octet_to_int2(vm->ram, REG_SIZE, addrs);
	if (pcs->reg[pcs->action.args[2]] == 0)
		pcs->carry = 1;
	else
		pcs->carry = 0;
	if ((*vm).flag_operand)
		ft_print_ldi(pcs, value1, value2, action->args[2]);
}
