/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:05:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/21 15:27:53 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	initialize_vm(int argc, char **argv, t_vm *vm)
{
	(void) argc;
	(void) argv;
	// Fonction to check arguments
	if (!((*vm).ram = (unsigned char *)ft_memalloc(MEM_SIZE)))
		ft_exit_malloc();

	/*
	** Create processus - Initialise with arg.
	** Generate player name or use one specify
	*/

}
