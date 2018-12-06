/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/06 21:59:26 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Faire dans get action les verifications des valeurs de registres
** Faire dans get action la verificaiton Nb_arg
*/

#include "corewar.h"

void	ft_live(t_vm *vm, t_processus *processus)
{
	int			champion;
	t_action	action;

	// ft_printf("~~~LIVE~~~\n");
	action = processus->action;
	// ft_printf("action.pc = %d\n", action.pc);
	champion = ft_octet_to_int2((*vm).ram, 4, circular(action.pc + 1));
	//verifier si on ne doit faire ca que sur un numero de joueur valide
	//"un processus dit que le joueur x(nom_champion) est en vie"
	processus->lives++;
	(*vm).last_alive = champion;
}

void	ft_ld(t_vm *vm, t_processus *processus)
{
	t_action		action;
	int				arg1;
	int				arg2;
	int				address;

	// ft_printf("~~~LD~~~\n");
	action = processus->action;
	arg1 = action.args[ARG1];
	arg2 = action.args[ARG2];
	if (action.nb_arg != 2 || action.type[ARG1] == REG || action.type[ARG2] != REG)
		return;
	if (arg2 < 1 || arg2 > 16)
		return;
	//si coder sur 4 bytes
	if (action.type[ARG1] == 2)
		processus->reg[arg2] = arg1;
	//si coder sur 2 bytes
	else if (action.type[ARG1] == 3)
	{
		address = (short)circular(processus->PC + arg1);
		processus->reg[arg2] = ft_octet_to_int2((*vm).ram, 4, address);
	}
	processus->carry = 1;
}

void	ft_st(t_vm *vm, t_processus *processus)
{
	// est-ce que les valeurs sont bien des int ou unsigned int
	t_action		action;
	unsigned int	arg1;
	int				arg2;

	// ft_printf("~~~ST~~~\n");
	action = processus->action;
	arg1 = action.args[0];
	arg2 = action.args[1];
	if (action.nb_arg != 2 || action.type[0] != REG || action.type[1] == DIR)
		return;
	if (arg1 < 1 || arg1 > 16)
		return;
	if (action.type[1] == REG && (arg2 < 1 || arg2 > 16))
		return;
	if (action.type[1] == REG)
	{
		processus->reg[arg1] = processus->reg[arg2];
		return;
	}
	else
		ft_int_to_octet((*vm).ram, processus->reg[arg1 - 1], circular(arg2));
}

void	ft_add(t_vm *vm, t_processus *processus)
{
	(void)vm;
	t_action		action;
	int				arg1;
	int				arg2;
	int				arg3;

	// ft_printf("~~~ADD~~~\n");
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

	// ft_printf("~~~SUB~~~\n");
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
