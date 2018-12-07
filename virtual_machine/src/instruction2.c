/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/07 16:23:19 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_and(t_vm *vm, t_processus *processus)
{
	(void)vm;
	int		value1;
	int		value2;

	// ft_printf("~~~AND~~~\n");
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
	processus->reg[processus->action.args[2] - 1] = value1 & value2;
	processus->carry = 1;
}

void	ft_or(t_vm *vm, t_processus *processus)
{
	(void)vm;
	int		value1;
	int		value2;

	// ft_printf("~~~OR~~~\n");
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
	processus->reg[processus->action.args[2] - 1] = value1 | value2;
	processus->carry = 1;
}

void	ft_xor(t_vm *vm, t_processus *processus)
{
	(void)vm;
	int		value1;
	int		value2;

	// ft_printf("~~~XOR~~~\n");
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
	processus->reg[processus->action.args[2] - 1] = value1 ^ value2;
	processus->carry = 1;
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
		// if (a < 0)
			// a++;
		processus->PC = circular(processus->action.pc + a);
		// ft_printf("a = %hd, action.pc = %hd, processus.pc = %hd\n", a, processus->action.pc, processus->PC);
	}
}


void	ft_ldi(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 bytes
	t_action		action;
	int				arg1;
	int				arg2;
	int				arg3;
	int				address;

	// ft_printf("~~~LD~~~\n");
	action = processus->action;

	//calcul valeur arg1--------------------------
	if (action.type[ARG1] == REG)
	{
		if (action.args[ARG1] < 1 || action.args[ARG1] > 16)
			return;
		arg1 = processus->reg[action.args[ARG1]];
	}
	else if (action.type[ARG1] == DIR)
		arg1 = (short)action.args[ARG1];
	else if (action.type[ARG1] == IND)
	{
		address = circular(processus->PC + action.args[ARG1]);
		arg1 = ft_octet_to_int2((*vm).ram, IND_SIZE, address);
	}
	else
		return;

	//calcul valeur arg2---------------------------
	if (action.type[ARG2] == REG)
	{
		if (action.args[ARG2] < 1 || action.args[ARG2] > 16)
			return;
		arg2 = processus->reg[action.args[ARG2]];
	}
	else if (action.type[ARG2] == DIR)
		arg2 = (short)action.args[ARG2];
	else if (action.type[ARG2] == IND)
		return;

	//calcul valeur arg3---------------------------
	if (action.type[ARG3] == REG)
	{
		if (action.args[ARG3] < 1 || action.args[ARG3] > 16)
			return;
		arg3 = action.args[ARG3];
	}
	else
		return;

	//calcul valeur LDI---------------------------
	address = circular(processus->PC + (arg1 + arg2));
	processus->reg[arg3] = ft_octet_to_int2((*vm).ram, REG_SIZE, address);
	processus->carry = 1;
}
