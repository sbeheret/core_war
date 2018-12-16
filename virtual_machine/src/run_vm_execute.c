/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:14:17 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 10:21:12 by rfibigr          ###   ########.fr       */
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
	int			op_code;
	t_processus	*processus;

	processus = (*vm).processus;
	if (vm->visu)
		update_cycles(vm, 0);
	while (processus)
	{
		op_code = processus->action.op_code;
		// ft_printf("P%d| ram = %d | op_code = %d\n",processus->processus_number, vm->ram[processus->action.pc], processus->action.op_code);
		if (vm->ram[circular(processus->action.pc)] >= 1
		&& vm->ram[circular(processus->action.pc)] <= 16
		&& vm->ram[circular(processus->action.pc)]!= processus->action.op_code)
		{
			get_op_code(vm, processus);
			// ft_printf("P%d| AFTER | op_code = %d\n",processus->processus_number, processus->action.op_code);
			if (vm->cycles_ttx != 0)
				processus->cycles_wait--;
			// print_processus(processus);
			// return ;
		}
		else if (processus->cycles_wait == 0)
		{
			get_action(vm, processus);
			if (op_code < 1 || op_code > 17)
				processus->pc++;
			else if (instruction_check(processus))
				run_instruction(vm, processus, op_code);
			initialize_action(processus);
		}
		processus = processus->next;
	}
}

void	get_instruction(t_vm *vm)
{
	t_processus	*processus;

	processus = (*vm).processus;
	// print_processus(processus);
	while (processus)
	{
		if (processus->cycles_wait == 0)
			get_op_code(vm, processus);
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

		instruction[op_code - 1](vm, processus);
	}
