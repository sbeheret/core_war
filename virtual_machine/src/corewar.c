/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:51 by rfibigr           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/29 17:23:21 by rfibigr          ###   ########.fr       */
||||||| merged common ancestors
/*   Updated: 2018/11/29 16:00:17 by rfibigr          ###   ########.fr       */
=======
/*   Updated: 2018/11/29 17:58:44 by sbeheret         ###   ########.fr       */
>>>>>>> 8e3e6e153e038330a4b6072bbc1a3bf738cc996c
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
	run_vm(&vm);
	print_optab();
	print_struct_vm(vm);
//	print_ram(vm.ram);
	ft_free_vm(&vm);
	return (1);
}
