/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:52 by esouza            #+#    #+#             */
/*   Updated: 2018/11/23 12:52:37 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			free_labels(t_data *d)
{
	t_labels	*label;

	while (d->first_label)
	{
		label = d->first_label;
		d->first_label = d->first_label->next;
        free(label->name);
		free(label);
	}
}

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

static void			free_trim(char *line, char *trim)
{
	free(line);
	free(trim);
	line = NULL;
	trim = NULL;
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
		if (trim[0] !=  COMMENT_CHAR)
			data = strjoinappend(data, trim);
		free_trim(line, trim);
	}
	d->tab = ft_strsplit(data, '$');
	while (d->tab[i])
	{
		printf("%s\n", d->tab[i]);
		i++;
	}
	get_labels(d, 2);
//	free_labels(d);
	free_data(d->tab, data);
}
