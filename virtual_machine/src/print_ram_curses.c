/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ram_curses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:25:26 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/13 15:27:42 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_ram_nocolor(unsigned char *ram, int i)
{
	if (!(i % 64))
	{
		printw("\n");
		printw("0X");
		printw("%.4X :", i);
	}
	printw("%hhx", ram[i] / 16);
	printw("%hhx", ram[i] % 16);
	printw(" ");
}

int		print_ram_color(unsigned char *ram, int i, int color, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (!((i + j) % 64))
		{
			printw("\n");
			printw("0X");
			printw("%.4X :", i + j);
		}
		attron(COLOR_PAIR(color));
		printw("%hhx", ram[i + j] / 16);
		printw("%hhx", ram[i + j] % 16);
		attroff(COLOR_PAIR(color));
		printw(" ");
		j++;
	}
	return (j);
}

void	print_ram_curses(t_vm *vm)
{
	t_champion	*tmp;
	int			i;
	int			c;

	i = 0;
	c = 0;
	tmp = vm->champion;
	while (i < MEM_SIZE)
	{
		if (tmp->start == i)
		{
			c++;
			i += print_ram_color(vm->ram, i, c, tmp->weight);
			if (tmp->next != NULL)
				tmp = tmp->next;
		}
		else
		{
			print_ram_nocolor(vm->ram, i);
			i++;
		}
	}
	init_data_visu(vm);
}

void	init_ncurses(void)
{
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	curs_set(0);
	init_color(COLOR_WHITE, 500, 500, 500);
	init_color(COLOR_GREEN, 0, 1000, 329);
	init_color(COLOR_RED, 1000, 0, 888);
	init_color(COLOR_BLUE, 0, 529, 1000);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_BLUE);
	raw();
	noecho();
}
