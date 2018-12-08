/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:55:36 by esouza            #+#    #+#             */
/*   Updated: 2018/12/08 11:38:36 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				err_dots(int idx, int err, char **tab, t_header *h)
{
	int			i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(h);
	h = NULL;
	if (err >= 0)
	{
		ft_printf("Error Token[%d:%d]\n", idx, err);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr("Missing '.name' or '.comment'\n");
		exit(EXIT_FAILURE);
	}
}
