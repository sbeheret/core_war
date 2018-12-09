/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/09 16:15:06 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sti(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 bytes
	t_action		action;
	int				arg1;
	int				arg2;
	int				arg3;
	int				address;

	action = processus->action;
	//calcul valeur arg1--------------------------
	if (action.type[ARG1] == REG)
	{
		if (action.args[ARG1] < 1 || action.args[ARG1] > 16)
			return;
		arg3 = action.args[ARG3];
	}
	else
		return;

	//calcul valeur arg2---------------------------
	if (action.type[ARG2] == REG)
	{
		if (action.args[ARG2] < 1 || action.args[ARG2] > 16)
			return;
		arg1 = processus->reg[action.args[ARG2]];
	}
	else if (action.type[ARG2] == DIR)
		arg2 = (short)action.args[ARG2];
	else if (action.type[ARG2] == IND)
	{
		address = circular(action.pc + (action.args[ARG2] % IDX_MOD));
		arg2 = ft_octet_to_int2((*vm).ram, IND_SIZE, address);
	}
	else
		return;

	//calcul valeur arg2---------------------------
	if (action.type[ARG3] == REG)
	{
		if (action.args[ARG3] < 1 || action.args[ARG3] > 16)
			return;
		arg3 = processus->reg[action.args[ARG3]];
	}
	else if (action.type[ARG3] == DIR)
		arg3 = (short)action.args[ARG3];
	else if (action.type[ARG3] == IND)
		return;

	//calcul valeur arg3---------------------------

	//calcul valeur LDI---------------------------
	address = circular(action.pc + ((arg2 + arg3) % IDX_MOD));
	ft_int_to_octet((*vm).ram, processus->reg[arg1], address);
	if (vm->visu)
		write_in_ram(vm->ram, processus, address);
	processus->carry = 1;
}

void	ft_fork(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 BYTES
	t_processus *copy;
	int	i;

	if (processus->action.type[ARG1] != 2)
		return;
	copy = new_processus(0, ((short)circular(processus->action.pc + processus->action.args[ARG1]) % IDX_MOD));
	i = -1;
	while (++i <= 16)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;

	get_action(vm, copy);
	push_front_pcs(&(*vm).processus, copy);
	processus->PC = circular(processus->action.pc + 3);
}

void	ft_lld(t_vm *vm, t_processus *processus)
{
	//DIRECT 4 BYTES
	(void)vm;
	int		registre;

	//ft_printf("~~~LLD~~~\n");
	registre = processus->action.args[1];
	if (registre < 1 || registre > 16)
		return ;
	processus->reg[registre - 1] = processus->action.args[0];
	//load value first arg in register (2nd arg)
}

void	ft_lldi(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 BYTES
	int		value1;
	int		value2;

	//ft_printf("~~~LLDI~~~\n");
	if (processus->action.args[2] < 1 || processus->action.args[2] > 16)
		return ;
	if (processus->action.type[0] == 1)
		value1 = processus->reg[processus->action.args[0] - 1];
	else
		value1 = processus->action.args[0];
	if (processus->action.type[1] == 1)
		value2 = processus->reg[processus->action.args[1] - 1];
	else
		value2 = processus->action.args[1];
	processus->reg[processus->action.args[2] - 1] = ft_octet_to_int2(vm->ram,
			4, circular(value1 + value2));
}

void	ft_lfork(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 BYTES
	t_processus *copy;
	int	i;

	copy = new_processus(0, processus->PC, processus->color);
	i = -1;
	while (++i <= 15)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;
	push_front_pcs(&(*vm).processus, copy);
}
