/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:01:54 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/11 11:38:58 by sbeheret         ###   ########.fr       */
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
	int nb_decrement;
	int	total_live;

	nb_decrement = 0;
	while ((*vm).processus)
	{
		(*vm).cycles_now = 0;
		total_live = 0;
		while ((*vm).cycles_now < (*vm).CTD)
		{
			ncurses_input(vm);
			execute_processus(vm);
			(*vm).cycles_ttx++;
			(*vm).cycles_now++;
			if ((*vm).flag_dump == 1 && (*vm).dump_cycle == (*vm).cycles_ttx)
				ft_exit_dump(vm);
		}
		total_live = kill_processus(vm);
//		ft_printf("cycles_now = %d < CTD = %d| cylces ttx = %d | total_live = %d > NBR_LIVE = %d | nb_decrement = %d > MAX_CHECKS = %d \n"
//	,(*vm).cycles_now, (*vm).CTD, (*vm).cycles_ttx, total_live, NBR_LIVE, nb_decrement, MAX_CHECKS);
		update_cycles(vm, 1);
		if (total_live > NBR_LIVE || nb_decrement > MAX_CHECKS)
		{
			(*vm).CTD -= CYCLE_DELTA;
			nb_decrement = 0;
		}
		nb_decrement++;
	}
	declare_winner(vm);
}

void	execute_processus(t_vm *vm)
{
	int		op_code;

	t_processus *processus;
	processus = (*vm).processus;
	if (vm->visu)
		update_cycles(vm, 0);
	while (processus)
	{
		// usleep(50000);
		op_code = processus->action.op_code;
		if (processus->cycles_wait == 0)
		{
			if (op_code > 0 && op_code < 17)
				run_instruction(vm, processus, op_code);
			get_action(vm, processus);
		}
		if (vm->visu)
			update_pc_visu(vm->ram, processus);
		processus->cycles_wait--;
		processus = processus->next;
	}
}

int		kill_processus(t_vm *vm)
{
	//parcours la liste,
	// on addition le nombre de live
	// si un processus a live a 0 on le supprime

	int			total_live;
	t_processus	*tmp;
	t_processus *previous;

	total_live = 0;
	previous = NULL;
	tmp = (*vm).processus;
	while (tmp)
	{
		if (tmp->lives == 0)
		{
			if (previous == NULL)
			{
				tmp = tmp->next;
				ft_memdel((void**)&((*vm).processus)->reg);
				ft_memdel((void**)&(*vm).processus);
				(*vm).processus = tmp;
			}
			else
			{
				previous->next = tmp->next;
				ft_memdel((void**)&tmp->reg);
				ft_memdel((void**)&tmp);
				tmp = previous->next;
			}
		}
		else
		{
			total_live += tmp->lives;
			tmp->lives = 0;
			previous = tmp;
			tmp = tmp->next;
		}
	}
	return (total_live);
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
	// print_ram((*vm).ram);
	// ft_printf("BEFORE INSTRUCTION\n");
	// print_processus((*vm).processus);
	instruction[op_code - 1](vm, processus);
	// ft_printf("AFTER INSTRUCTION\n");
	// print_processus((*vm).processus);
	// print_ram((*vm).ram);
}

void	declare_winner(t_vm *vm)
{
	char		*name;
	t_champion	*champion;

	name = NULL;
	champion = (*vm).champion;
	while(champion)
	{
		if (champion->p_number == (*vm).last_alive)
		{
			name = champion->name;
			break;
		}
		champion = champion->next;
	}
//	if (name == NULL)
	// sauvegarder le dernier champion au cas ou le numeor change
//		ft_printf("Aucun live avec un nom de champion valide n'a ete lance.\n");
//	ft_printf("le joueur %#X(%s)a gagne\n",(*vm).last_alive, name);
}
