/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_ncurses2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:14:45 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/16 10:14:26 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	remove_dead_pcs(unsigned char *ram, t_processus *pcs)
{
	int		i;
	int		b;

	i = circular(pcs->action.pc);
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
}

void	winner_ncurses(char *name, int nb, int i)
{
	int		row;
	int		col;

	erase();
	nodelay(stdscr, 0);
	getmaxyx(stdscr, row, col);
	move(row / 2, col / 2);
	attron(A_BOLD);
	if (name == NULL)
	{
		printw("Only ");
		printw("LOOSERS");
		attroff(A_BOLD);
		return ;
	}
	printw("PLAYER ");
	attron(COLOR_PAIR(i));
	printw("%#X ", nb);
	attroff(COLOR_PAIR(i));
	printw("- ");
	attron(COLOR_PAIR(i));
	printw("%s", name);
	attroff(COLOR_PAIR(i));
	printw(" IS A WINNER");
	attroff(A_BOLD);
}
