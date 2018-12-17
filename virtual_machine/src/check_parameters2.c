/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:47:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 18:47:58 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_binary(t_champion *champion)
{
	int				magic_number;
	unsigned char	*binary;

	binary = champion->binary;
	if (champion->binary_len < BEGIN_BINARY)
		ft_exit_toosmall(champion->file);
	if ((magic_number = ft_octet_to_int(&binary, 4)) != COREWAR_EXEC_MAGIC)
		ft_exit_magicnumber(champion->file);
	champion->name = ft_octet_to_char(&binary, PROG_NAME_LENGTH);
	check_padding(&binary, champion->file);
	champion->weight = ft_octet_to_int(&binary, 4);
	champion->comment = ft_octet_to_char(&binary, COMMENT_LENGTH);
	check_padding(&binary, champion->file);
	if (champion->weight != champion->binary_len - BEGIN_BINARY)
		ft_exit_header(champion->file);
	if (champion->weight > CHAMP_MAX_SIZE)
		ft_exit_toobig(champion->file);
	if (champion->weight == 0)
		ft_exit_nochamp(champion->file);
	binary = NULL;
}

void	check_padding(unsigned char **binary, char *file)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (**binary != 0)
			ft_exit_header(file);
		*binary = *binary + 1;
		i++;
	}
}

int		check_number(unsigned int number, t_champion *champion)
{
	while (champion)
	{
		if (number == champion->p_number)
			return (1);
		champion = champion->next;
	}
	return (0);
}

void	create_process(t_champion **champions, t_processus **pcs)
{
	t_champion		*champ;
	t_processus		*new;
	int				i;

	i = 1;
	champ = (*champions);
	new = NULL;
	while (champ != NULL)
	{
		new = new_processus(champ->p_number, champ->start, i);
		push_front_pcs(pcs, new);
		champ = champ->next;
		i++;
	}
}

void	check_multi_flag(t_vm *vm)
{
	if (vm->visu == 1)
	{
		vm->verbose = 0;
		vm->flag_hex = 0;
		vm->flag_dump = 0;
		vm->flag_live = 1;
	}
}
