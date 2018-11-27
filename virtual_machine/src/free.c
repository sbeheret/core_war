/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:32:56 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/27 17:44:32 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_free_vm(t_vm *vm)
{
	if ((*vm).ram)
	{
		ft_printf("free ram\n");
		ft_memdel((void**)&(*vm).ram);
	}
	if ((*vm).champion)
	{
		ft_printf("free champion\n");
		ft_free_champion(&(*vm).champion);
	}
	if ((*vm).processus)
	{
		ft_printf("free processus\n");
		ft_free_processus(&(*vm).processus);
	}
	ft_printf("exit free\n");
}

void	ft_free_champion(t_champion **champion)
{
	t_champion	*tmp;

	while ((*champion))
	{
		if ((*champion)->name)
			ft_memdel((void**)&(*champion)->name);
		if ((*champion)->comment)
			ft_memdel((void**)&(*champion)->comment);
		if ((*champion)->binary)
			ft_memdel((void**)&(*champion)->binary);
		tmp = (*champion)->next;
		ft_memdel((void**)champion);
		*champion = tmp;
	}
	ft_memdel((void**)champion);
}

void	ft_free_processus(t_processus **processus)
{
	t_processus	*tmp;

	while ((*processus)->next)
	{
		if ((*processus)->reg)
			ft_memdel((void**)&(*processus)->reg);
		tmp = (*processus)->next;
		ft_memdel((void**)processus);
		*processus = tmp;
	}
}
