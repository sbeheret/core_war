/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/06 18:36:26 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_and(t_vm *vm, t_processus *processus)
{
	//DIRECT 4 BYTES
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
	//DIRECT 4 BYTES
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
	//DIRECT 4 BYTES
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
	//DIRECT 2 BYTES
	short	a;

	(void)vm;
	// ft_printf("~~~JUMP~~~\n");
	if (processus->carry == 1)
	{
		a = processus->action.args[0];
		// ft_printf("a before modulo = %hd\n", a);
		// ft_printf("a short before modulo = %hd\n", a);
		a = (a % IDX_MOD);
		// if (a < 0)
			// a++;
		processus->PC = circular(processus->action.pc + a);
		// ft_printf("a = %hd, action.pc = %hd, processus.pc = %hd\n", a, processus->action.pc, processus->PC);
	}
}

void	ft_ldi(t_vm *vm, t_processus *processus)
{
	//DIRECT 2 BYTES
	(void)processus;
	int		value1;
	int		value2;

	// ft_printf("~~~LDI~~~\n");
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
