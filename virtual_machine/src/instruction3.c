/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/30 17:27:18 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sti(t_vm *vm, t_processus *processus)
{
	int		value1;
	int		value2;
	int		i;

	i = -1;
	ft_printf("~~~STI~~~\n");
	if (processus->action.args[0] < 1 || processus->action.args[0] > 16)
		return ;
	if (processus->action.type[1] == 1)
		value1 = processus->reg[processus->action.args[1] - 1];
	else
		value1 = processus->action.args[1];
	if (processus->action.type[2] == 1)
		value2 = processus->reg[processus->action.args[2] - 1];
	else
		value2 = processus->action.args[2];
	ft_int_to_octet(&vm->ram, processus->reg[processus->action.args[0] - 1],
			circular(value1 + value2));
	// argments 1, 2 et 3
	// 2 + 3 = adresse
	// write 1 at adresse
}

void	ft_fork(t_vm *vm, t_processus *processus)
{
	t_processus *copy;
	int	i;

	copy = new_processus(0, processus->PC % IDX_MOD);
	i = -1;
	while (++i <= 15)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;
	push_front_pcs(&(*vm).processus, copy);
}

void	ft_lld(t_vm *vm, t_processus *processus)
{
	int		registre;

	ft_printf("~~~LLD~~~\n");
	registre = processus->action.args[1];
	if (registre < 1 || registre > 16)
		return ;
	processus->reg[registre - 1] = processus->action.args[0];
	//load value first arg in register (2nd arg)
}

void	ft_lldi(t_vm *vm, t_processus *processus)
{
	int		value1;
	int		value2;

	ft_printf("~~~LLDI~~~\n");
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
	t_processus *copy;
	int	i;

	copy = new_processus(0, processus->PC);
	i = -1;
	while (++i <= 15)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;
	push_front_pcs(&(*vm).processus, copy);
}
