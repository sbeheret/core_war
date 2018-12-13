/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/13 15:10:21 by sbeheret         ###   ########.fr       */
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
	if (vm.visu)
	{
		init_ncurses();
		print_ram_curses(&vm);
		refresh();
		getch();
		nodelay(stdscr, 1);
	}
//	print_ram((vm).ram);
	run_vm(&vm);
	// print_optab();
	// print_struct_vm(vm);
//	print_ram(vm.ram);
	if (vm.visu)
	{
		getch();
		endwin();
	}
	ft_free_vm(&vm);
	return (1);
}
