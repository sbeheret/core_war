/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:30 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/29 15:47:04 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.c"

void	get_action(t_vm *vm, t_processus *processus)
{
	// t_action	*new;
	//
	// if (!(new = malloc(sizeof(t_action))))
	// 	ft_exit_malloc();
	// new->op_code = (*vm)->ram[pcs->PC];
	// new->nb_arg = op_tab[new->op_code - 1][1];
	// if (!(new->args = malloc(sizeof(int) * new->nb_arg)))
	// 	ft_exit_malloc();
	// if (!(new->type = malloc(sizeof(int) * 4)))
	// 	ft_exit_malloc();
	// args_action((*vm).ram, pcs->PC, new);

	int		op_code;

	op_code = (*vm).ram[circular(processus->PC)];
	processus->action.op_code = op_code;
	processus->action.nb_arg = op_tab[op_code -1][1];
	args_action((*vm).ram, processus->PC, &processus->action);
}

void	args_action(unsigned char *ram, int PC, t_action *action)
{
	int		i;
	int		i_ram;
	int		size;
	int		enc_byte;

	enc_byte = op_tab[action->op_code - 1][6];
	size = 0;
	i = 0;
	trad_encoding_byte(action, enc_byte, ram[circular(PC + 1)]);
	i_ram = circular(PC + enc_byte + 1);
	while (i < action->nb_arg)
	{
		if (action->type[i] == 11 || (action->type[i] == 10 && enc_byte))
			size = 2;
		else if (action->type[i] == 10)
			size = 4;
		else
			size = 1;
		action->args[i] = size == 1 ? ram[i_ram] : ft_octet_to_int2(ram, size,
			i_ram);
		i_ram += size;
		action->size_read += size;
		i++;
	}
}

void	trad_encoding_byte(t_action *action, int enc_byte, int value)
{
	char	*str;
	int		i;

	i = 0;
	if (!enc_byte)
	{
		action->type[0] = 10;
		action->type[1] = 0;
		action->type[2] = 0;
		action->type[3] = 0;
	}
	else
	{
		str = ft_itoa_base(value, "01");
		action->type[0] = (str[0] - 48) * 10 + str[1] - 48;
		action->type[1] = (str[2] - 48) * 10 + str[3] - 48;
		action->type[2] = (str[4] - 48) * 10 + str[5] - 48;
		action->type[0] = (str[6] - 48) * 10 + str[7] - 48;
	}
}
