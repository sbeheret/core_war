/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:14:17 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 18:50:48 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	execute_cycle(t_vm *vm)
{
	if ((*vm).verbose == 1 && (*vm).cycles_ttx != 0)
		ft_printf("It is now cycle %d\n", (*vm).cycles_ttx);
	ncurses_input(vm);
	execute_instruction(vm);
	get_instruction(vm);
	if ((*vm).flag_dump == 1 && (*vm).dump_cycle == (*vm).cycles_ttx)
		ft_exit_dump(vm);
	(*vm).cycles_ttx++;
}

void	execute_instruction(t_vm *vm)
{
	t_processus	*pcs;

	pcs = (*vm).processus;
	vm->visu ? update_cycles(vm, 0) : 1;
	while (pcs)
	{
		if (vm->ram[circular(pcs->action.pc)] >= 1
		&& vm->ram[circular(pcs->action.pc)] <= 16
		&& vm->ram[circular(pcs->action.pc)] != pcs->action.op_code)
		{
			get_op_code(vm, pcs);
			vm->cycles_ttx != 0 ? pcs->cycles_wait-- : 1;
		}
		else if (pcs->cycles_wait == 0)
		{
			get_action(vm, pcs);
			if (pcs->action.op_code < 1 || pcs->action.op_code > 16)
				pcs->pc++;
			else if (instruction_check(pcs))
				run_instruction(vm, pcs, pcs->action.op_code);
			initialize_action(pcs);
		}
		pcs = pcs->next;
	}
}

void	get_instruction(t_vm *vm)
{
	t_processus	*processus;

	processus = (*vm).processus;
	while (processus)
	{
		if (processus->cycles_wait == 0)
			get_op_code(vm, processus);
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

	instruction[op_code - 1](vm, processus);
}
