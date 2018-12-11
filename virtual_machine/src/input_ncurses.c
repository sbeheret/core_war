/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:26:19 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/11 12:09:44 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ncurses_input(t_vm *vm)
{
	int		c;

	timeout(1);
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
		{
			c = getch();
		}
	}
	else if (c == 'q')
	{
		endwin();
		ft_exit_visu(vm);
	}
}
