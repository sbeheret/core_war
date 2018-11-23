/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:05:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/23 11:45:11 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	initialize_vm(int argc, char **argv, t_vm *vm)
{
	(void) argc;
	(void) argv;

	// Fonction to check arguments
	(*vm).flag_dump = 0;
	(*vm).dump_cycle = 0;
	(*vm).processus = NULL;
	if (!((*vm).ram = (unsigned char *)ft_memalloc(MEM_SIZE)))
		ft_exit_malloc();
}

void	initialize_processus(t_processus **processus)
{
	(*processus)->name = NULL;
	(*processus)->comment = NULL;
	(*processus)->file = NULL;
	(*processus)->p_number = 0;
	(*processus)->weight = 0;
	(*processus)->binary = NULL;
	(*processus)->binary_len = 0;
	(*processus)->adress_start = NULL;
	(*processus)->next = NULL;
}
