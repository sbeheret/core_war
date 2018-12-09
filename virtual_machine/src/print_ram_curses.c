/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ram_curses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:25:26 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/06 16:07:11 by sbeheret         ###   ########.fr       */
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

int	print_ram_color(unsigned char *ram, int i, int color, int size)
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
	int		i;
	int		c;

	i = 0;
	c = 0;
	tmp = vm->champion;
	while (i < MEM_SIZE && i < 3500)
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
}

void	init_ncurses(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_YELLOW);
	init_pair(7, COLOR_BLACK, COLOR_GREEN);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_MAGENTA);
	raw();
	noecho();
}
