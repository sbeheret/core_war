/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:47:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/06 14:43:49 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

void			create_process(t_champion **champions, t_processus **pcs)
{
	t_champion		*champ;
	t_processus		*new;
	int			i;

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
