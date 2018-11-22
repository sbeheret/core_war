/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:52 by esouza            #+#    #+#             */
/*   Updated: 2018/11/22 14:32:55 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	char		**tab;
	char		*trim;
	int			i;

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
	tab = ft_strsplit(data, '$');
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_data(tab, data);
}
