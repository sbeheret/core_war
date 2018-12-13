/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:14:17 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/13 15:19:11 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	execute_cycle(t_vm *vm)
{
	ncurses_input(vm);
	execute_instruction(vm);
	execute_get_action(vm);
	(*vm).cycles_ttx++;
	(*vm).cycles_now++;
	if ((*vm).flag_dump == 1 && (*vm).dump_cycle == (*vm).cycles_ttx)
		ft_exit_dump(vm);
}

void	execute_instruction(t_vm *vm)
{
	int			op_code;
	t_processus	*processus;

	processus = (*vm).processus;
	if (vm->visu)
		update_cycles(vm, 0);
	while (processus)
	{
		op_code = processus->action.op_code;
		if (processus->cycles_wait == 0 && op_code > 0 && op_code < 17)
			run_instruction(vm, processus, op_code);
		processus = processus->next;
	}
}

void	execute_get_action(t_vm *vm)
{
	t_processus	*processus;

	processus = (*vm).processus;
	while (processus)
	{
		if (processus->cycles_wait == 0)
			get_action(vm, processus);
		if (vm->visu)
			update_pc_visu(vm->ram, processus);
		processus->cycles_wait--;
		processus = processus->next;
	}
}

void	run_instruction(t_vm *vm, t_processus *processus, int op_code)
{
	static t_instruction	instruction[] = {
		&ft_live,
		&ft_ld,
		&ft_st,
		&ft_add,
		&ft_sub,
		&ft_and,
		&ft_or,
		&ft_xor,
		&ft_zjump,
		&ft_ldi,
		&ft_sti,
		&ft_fork,
		&ft_lld,
		&ft_lldi,
		&ft_lfork,
		&ft_aff};

	if (instruction_check(processus))
		instruction[op_code - 1](vm, processus);
}
