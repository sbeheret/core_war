/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:52 by esouza            #+#    #+#             */
/*   Updated: 2018/12/14 10:55:14 by esouza           ###   ########.fr       */
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

static void		read_fd(int fd, char **data)
{
	char		*line;
	char		*trim;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		trim = ft_str_trim((char const *)line);
		if (trim[0] != COMMENT_CHAR && trim[0] != ';')
			*data = strjoinappend(*data, trim);
		free_trim(line, trim);
	}
}

static void		bad_file_format(t_data *d, char *data, t_header *header)
{
	free_data(d, data, header);
	ft_putstr("Error, file has a bad format\n");
	exit(EXIT_FAILURE);
}

void			get_data(char **argv, int fd, int fd2)
{
	t_data		d;
	char		*data;
	char		name[PROG_NAME_LENGTH];
	t_header	*header;

	if (!(header = (t_header *)malloc(sizeof(t_header))))
		exit(EXIT_FAILURE);
	ft_bzero(&d, sizeof(t_data));
	data = ft_strnew(0);
	read_fd(fd, &data);
	d.tab = ft_strsplit(data, '\n');
	d.y = set_header(d.tab, header) + 1;
	name_comment_length(&d, data, header, fd);
	if (!get_labels(&d))
		bad_file_format(&d, data, header);
	header->prog_size = swap_uint32(d.total_bytes);
	stocor(name, argv);
	fd2 = open(name, O_RDWR | O_CREAT | O_TRUNC, RIGHTS);
	write(fd2, header, sizeof(t_header));
	create_file_body(&d, fd2);
	ft_printf("Writing output program to %s\n", name);
	free_data(&d, data, header);
}
