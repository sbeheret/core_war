/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:52 by esouza            #+#    #+#             */
/*   Updated: 2018/12/02 15:51:22 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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

void			get_data(char **argv, int fd, int fd2)
{
	t_data		*d;
	char		*data;
	char		name[PROG_NAME_LENGTH];
	int			position;
	t_header	*header;

	if (!(header = (t_header *)malloc(sizeof(t_header))) ||
		!(d = (t_data *)ft_memalloc(sizeof(t_data))))
		exit(EXIT_FAILURE);
	data = ft_strnew(0);
	read_fd(fd, &data);
	d->tab = ft_strsplit(data, '$');
	position = set_header(d->tab, header);
	if (!get_labels(d, position + 1))
	{
		free_data(d, data, header);
		ft_printf("Error, file has a bad format\n");
		exit(EXIT_FAILURE);
	}
	stocor(name, argv);
	fd2 = open(name, O_RDWR | O_APPEND | O_CREAT, RIGHTS);
	write(fd2, header, sizeof(t_header));
	print_tab(d, position); //tmp
	free_data(d, data, header);
}
