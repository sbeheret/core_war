/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/30 17:07:38 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Faire dans get action les verifications des valeurs de registres
** Faire dans get action la verificaiton Nb_arg
*/

#include "corewar.h"

void	ft_live(t_vm *vm, t_processus *processus)
{
	int	champion;
	t_action		action;

	action = processus->action;
	champion = ft_octet_to_int2((*vm).ram, 4, action.pc + 1);
	processus->lives++;
	(*vm).last_alive = champion;
}

void	ft_ld(t_vm *vm, t_processus *processus)
{
	// est-ce que les valeurs sont bien des int
	t_action		action;
	int				arg1;
	int				arg2;


	action = processus->action;
	arg1 = action.args[0];
	arg2 = action.args[1];
	//get action ?
	if (action.nb_arg != 2 || action.type[0] == REG || action.type[1] != REG)
		return;
	//get action ?
	if (action.args[1] < 1 || action.args[1] > 16)
		return;
	//change carry
	if ((processus->reg[action.args[1] - 1] = (*vm).ram[action.pc + action.args[0]]))
		processus->carry = 1;
}

void	ft_st(t_vm *vm, t_processus *processus)
{
	// est-ce que les valeurs sont bien des int ou unsigned int
	t_action		action;
	int				arg1;
	int				arg2;


	action = processus->action;
	arg1 = action.args[0];
	arg2 = action.args[1];
	if (action.type[1] == REG)
	{
		processus->reg[arg1] = processus->reg[arg2];
		return;
	}
	//get action ?
	if (action.nb_arg != 2 || action.type[0] != REG || action.type[1] == DIR)
		return;
	//get action ?
	if (arg1 < 1 || arg1 > 16)
		return;
	if (action.type[1] == REG && (arg2 < 1 || arg2 > 16))
		return;
	ft_int_to_octet(&(*vm).ram, arg1, arg2);
}

void	ft_add(t_vm *vm, t_processus *processus)
{
	(void)vm;
	t_action		action;
	int				arg1;
	int				arg2;
	int				arg3;


	action = processus->action;
	arg1 = action.args[0];
	arg2 = action.args[1];
	arg3 = action.args[2];
	if (action.nb_arg != 3 || action.type[0] != REG || action.type[1] != REG ||
	action.type[2] != REG)
		return;
	if (arg1 < 1 || arg2 < 1 || arg3 < 1 || arg1 > 16 || arg2 > 16 || arg3 > 16)
		return;
	if ((processus->reg[arg3] = processus->reg[arg1] + processus->reg[arg2]))
		processus->carry = 1;
}

void	ft_sub(t_vm *vm, t_processus *processus)
{
	(void)vm;
	t_action		action;
	int				arg1;
	int				arg2;
	int				arg3;


	action = processus->action;
	arg1 = action.args[0];
	arg2 = action.args[1];
	arg3 = action.args[2];
	if (action.nb_arg != 3 || action.type[0] != REG || action.type[1] != REG ||
	action.type[2] != REG)
		return;
	if (arg1 < 1 || arg2 < 1 || arg3 < 1 || arg1 > 16 || arg2 > 16 || arg3 > 16)
		return;
	if (!(processus->reg[arg3] = processus->reg[arg1] + processus->reg[arg2]))
		processus->carry = 1;
}
