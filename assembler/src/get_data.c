/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:52 by esouza            #+#    #+#             */
/*   Updated: 2018/11/30 12:25:56 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		stocor(char name[], char **argv)
{
	short	i;
	short	j;
	char	*p;

	i = 0;
	j = 0;
	p = ".cor";
	if (ft_strlen(argv[1]) > (FILE_NAME_LENGTH - 5))
	{
		ft_putstr("File name too long\n");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i] != '\0' && i < (FILE_NAME_LENGTH - 5))
	{
		name[i] = argv[1][i];
		i++;
	}
	i -= 2;
	while (p[j])
	{
		name[i] = p[j];
		i++;
		j++;
	}
	name[i] = '\0';
}

static void			free_data(char **tab, char *data, t_header *header)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(header);
	free(data);
	free(tab);
	header = NULL;
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

int				get_data(char **argv, int fd, int fd2)
{
	char		*data;
	char		**tab;
	char		name[PROG_NAME_LENGTH];
	int			position;
	t_header	*header;
	int			i; // to delte

	if (!(header = (t_header *)malloc(sizeof(t_header))))
		exit(EXIT_FAILURE);
	data = ft_strnew(0);
	position = 0;
	i = 0;
	read_fd(fd, &data);
	tab = ft_strsplit(data, '$');
	position = set_header(tab, header);
	//check_start_opcode(tab, position + 1);
	stocor(name, argv);
	fd2 = open(name, O_RDWR | O_APPEND | O_CREAT, RIGHTS);
	write(fd2, header, sizeof(t_header));
	printf("{%s}\n", tab[position]);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_data(tab, data, header);
	return (position);
}
