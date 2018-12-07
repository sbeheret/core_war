/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:05:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/07 15:20:21 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	initialize_vm(t_vm *vm)
{
	(*vm).nb_champs = 0;
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

void	initialize_processus(t_processus **processus, int nb_player, int start)
{
	int	i;
	static int processus_number = 1;

	i = -1;
	(*processus)->processus_number = processus_number;
	processus_number++;
	(*processus)->PC = start;
	(*processus)->carry = 0;
	if (!((*processus)->reg = malloc(sizeof(int) * 17)))
		ft_exit_malloc();
	while (++i <= 16)
		(*processus)->reg[i] = 0;
	(*processus)->reg[1] = nb_player;
	(*processus)->cycles_wait = 0;
	(*processus)->lives = 0;
	(*processus)->next = NULL;
	initialize_action(*processus);
}

void	initialize_action(t_processus *processus)
{
	processus->action.op_code = 0;
	processus->action.args[0] = 0;
	processus->action.args[1] = 0;
	processus->action.args[2] = 0;
	processus->action.args[3] = 0;
	processus->action.nb_arg = 0;
	processus->action.size_read = 0;
	processus->action.pc = 0;
	processus->action.type[0] = 0;
	processus->action.type[1] = 0;
	processus->action.type[2] = 0;
	processus->action.type[3] = 0;
}

void	initialize_champion(t_champion **champion)
{
	(*champion)->name = NULL;
	(*champion)->comment = NULL;
	(*champion)->file = NULL;
	(*champion)->p_number = 0;
	(*champion)->weight = 0;
	(*champion)->start = -1;
	(*champion)->binary = NULL;
	(*champion)->binary_len = 0;
	(*champion)->next = NULL;
}
