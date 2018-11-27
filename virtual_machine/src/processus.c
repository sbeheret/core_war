/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:26:38 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/27 18:40:01 by rfibigr          ###   ########.fr       */
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
