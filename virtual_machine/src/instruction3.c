/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/13 10:52:33 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//sti r2,%4,%5 sti copie REG_SIZE octet de r2 a l’adresse (4 + 5)
//Les paramètres 2 et 3 sont des index. Si les paramètres 2 ou 3
//sont des registres, on utilisera leur contenu comme un index.
//T_REG,
//T_REG | T_DIR | T_IND,
//T_DIR | T_REG
// IND = valeur a l'adresse;

void	ft_sti(t_vm *vm, t_processus *pcs)
{
	//DIRECT 2 bytes
	t_action	action;
	int			address;
	int			value1;
	int			value2;

	action = pcs->action;
	value1 = get_content_value(vm->ram, pcs, pcs->action.type[1],
			pcs->action.args[1]);
	value2 = get_content_value(vm->ram, pcs, pcs->action.type[2],
			pcs->action.args[2]);
	address = circular(action.pc + ((value1 + value2) % IDX_MOD));
	ft_int_to_octet((*vm).ram, pcs->reg[action.args[0]], address);
	if (vm->visu)
		write_in_ram(vm->ram, pcs, address);
	if ((*vm).verbose)
		ft_print_sti(pcs, action.args[0], value1, value2);
}

void	ft_fork(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 BYTES
	t_processus *copy;
	t_processus *tmp;
	int	i;

	tmp = NULL;
	if (processus->action.type[ARG1] != 2)
		return;
	copy = new_processus(0,(circular(processus->action.pc +
	((short)processus->action.args[ARG1] % IDX_MOD))), processus->color);
	i = 0;
	while (++i <= 16)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;
	get_action(vm, copy);
	copy->cycles_wait--;
	// if (processus->next)
	// 	tmp = processus->next;
	// processus->next = copy;
	// copy->next = tmp;
	push_front_pcs(&(*vm).processus, copy);
	// print_processus((*vm).processus);
	processus->PC = circular(processus->action.pc + 3);
	if ((*vm).verbose)
		ft_print_fork(processus, (short)processus->action.args[ARG1] % IDX_MOD);
}

void	ft_lld(t_vm *vm, t_processus *processus)
{
	int				arg1;
	int				arg2;
	int				address;

	arg2 = (*processus).action.args[1];
	arg1 = (*processus).action.args[0];
	if ((*processus).action.type[ARG1] == IND)
	{
		address = circular((*processus).action.pc + (short)arg1);
		arg1 = ft_octet_to_int2((*vm).ram, REG_SIZE, address);
	}
	if ((processus->reg[arg2] = arg1) == 0)
		processus->carry = 1;
	else
		processus->carry = 0;
	if ((*vm).verbose)
		ft_print_lld(processus, arg1, arg2);
}

void	ft_lldi(t_vm *vm, t_processus *pcs)
{
	t_action	*action;
	int			value1;
	int			value2;
	int			addrs;

	action = &(pcs->action);
	value1 = (short)get_long_content_value(vm->ram, pcs, action->type[0],
			action->args[0]);
	value2 = (short)get_long_content_value(vm->ram, pcs, action->type[1],
			action->args[2]);
	addrs = circular (pcs->action.pc + (value1 + value2));
	pcs->reg[pcs->action.args[2]] = ft_octet_to_int2(vm->ram, REG_SIZE, addrs);
	if (pcs->reg[pcs->action.args[2]] == 0)
		pcs->carry = 1;
	else
		pcs->carry = 0;
	if ((*vm).verbose)
		ft_print_lldi(pcs, action->args[0], action->args[1], action->args[2]);
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
		ft_print_fork(processus, (short)processus->action.args[ARG1]);
}
