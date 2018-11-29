/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:01:54 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/29 15:48:56 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Fonction qui pour chaque cycle
** Parcourir les processus
** 	- Executer les processus si leur cycle d'attente est a 0
		- Decode instruction et parametre
		- run intstruction
**
*/

void	run_vm(t_vm *vm)
{
	//condition du while a changer
	while ((*vm).CTD)
	{
		execute_processus(vm);
		//voir les bonnes conditions et variables a inc/decrementer
		(*vm).cycles_ttx++;
		(*vm).cycles_now++;
		(*vm).CTD--;
	}
}

void	execute_processus(t_vm *vm)
{
	int		op_code;

	t_processus *processus;
	processus = (*vm).processus;
	//processus circulaire ?? si c'est le cas il faut break a un moment
	while (processus)
	{
		op_code = processus->action.op_code;
		if (processus->cycles_wait == 0)
		{
			if (op_code > 0 && op_code < 17)
				run_instruction(vm, op_code);
			get_action(vm, processus);
			//changer le PC
		}
		processus->cycles_wait--;
		processus = processus->next;
	}
}

void	run_instruction(t_vm *vm, int op_code)
{
	static t_instruction	instruction[] = {
		&ft_live,
		&ft_ld,
		&ft_st,
		&ft_add,
		&ft_sub,
		&ft_and,
		&ft_or,
		&ft_xor,
		&ft_zjump,
		&ft_ldi,
		&ft_sti,
		&ft_fork,
		&ft_lld,
		&ft_lldi,
		&ft_lfork,
		&ft_aff
	};
	instruction[op_code - 1](vm);
}
