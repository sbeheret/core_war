/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:01:54 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/13 13:46:37 by rfibigr          ###   ########.fr       */
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
			execute_instruction(vm);
			execute_get_action(vm);
			// execute_processus(vm);
			(*vm).cycles_ttx++;
			(*vm).cycles_now++;
			if ((*vm).flag_dump == 1 && (*vm).dump_cycle == (*vm).cycles_ttx)
				ft_exit_dump(vm);
		}
		total_live = kill_processus(vm);
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

// void	execute_processus(t_vm *vm)
// {
// 	int		op_code;
//
// 	t_processus *processus;
// 	processus = (*vm).processus;
// 	if (vm->visu)
// 		update_cycles(vm, 0);
// 	while (processus)
// 	{
// 		op_code = processus->action.op_code;
// 		if (processus->cycles_wait == 0)
// 		{
// 			if (op_code > 0 && op_code < 17)
// 				run_instruction(vm, processus, op_code);
// 			get_action(vm, processus);
// 		}
// 		if (vm->visu)
// 			update_pc_visu(vm->ram, processus);
// 		if (processus->cycles_wait != 0)
// 			processus->cycles_wait--;
// 		processus = processus->next;
// 	}
// }
void	execute_instruction(t_vm *vm)
{
	int		op_code;

	t_processus *processus;
	processus = (*vm).processus;
	if (vm->visu)
		update_cycles(vm, 0);
	while (processus)
	{
		op_code = processus->action.op_code;
		if (processus->cycles_wait == 0 && op_code > 0 && op_code < 17)
			run_instruction(vm, processus, op_code);
		processus = processus->next;
	}
}

void	execute_get_action(t_vm *vm)
{
	t_processus *processus;
	processus = (*vm).processus;
	while (processus)
	{
		if (processus->cycles_wait == 0)
			get_action(vm, processus);
		if (vm->visu)
			update_pc_visu(vm->ram, processus);
		processus->cycles_wait--;
		processus = processus->next;
	}
}

int		kill_processus(t_vm *vm)
{
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
				remove_dead_pcs(vm->ram, vm->processus);
				ft_memdel((void**)&((*vm).processus)->reg);
				ft_memdel((void**)&(*vm).processus);
				(*vm).processus = tmp;
			}
			else
			{
				previous->next = tmp->next;
				remove_dead_pcs(vm->ram, tmp);
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
	if (instruction_check(processus))
		instruction[op_code - 1](vm, processus);
	// else
	// 	processus->PC = processus->action.pc + 2;
	//verifier la valeur de si instruction false
	//surement seulement plus 1 si encoding_byte
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
	// ft_printf("le joueur %#X(%s)a gagne\n",(*vm).last_alive, name);
}
