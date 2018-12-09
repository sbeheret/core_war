/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_ncurses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:07:06 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/09 15:59:47 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_in_ram(unsigned char *ram, t_processus *pcs, int id)
{
	int	i;

	i = 0;
	attron(COLOR_PAIR(pcs->color));
	move(id / 64 + 1, 9 + 3 * (id % 64));
	while (i < 4)
	{
		printw("%hhx", ram[id] / 16);
		printw("%hhx", ram[id] % 16);
		printw(" ");
		id++;
		i++;
	}
	attroff(COLOR_PAIR(pcs->color));
}

void	update_cycles(t_vm *vm, int a)
{
	if (a == 0)
	{
		mvprintw(1, 208, "%d", vm->cycles_ttx);
		mvprintw(3, 212, "%d", vm->cycles_now);
	}
	else
	{
		mvprintw(5, 215, "          ");
		mvprintw(5, 215, "%d", vm->CTD);
	}
}

void	update_lives(unsigned int nb, t_vm *vm, t_champion *chmps)
{
	t_champion	*tmp;
	int		i;

	i = 0;
	tmp = chmps;
	while (tmp && nb != tmp->p_number)
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		return ;
	(*vm).last_alive = nb;
//	tmp->lives++;
	if (vm->visu)
		mvprintw(10 + (i * 4), 210, "%d", vm->cycles_ttx);
//	mvprintw(11 + (i * 4), 222, "%d", tmp->lives);
}

void	init_data_visu(t_vm *vm)
{
	t_champion	*tmp;
	int		i;

	i = 9;
	tmp = vm->champion;
	mvprintw(1, 200, "Cycles: 0");
	mvprintw(3, 200, "Cycles Now: 0");
	mvprintw(5, 200, "Cycles to die: %d", CYCLE_TO_DIE);
	mvprintw(7, 200, "Cycles Delta: %d", CYCLE_DELTA);
	while (tmp)
	{
		mvprintw(i, 200, "Player %d: %s", tmp->p_number, tmp->name);
		mvprintw(++i, 200, "last live:");
//		mvprintw(++i, 200, "Live in current period:");
		i += 2;
		tmp = tmp->next;
	}
}

void	update_pc_visu(unsigned char *ram, t_processus *pcs)
{
	int	i;

	i = pcs->action.pc;
	attron(COLOR_PAIR(pcs->color + 5));
	mvprintw(i / 64 + 1, 9 + 3 * (i % 64), "%hhx", ram[i] / 16);
	printw("%hhx", ram[i] % 16);
	attroff(COLOR_PAIR(pcs->color + 5));
	return ;
}
