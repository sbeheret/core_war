/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_ncurses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:07:06 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/16 18:47:15 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_in_ram(unsigned char *ram, t_processus *pcs, int id)
{
	int	i;

	i = 0;
	attron(COLOR_PAIR(pcs->color));
	while (i < 4)
	{
		id = circular(id);
		move(id / 64 + 1, 8 + 3 * (id % 64));
		printw("%hhx", ram[id] / 16);
		printw("%hhx", ram[id] % 16);
		printw(" ");
		id++;
		i++;
	}
	attroff(COLOR_PAIR(pcs->color));
	refresh();
}

void	update_cycles(t_vm *vm, int a)
{
	if (!vm->visu)
		return ;
	usleep(vm->sleep);
	if (a == 0)
	{
		mvprintw(1, 208, "%d", vm->cycles_ttx);
		mvprintw(3, 212, "%d", vm->cycles_now);
	}
	else
	{
		mvprintw(5, 215, "      ");
		mvprintw(3, 212, "0     ");
		refresh();
		mvprintw(5, 215, "%d", vm->ctd);
	}
	mvprintw(22, 200, "                             ");
	mvprintw(22, 200, "%d Cycles / secondes", 1000000 / vm->sleep);
	refresh();
}

void	update_lives(unsigned int nb, t_vm *vm, t_champion *chmps)
{
	t_champion	*tmp;
	int			i;

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
	if (vm->visu)
	{
		mvprintw(10 + (i * 3), 213, "%d", vm->cycles_ttx);
		refresh();
	}
	else if (vm->flag_live == 0)
		ft_printf("un processus dit que le joueur %d (%s) est en vie\n",
		tmp->display_name, tmp->name);
}

void	init_data_visu(t_vm *vm)
{
	t_champion	*tmp;
	int			i;
	int			color;

	color = 1;
	i = 9;
	tmp = vm->champion;
	mvprintw(1, 200, "Cycles: 0");
	mvprintw(3, 200, "Cycles Now: 0");
	mvprintw(5, 200, "Cycles to die: %d", CYCLE_TO_DIE);
	mvprintw(7, 200, "Cycles Delta: %d", CYCLE_DELTA);
	while (tmp)
	{
		mvprintw(i, 200, "Player %d: ", tmp->p_number);
		attron(COLOR_PAIR(color));
		printw("%s", tmp->name);
		attroff(COLOR_PAIR(color));
		mvprintw(++i, 200, "last live:");
		i += 2;
		tmp = tmp->next;
		color++;
	}
	mvprintw(22, 200, "10 Cycles / secondes");
	refresh();
}

void	update_pc_visu(unsigned char *ram, t_processus *pcs)
{
	int	i;
	int	b;

	i = circular(pcs->last_pc);
	b = mvinch(i / 64 + 1, 8 + 3 * (i % 64)) & A_COLOR;
	if (i == pcs->action.pc && b == COLOR_PAIR(pcs->color + 5))
		return ;
	if (b == COLOR_PAIR(pcs->color + 5))
	{
		if (ram[i] != 0)
			attron(COLOR_PAIR(pcs->color));
		mvprintw(i / 64 + 1, 8 + 3 * (i % 64), "%hhx", ram[i] / 16);
		printw("%hhx", ram[i] % 16);
		if (ram[i] != 0)
			attroff(COLOR_PAIR(pcs->color));
		refresh();
	}
	i = circular(pcs->action.pc);
	pcs->last_pc = i;
	attron(COLOR_PAIR(pcs->color + 5));
	mvprintw(i / 64 + 1, 8 + 3 * (i % 64), "%hhx", ram[i] / 16);
	printw("%hhx", ram[i] % 16);
	attroff(COLOR_PAIR(pcs->color + 5));
	refresh();
	return ;
}
