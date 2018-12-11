/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:30 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/11 16:29:30 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.c"

void		get_action(t_vm *vm, t_processus *pcs)
{
	initialize_action(pcs);
	pcs->action.pc = pcs->PC;
	pcs->action.op_code = vm->ram[circular(pcs->PC)];
	if (pcs->action.op_code < 1 || pcs->action.op_code > 16)
	{
		pcs->PC++;
		pcs->action.op_code = 0;
		pcs->cycles_wait = 1;
		return ;
	}
	pcs->cycles_wait = op_tab[pcs->action.op_code - 1].cycle;
	pcs->action.nb_arg = op_tab[pcs->action.op_code - 1].param_number;
	pcs->action.size_read++;
	args_action(vm->ram, pcs->PC, &pcs->action);
	pcs->PC = pcs->PC + pcs->action.size_read;
}

static int	size_argument(int type, int direct_octet)
{
	if (type == 3 || (type == 2 && direct_octet))
		return (2);
	else if (type == 2)
		return (4);
	else
		return (1);
}

void		args_action(unsigned char *ram, int PC, t_action *action)
{
	int		i;
	int		i_ram;
	int		size;
	int		enc_byte;

	if ((enc_byte = op_tab[action->op_code - 1].encoding_byte))
		action->size_read++;
	size = 0;
	i = 0;
	trad_encoding_byte(action, enc_byte, ram[circular(PC + 1)]);
	i_ram = circular(PC + enc_byte + 1);
	while (i < action->nb_arg)
	{
		size = size_argument(action->type[i],
				op_tab[action->op_code - 1].direct_octet);
		action->args[i] = size == 1 ? ram[i_ram] : ft_octet_to_int2(ram, size,
				i_ram);
		i_ram += size;
		action->size_read += size;
		i++;
	}
}

void		trad_encoding_byte(t_action *action, int enc_byte, int value)
{
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
}

int		instruction_check(t_processus *processus)
{
	int 		i;
	t_action	action;
	int			param;

	action = processus->action;
	if (op_tab[action.op_code - 1].param_number != action.nb_arg)
		return (0);
	i = 0;
	while (i < action.nb_arg)
	{
		param = op_tab[action.op_code - 1].param_type[i];
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
