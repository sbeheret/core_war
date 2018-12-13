/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_ncurses2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:14:45 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/13 14:28:31 by sbeheret         ###   ########.fr       */
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
		mvprintw(i / 64 + 1, 8 + 3 *(i % 64), "%hhx", ram[i] / 16);
		printw("%hhx", ram[i] % 16);
		if (ram[i] != 0)
			attroff(COLOR_PAIR(pcs->color));
		refresh();
	}
}

void	winner_ncurses(t_champion *champ, int i)
{
	int		row;
	int		col;

	erase();
	getmaxyx(stdscr, row, col);
	move(row / 2, col / 2);
	attron(A_BOLD);
	printw("PLAYER ");
	attron(COLOR_PAIR(i));
	printw("%d ", champ->p_number);
	attroff(COLOR_PAIR(i));
	printw("- ");
	attron(COLOR_PAIR(i) | A_BLINK);
	printw("%s", champ->name);
}
