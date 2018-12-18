/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:30 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/17 13:31:16 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void		get_op_code(t_vm *vm, t_processus *pcs)
{
	initialize_action(pcs);
	pcs->action.pc = pcs->pc;
	pcs->action.op_code = vm->ram[circular(pcs->pc)];
	if (vm->visu)
		update_pc_visu(vm->ram, pcs);
	if (pcs->action.op_code < 1 || pcs->action.op_code > 16)
	{
		pcs->cycles_wait = 1;
		return ;
	}
	pcs->cycles_wait = g_op_tab[pcs->action.op_code - 1].cycle;
}

static int	size_argument(int type, int direct_octet)
{
	if (type == 3 || (type == 2 && direct_octet))
		return (2);
	else if (type == 2)
		return (4);
	else if (type == 1)
		return (1);
	else
		return (0);
}

void		get_action(t_vm *vm, t_processus *pcs)
{
	int		i;
	int		i_ram;
	int		size;
	int		enc_byte;

	if (pcs->action.op_code < 1 || pcs->action.op_code > 16)
		return ;
	pcs->action.size_read++;
	if ((enc_byte = g_op_tab[pcs->action.op_code - 1].encoding_byte))
		pcs->action.size_read++;
	size = 0;
	trad_encoding_byte(&pcs->action, enc_byte, vm->ram[circular(pcs->pc + 1)]);
	i = 0;
	i_ram = circular(pcs->pc + enc_byte + 1);
	while (i < pcs->action.nb_arg)
	{
		size = size_argument(pcs->action.type[i],
				g_op_tab[pcs->action.op_code - 1].direct_octet);
		pcs->action.args[i] = size == 1 ?
						vm->ram[i_ram] : ft_octet_to_int2(vm->ram, size, i_ram);
		i_ram = circular(i_ram + size);
		pcs->action.size_read += size;
		i++;
	}
	pcs->pc = circular(pcs->pc + pcs->action.size_read);
}

void		trad_encoding_byte(t_action *action, int enc_byte, int value)
{
	int		i;

	if (!enc_byte)
	{
		action->type[0] = 2;
		action->type[1] = 0;
		action->type[2] = 0;
		action->type[3] = 0;
	}
	else
	{
		action->type[0] = (value & 0b11000000) >> 6;
		action->type[1] = (value & 0b00110000) >> 4;
		action->type[2] = (value & 0b00001100) >> 2;
		action->type[3] = 0;
	}
	i = -1;
	while (++i < 4)
	{
		if (action->type[i])
			action->nb_arg++;
	}
}

int			instruction_check(t_processus *processus)
{
	int			i;
	t_action	action;
	int			param;

	action = processus->action;
	if (g_op_tab[action.op_code - 1].param_number != action.nb_arg)
		return (0);
	i = 0;
	while (i < action.nb_arg)
	{
		param = g_op_tab[action.op_code - 1].param_type[i];
		if (action.type[i] == REG && (param == 2 || param == 6 || param == 4
		|| action.args[i] < 1 || action.args[i] > 16))
			return (0);
		else if (action.type[i] == DIR && (param == 1 || param == 4
			|| param == 5))
			return (0);
		else if (action.type[i] == IND && param < 4)
			return (0);
		else if (action.type[i] <= 0 || action.type[i] >= 4)
			return (0);
		i++;
	}
	return (1);
}
