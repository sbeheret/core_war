/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/06 17:44:41 by rfibigr          ###   ########.fr       */
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
	run_vm(&vm);
	// print_optab();
	// print_struct_vm(vm);
	// print_ram(vm.ram);
	ft_free_vm(&vm);
	return (1);
}
