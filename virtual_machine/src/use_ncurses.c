/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_ncurses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:07:06 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/11 12:01:31 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_in_ram(unsigned char *ram, t_processus *pcs, int id)
{
	int	i;
//	static int z = 0;

	i = 0;
	attron(COLOR_PAIR(pcs->color));
//	usleep(50000000);
//	mvprintw(70+z,50,"%d %d %d %d", ram[id], ram[id+1], ram[id+2], ram[id+3]);
//	z++;
	while (i < 4)
	{
		id = circular(id);
		move(id / 64 + 1, 8 + 3 * (id % 64));
		printw("%hhx", ram[id] / 16);
		printw("%hhx", ram[id] % 16);
		printw(" ");
//		ft_printf("%hhx", ram[id] / 16);
//		ft_printf("%hhx", ram[id] % 16);
//		ft_printf("\n");
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
	usleep(50000);
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
		mvprintw(5, 215, "%d", vm->CTD);
	}
	refresh();
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
	{
		mvprintw(10 + (i * 3), 210, "%d", vm->cycles_ttx);
		refresh();
	}
		//	mvprintw(11 + (i * 4), 222, "%d", tmp->lives);
}

void	init_data_visu(t_vm *vm)
{
	t_champion	*tmp;
	int		i;
	int		color;

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
	refresh();
}

void	update_pc_visu(unsigned char *ram, t_processus *pcs)
{
	int	i;
	int	b;

	i = circular(pcs->last_pc);
	if (i == pcs->action.pc)
		return ;
	b = mvinch(i / 64 + 1, 8 + 3 * (i % 64)) & A_COLOR;
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
