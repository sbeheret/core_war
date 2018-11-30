/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:01:54 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/30 12:44:39 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Fonction qui pour chaque cycle
** Parcourir les processus
** 	- Executer les processus si leur cycle d'attente est a 0
		- si dans les instruction il y a un optcode valide on l'execute
		- Decode instruction et parametre
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
	// processus chaine lister null terminated
	while (processus)
	{
		usleep(500000);
		op_code = processus->action.op_code;
		if (processus->cycles_wait == 0)
		{
			if (op_code > 0 && op_code < 17)
				run_instruction(vm, processus, op_code);
			get_action(vm, processus);
		}
		processus->cycles_wait--;
		processus = processus->next;
		print_processus((*vm).processus);
	}
}

void	run_instruction(t_vm *vm, t_processus *processus, int op_code)
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
	instruction[op_code - 1](vm, processus);
}
