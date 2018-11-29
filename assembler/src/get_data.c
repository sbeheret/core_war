/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:52 by esouza            #+#    #+#             */
/*   Updated: 2018/11/28 17:40:31 by esouza           ###   ########.fr       */
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

static void			read_fd(int fd, char **data)
{
	char		*line;
	char		*trim;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		trim = ft_strtrim((char const *)line);
		if (trim[0] != COMMENT_CHAR)
			*data = strjoinappend(*data, trim);
		free_trim(line, trim);
	}
}

int				get_data(int fd, int fd2)
{
	char		*data;
	char		**tab;
	int			position;
	int			i; // to delte

	data = ft_strnew(0);
	position = 0;
	i = 0;
	read_fd(fd, &data);
	tab = ft_strsplit(data, '$');
	position = set_header(fd2, tab);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_data(tab, data);
	return (position);
}
