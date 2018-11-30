/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:47:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/29 17:25:06 by rfibigr          ###   ########.fr       */
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
	// t_processus		*tmp_pcs;

	champ = (*champions);
	new = NULL;
	while (champ != NULL)
	{
		new = new_processus(champ->p_number, champ->start);
		push_front_pcs(pcs, new);
		champ = champ->next;
	}
	/*
	** liste chainee ciruclaire
	*/
	// tmp_pcs = (*pcs);
	// while (tmp_pcs->next != NULL)
	// 	tmp_pcs = tmp_pcs->next;
	// tmp_pcs->next = (*pcs);
}
