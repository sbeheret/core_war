/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:47:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/27 15:58:34 by rfibigr          ###   ########.fr       */
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
