/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/23 12:52:51 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main (int argc, char **argv)
{
	t_vm	vm;
	/*
	** Initilization of VM
	** -Check if arguments are valable
	** -Create ram and initialize all element
	*/
	initialize_vm(argc, argv, &vm);
	check_parameters(argc, argv, &vm);


	// print_ram(vm.ram);
	ft_memdel((void **) &(vm.ram));
	return (1);
}



/*


list :
struct processus
{
	name :
	comment :
	number :
	file :
	binary :
	binary_size :


-
}

*/
