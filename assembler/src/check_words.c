/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:51:54 by esouza            #+#    #+#             */
/*   Updated: 2018/11/30 12:11:21 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				check_end(char **tab, int col, int row)
{
	while (tab[col][++row])
	{
		if (tab[col][row] > 32 && tab[col][row] < 127)
			return (1);
	}
	return (0);
}