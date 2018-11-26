/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_in_ram.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:45:45 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/26 16:59:36 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	load_champs(t_vm *vm)
{
	t_champion	*champ;
	int			start;
	int			i;

	champ = vm->champion;
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
