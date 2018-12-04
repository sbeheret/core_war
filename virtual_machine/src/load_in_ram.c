/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_in_ram.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:45:45 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/28 10:28:23 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	load_champs(t_vm *vm)
{
	t_champion	*champ;
	int			start;
	size_t		i;

	champ = vm->champion;
	start_champions(&(*vm).champion, (*vm).nb_champs);
	while (champ != NULL)
	{
		i = 0;
		start = champ->start;
		while (i < champ->weight)
		{
			vm->ram[start + i] = champ->binary[BEGIN_BINARY + i];
			i++;
		}
		champ = champ->next;
	}
}

void	start_champions(t_champion **champion, int nb_champs)
{
	t_champion	*tmp;

	tmp = (*champion);
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		give_start(tmp, nb_champs);
		tmp = tmp->next;
	}
}

void	give_start(t_champion *champ, int nb_champs)
{
	static int	order = 0;

	if (order == 0)
		champ->start = (0);
	else
		champ->start = (MEM_SIZE / nb_champs) * order;
	order++;
}
