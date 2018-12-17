/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:26:19 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/13 15:18:40 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	speed_define(unsigned int *speed, int c)
{
	if (c == KEY_UP)
	{
		if (*speed <= 1000000 && *speed > 100000)
			*speed -= 100000;
		else if (*speed == 100000)
			*speed -= 50000;
		else if (*speed <= 50000 && *speed > 10000)
			*speed -= 10000;
		else if (*speed <= 10000 && *speed > 2000)
			*speed -= 2000;
	}
	else if (c == KEY_DOWN)
	{
		if (*speed < 1000000 && *speed >= 100000)
			*speed += 100000;
		else if (*speed == 50000)
			*speed += 50000;
		else if (*speed < 50000 && *speed >= 10000)
			*speed += 10000;
		else if (*speed < 10000 && *speed >= 2000)
			*speed += 2000;
	}
	return ;
}

void		ncurses_input(t_vm *vm)
{
	int		c;

	if (!vm->visu)
		return ;
	c = 0;
	c = getch();
	if (!c)
		return ;
	if (c == ' ')
	{
		c = 0;
		while (c != ' ')
			c = getch();
	}
	else if (c == 'q')
	{
		endwin();
		ft_exit_visu(vm);
	}
	else if (c == KEY_UP || c == KEY_DOWN)
		speed_define(&(vm->sleep), c);
	return ;
}
