/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/21 15:14:09 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main (int argc, char **argv)
{
	t_vm	vm;
	/*
	** Initilization of VM
	** -Check if arguments are valable
			- check magic number ??
			- read name and comment ??
	** -Create ram and initialize all element
	*/
	check_parameters(argc, argv);
	initialize_vm(argc, argv, &vm);


	print_ram(vm.ram);
	ft_memdel((void **) &(vm.ram));
	return (1);
}
