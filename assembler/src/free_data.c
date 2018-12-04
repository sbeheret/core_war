/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:17 by dshults           #+#    #+#             */
/*   Updated: 2018/12/04 15:36:28 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			free_trim(char *line, char *trim)
{
	free(line);
	free(trim);
	line = NULL;
	trim = NULL;
}

static void			free_labels(t_data *d)
{
	t_labels	*label;
	int			i;

	while (d->first_label)
	{
		label = d->first_label;
		d->first_label = d->first_label->next;
        free(label->name);
		label->name = NULL;
		i = 0;
		while (label->args[i])
		{
			free(label->args[i]);
			label->args[i] = NULL;
			i++;
		}
		free(label->args);
		label->args = NULL;
		free(label);
		label = NULL;
	}
	free(d);
	d = NULL;
}

void			free_data(t_data *d, char *data, t_header *header)
{
	int		i;

	i = 0;
	while (d->tab[i])
	{
		free(d->tab[i]);
		d->tab[i] = NULL;
		i++;
	}
	free(header);
	free(data);
	free(d->tab);
	header = NULL;
	data = NULL;
	d->tab = NULL;
	free_labels(d);
}
