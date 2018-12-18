/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:01:54 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/17 12:05:06 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Fonction qui pour chaque cycle
** Parcourir les processus
** 	- Executer les processus si leur cycle d'attente est a 0
**		- si dans les instruction il y a un optcode valide on l'execute
**		- Decode instruction et parametre
*/

void	run_vm(t_vm *vm)
{
	int nb_decrement;
	int	total_live;

	nb_decrement = 0;
	total_live = 0;
	while ((*vm).processus)
	{
		execute_cycle(vm);
		if (vm->cycles_now >= vm->ctd)
		{
			total_live = kill_processus(vm);
			update_cycles(vm, 1);
			if (total_live >= NBR_LIVE || nb_decrement >= MAX_CHECKS)
			{
				(*vm).ctd -= CYCLE_DELTA;
				if ((*vm).flag_cycle == 1)
					ft_printf("Cycle to die is now %d\n", (*vm).ctd);
				nb_decrement = 0;
			}
			nb_decrement++;
			vm->cycles_now = 0;
		}
		(*vm).cycles_now++;
	}
	declare_winner(vm);
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
			if (vm->flag_death)
				ft_printf("Process %d didn't survive (CTD %d)\n",
				tmp->processus_number, vm->ctd);
			delete_element(&previous, &tmp, vm);
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

void	delete_element(t_processus **previous, t_processus **tmp, t_vm *vm)
{
	if (*previous == NULL)
	{
		*tmp = (*tmp)->next;
		remove_dead_pcs(vm->ram, vm->processus);
		ft_memdel((void**)&((*vm).processus)->reg);
		ft_memdel((void**)&(*vm).processus);
		(*vm).processus = *tmp;
	}
	else
	{
		(*previous)->next = (*tmp)->next;
		remove_dead_pcs(vm->ram, *tmp);
		ft_memdel((void**)&(*tmp)->reg);
		ft_memdel((void**)&(*tmp));
		(*tmp) = (*previous)->next;
	}
}

void	declare_winner(t_vm *vm)
{
	char		*name;
	t_champion	*champion;
	int			i;

	i = 0;
	name = NULL;
	champion = (*vm).champion;
	while (champion)
	{
		i++;
		if (champion->p_number == (*vm).last_alive)
		{
			name = champion->name;
			break ;
		}
		champion = champion->next;
	}
	if (vm->visu)
		winner_ncurses(name, (*vm).last_alive, i);
	else if (name == NULL)
		ft_printf("Only loosers... Do better next time.\n");
	else
		ft_printf("le joueur %d (%s)a gagne\n", champion->display_name, name);
}
