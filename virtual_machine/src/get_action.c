/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:30 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/28 18:01:32 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_action(t_vm **vm, t_processus *pcs)
{
	t_action	*new;

	if (!(new = malloc(sizeof(t_action))))
		ft_exit_malloc();
	new->op_code = (*vm)->ram[pcs->PC];
	new->nb_arg = op_tab[new->op_code - 1][1];
	if (!(new->args = malloc(sizeof(int) * new->nb_arg)))
		ft_exit_malloc();
	if (!(new->type = malloc(sizeof(int) * 4)))
		ft_exit_malloc();
	args_action((*vm)->ram, pcs->PC, new);
}

void	args_action(unsigned char *ram, int PC, t_action *new)
{
	int		i;
	int		i_ram;
	int		size;
	int		enc_byte;

	enc_byte = op_tab[new->op_code - 1][6];
	size = 0;
	i = 0;
	trad_encoding_byte(new, enc_byte, ram[PC + 1]);
	i_ram = PC + enc_byte + 1;
	while (i < new->nb_arg)
	{
		if (new->type[i] == 11 || (new->type[i] == 10 && enc_byte))
			size = 2;
		else if (new->type[i] == 10)
			size = 4;
		else
			size = 1;
		new->args[i] = size == 1 ? ram[i_ram] : ft_octet_to_int(ram, size,
				i_ram);
		i_ram += size;
		new->size_read += size;
		i++;
	}
}

void	trad_encoding_byte(t_action *new, int enc_byte, int value)
{
	char	*str;
	int		i;

	i = 0;
	if (!enc_byte)
	{
		new->type[0] = 10;
		new->type[1] = 0;
		new->type[2] = 0;
		new->type[3] = 0;
	}
	else
	{
		str = ft_itoa_base(value, "01");
		new->type[0] = (str[0] - 48) * 10 + str[1] - 48;
		new->type[1] = (str[2] - 48) * 10 + str[3] - 48;
		new->type[2] = (str[4] - 48) * 10 + str[5] - 48;
		new->type[0] = (str[6] - 48) * 10 + str[7] - 48;
	}
}
