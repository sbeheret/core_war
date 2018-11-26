/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:06:17 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/26 16:24:08 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	start_champions(t_champion **champion, int nb_champs)
{
	t_champion	*tmp;
	t_champion	*tmp2;

	tmp = (*champion);
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		give_start(tmp, nb_champs);
		tmp = tmp->next;
	}
}

int		give_start(t_champion *champ, int nb_champs)
{
	static int	order = 0;

	if (champ->start >= 0)
		return (0);
	if (order == 0)
		champ->start = (0);
	else
		champ->start = (MEM_SIZE / nb_champs) * order;
	order++;
	return (1);
}
