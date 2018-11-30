/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/30 16:25:06 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TYPE
** 1 registre
** 2 direct
** 3 indirect
*/

/*
** Faire dans get action les verifications des valeurs de registres
** Faire dans get action la verificaiton Nb_arg
*/

#include "corewar.h"

void	ft_live(t_vm *vm, t_processus *processus)
{
	// adresse du nom du programme dans la ram
	// ecrire dans processus lives
	//		pour ca il me faut le processus
	// ecrire dans VM last_alive
	// (printf (champion name))

	// t_action action;
	//
	// action = (*vm).processus->action;j
	// (*vm).last_alive =

	processus->lives++;
	ft_printf("ft_ld = %d", (*vm).nb_champs);
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
	if (processus->reg[action.args[1] - 1] = (*vm).ram[action.pc + action.args[0]])
		processus->carry = 1;
}

void	ft_st(t_vm *vm, t_processus *processus)
{
	// est-ce que les valeurs sont bien des int
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



	// les deux parametre dans actions


	// param 2 = registre [x]

}

void	ft_add(t_vm *vm, t_processus *processus)
{
	t_action action;

	action = processus->action;
	if (action.nb_arg != 2 || action.type[0] == 1 || action.type[1] != 1)
		return;
	// recuperer 3 registres
	// le carry

	// registre 3 =registre 1 + registre 2

}

void	ft_sub(t_vm *vm, t_processus *processus)
{
	t_action action;

	action = processus->action;
	if (action.nb_arg != 2 || action.type[0] == 1 || action.type[1] != 1)
		return;
	// recuperer 3 registres
	// le carry

	// registre 3 =registre 1 - registre 2
}
