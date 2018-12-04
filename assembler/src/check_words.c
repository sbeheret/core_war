/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2018/12/04 15:35:48 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
