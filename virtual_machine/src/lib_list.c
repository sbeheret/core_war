/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:19:03 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/26 14:23:31 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion	*new_champion(void)
{
	t_champion	*new_elem;

	if (!(new_elem = (t_champion *)malloc(sizeof(t_champion))))
		ft_exit_malloc();
	initialize_champion(&new_elem);
	return(new_elem);
}

void	ft_push_back_chmp(t_champion **begin, t_champion *to_add)
{
	t_champion *tmp;

	tmp = *begin;
	if (*begin == NULL)
	{
		ft_printf("\nPUSH_BACK\n");

		*begin = to_add;
	}
	else
	{
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
		}
		tmp->next = to_add;
		ft_printf("\nPUSH_BACK 2\n");
	}
}
