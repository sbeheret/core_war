/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/07 17:47:12 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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

/*
** LD - 2arg
** arg1 = T_DIR | T_IND
** arg2 = T_REG
*/
void	ft_ld(t_vm *vm, t_processus *processus)
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
		address = circular((*processus).action.pc + ((short)arg1 % IDX_MOD));
		arg1 = ft_octet_to_int2((*vm).ram, REG_SIZE, address);
	}
	processus->reg[arg2] = arg1;
	processus->carry = 1;

}

void	ft_st(t_vm *vm, t_processus *processus)
{
	t_action		action;
	int				arg1;
	int				arg2;
	int				address;

	action = processus->action;
	arg1 = action.args[ARG1];
	arg2 = action.args[ARG2];
	if (action.nb_arg != 2 || action.type[ARG1] != REG || action.type[ARG2] == DIR)
		return;
	if (arg1 < 1 || arg1 > 16)
		return;
	if (action.type[ARG2] == REG && (arg2 < 1 || arg2 > 16))
		return;
	if (action.type[ARG2] == REG)
		processus->reg[arg1] = processus->reg[arg2];
	else if (action.type[ARG2] == IND)
	{
		address = circular(action.pc + ((short)arg2 % IDX_MOD));
		ft_int_to_octet((*vm).ram, processus->reg[arg1], address);
	}
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
	arg1 = action.args[ARG1];
	arg2 = action.args[ARG2];
	arg3 = action.args[ARG3];
	if (action.nb_arg != 3 || action.type[ARG1] != REG ||
		action.type[ARG2] != REG ||	action.type[ARG3] != REG)
		return;
	if (arg1 < 1 || arg2 < 1 || arg3 < 1 || arg1 > 16 || arg2 > 16 || arg3 > 16)
		return;
	processus->reg[arg3] = processus->reg[arg1] + processus->reg[arg2];
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
	arg1 = action.args[ARG1];
	arg2 = action.args[ARG2];
	arg3 = action.args[ARG3];
	if (action.nb_arg != 3 || action.type[ARG1] != REG ||
		action.type[ARG2] != REG ||	action.type[ARG3] != REG)
		return;
	if (arg1 < 1 || arg2 < 1 || arg3 < 1 || arg1 > 16 || arg2 > 16 || arg3 > 16)
		return;
	processus->reg[arg3] = processus->reg[arg1] + processus->reg[arg2];
	processus->carry = 1;
}
