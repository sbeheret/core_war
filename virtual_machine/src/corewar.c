/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/15 10:50:08 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Initilization of VM
** -Check if arguments are valable
** -Create ram and initialize all element
*/

int	main(int argc, char **argv)
{
	t_vm	vm;

	initialize_vm(&vm);
	check_parameters(argc, argv, &vm);
	load_champs(&vm);
	create_process(&(vm).champion, &(vm).processus);
	introduce_contestant(vm.champion);
	if (vm.visu)
	{
		init_ncurses();
		print_ram_curses(&vm);
		refresh();
		getch();
		nodelay(stdscr, 1);
	}
	run_vm(&vm);
	if (vm.visu)
	{
		getch();
		endwin();
	}
	ft_free_vm(&vm);
	return (1);
}

void	introduce_contestant(t_champion *champion)
{
	int i;

	i = 1;
	ft_printf("Introducing contestants...\n");
	while (champion)
	{
		ft_printf("* Player %d, weighing %zd bytes, \"%s\" (\"%s\") !\n", i, champion->weight, champion->name, champion->comment);
		champion = champion->next;
		i++;
	}

}
