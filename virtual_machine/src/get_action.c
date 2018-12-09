/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:30 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/07 16:38:05 by rfibigr          ###   ########.fr       */
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
// FAIRE PLUS PC DANS LES FONCTIONS
		// if (action->type[i] == 3)
		// 	action->args[i] += circular(PC);
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


/*
** Fonction pour debug
*/
void	print_optab(void)
{
	int i = 0;
	while (i<17)
	{
		ft_printf("tab[%d]= {\"%s\", %d, {%d,%d,%d}, %d, %d, %s, %d, %d}\n",i, op_tab[i].name,op_tab[i].param_number, op_tab[i].param_type[0], op_tab[i].param_type[1], op_tab[i].param_type[2], op_tab[i].op_code, op_tab[i].cycle, op_tab[i].comment, op_tab[i].encoding_byte, op_tab[i].direct_octet);
		i++;
	}
}
void	print_verbose(t_processus *processus)
{
	int	i;
	int	value1;
	int	value2;
	t_action action;

	action = processus->action;
	ft_printf("pc = %4d \tP = %d | ", action.pc, processus->processus_number);
	ft_printf("%s ", op_tab[action.op_code - 1].name);
	i = 0;
	while (i < action.nb_arg)
	{
		if (action.type[i] == 1)
			ft_printf("r%d ", action.args[i]);
		else
			ft_printf("%d ", action.args[i]);
		if (action.op_code == 12)
			ft_printf("(%d)", action.args[i] + action.pc);
		i++;
	}
	ft_printf("\n");
	if (action.op_code == 11)
	{
		if (processus->action.type[1] == 1)
			value1 = processus->reg[processus->action.args[1] - 1];
		else
			value1 = processus->action.args[1];
		if (processus->action.type[2] == 1)
			value2 = processus->reg[processus->action.args[2] - 1];
		else
			value2 = processus->action.args[2];
		ft_printf("\t  | -> store to %d + %d = %d (with pc and mod %d)\n",
		value1, value2, value1 + value2, action.pc + value1 + value2);
	}
}
