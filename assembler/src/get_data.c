/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:52 by esouza            #+#    #+#             */
/*   Updated: 2018/11/21 12:52:02 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void			free_data(char **tab, char *data)
{
		int		i;

		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(data);
		free(tab);
		data = NULL;
		tab = NULL;
}

void			get_data(int fd)
{
	char		*data;
	char		*line;
	char		*trim;
	int			i;
	t_data		*d;

	d = ft_memalloc(sizeof(t_data));
	data = ft_strnew(0);
	line = NULL;
	trim = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		trim = ft_strtrim((char const *)line);
		data = strjoinappend(data, trim);
		free(line);
		free(trim);
		trim = NULL;
		line = NULL;
	}
	d->tab = ft_strsplit(data, '$');
	while (d->tab[i])
	{
		printf("%s\n", d->tab[i]);
		i++;
	}
	get_labels(d);
	add_bytes(d);
	show_labels(d->first_label);
	free_data(d->tab, data);
	free_labels(d);
}
