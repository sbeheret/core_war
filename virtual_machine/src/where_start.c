/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:06:17 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/26 12:48:33 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	start_champions(t_champion **champion, int nb_champs)
{
	t_champion	*tmp;
	t_champion	*tmp2;
	int			boucle;
	int			i;

	boucle = 1;
	tmp = (*champion);
	tmp2 = (*champion);
	if (tmp == NULL)
		return ;
	i = 0;
	while (boucle)
	{
		tmp = (*champion);
		tmp2 = (*champion);
		while (tmp != NULL)
		{
			if (tmp2->p_number < tmp->p_number && tmp->p_number > i)
				tmp2 = tmp;
			tmp = tmp->next;
		}
		i = tmp2->p_number;
		boucle = give_start(tmp2, nb_champs);
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
	return (1);
}
