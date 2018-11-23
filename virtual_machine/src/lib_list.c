/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:19:03 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/23 13:36:08 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_processus	*create_processus(void)
{
	t_processus	*new_elem;

	if (!(new_elem = (t_processus *)malloc(sizeof(t_processus))))
		ft_exit_malloc();
	initialize_processus(&new_elem);
	return(new_elem);
}

void	ft_push_back(t_processus **begin, t_processus *to_add)
{
	t_processus *tmp;

	tmp = *begin;
	if (*begin == NULL)
		*begin = to_add;
	else
	{
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
		}
		tmp->next = to_add;
	}
}
