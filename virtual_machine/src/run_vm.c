/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:01:54 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/28 15:32:31 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Fonction qui pour chaque cycle
** Parcourir les processus
** 	- Executer les processus si leur cycle d'attente est a 0
		- Read optcode
		- Decode instruction et parametre
		- run intstruction
**
*/


void	run_vm(t_vm *vm)
{
	while ((*vm).CTD)
	{
		execute_processus((*vm).processus);
		//do des trucs
		(*vm).cycles_ttx++;
		(*vm).cycles_now++;
	}
}

void	execute_processus(t_processus *processus)
{
	// a voir si fonctionne ou envoyer l'adresse
	while (*processus)
	{
		if ((*processus).cycles_wait == 0)
		{
			decode_instruction()
			run_instruction()
		}
		(*processus) = (*processus)->next;
	}
}

void	decode_instruction()
{

}
