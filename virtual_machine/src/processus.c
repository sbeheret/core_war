/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:26:38 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/26 16:38:56 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			make_list_process(t_champion **champions, t_processus **pcs)
{
	t_champion		*champ;
	t_processus		*new;
	t_processus		*tmp_pcs;

	champ = (*champions);
	new = NULL;
	while (champ != NULL)
	{
		new = new_processus(champ->p_number, champ->start);
		push_front_pcs(pcs, new);
		champ = champ->next;
	}
	tmp_pcs = (*pcs);
	while (tmp_pcs->next != NULL)
		tmp_pcs = tmp_pcs->next;
	tmp_pcs->next = (*pcs);
}

void			push_front_pcs(t_processus **pcs, t_processus *new)
{
	t_processus	*tmp;

	tmp = (*pcs);
	if (tmp == NULL)
		(*pcs) = new;
	else
	{
		new->next = tmp;
		(*pcs) = new;
	}
}

t_processus		*new_processus(int p_number, int start)
{
	t_processus	*new;

	if (!(new = malloc(sizeof(t_processus))))
		ft_exit_malloc();
	initialize_processus(&new, p_number, start);
	return (new);
}
