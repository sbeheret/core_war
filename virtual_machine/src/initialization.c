/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:05:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/24 16:10:23 by sbeheret         ###   ########.fr       */
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
	(*vm).last_alive = 0;
	(*vm).CTD = CYCLE_TO_DIE;
	(*vm).cycles_ttx = 0;
	(*vm).cycles_now = 0;
	(*vm).processus = NULL;
	(*vm).champion = NULL;
	if (!((*vm).ram = (unsigned char *)ft_memalloc(MEM_SIZE)))
		ft_exit_malloc();
}

void	initialize_processus(t_processus **processus)
{
	int	i;

	i = -1;
	(*processus)->PC = 0;
	if (!((*processus)->reg = malloc(sizeof(int * 16))))
		ft_exit_malloc;
	while (++i <= 15)
		reg[i] = 0;
	(*processus)->cycles_wait = 0;
	(*processus)->lives = 0;
	(*processus)->next = NULL;
}

void	initialize_champion(t_champion **champion)
{
	(*champion)->name = NULL;
	(*champion)->comment = NULL;
	(*champion)->file = NULL;
	(*champion)->p_number = 0;
	(*champion)->weight = 0;
	(*champion)->binary = NULL;
	(*champion)->binary_len = 0;
	(*champion)->next = NULL;
}
