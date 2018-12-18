/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:53:09 by esouza            #+#    #+#             */
/*   Updated: 2018/12/12 12:17:50 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*file_build(int fd)
{
	int			ret;
	int			len;
	int			i;
	char		line[128];
	char		*file;

	len = 0;
	i = 0;
	lseek(fd, 0, SEEK_SET);
	while ((ret = read(fd, line, 128)) > 0)
		len += ret;
	file = ft_strnew(len);
	lseek(fd, 0, SEEK_SET);
	while ((ret = read(fd, line, 128)) > 0)
	{
		len = 0;
		while (len < ret)
			file[i++] = line[len++];
	}
	lseek(fd, 0, SEEK_SET);
	return (file);
}

static int		name_length(t_data *d, char *data, t_header *h, size_t i)
{
	size_t		len;

	len = 0;
	while (d->file[i] && d->file[i] != '"')
		i++;
	while (d->file[++i] && d->file[i] != '"')
		len++;
	if (len > PROG_NAME_LENGTH)
	{
		ft_printf("Champion name too long '%zu' (Max length 128)\n", len);
		free(d->file);
		d->file = NULL;
		free_data(d, data, h);
		exit(EXIT_FAILURE);
	}
	return (i);
}

static int		comment_length(t_data *d, char *data, t_header *h, size_t i)
{
	size_t		len;

	len = 0;
	while (d->file[i] && d->file[i] != '"')
		i++;
	while (d->file[++i] && d->file[i] != '"')
		len++;
	if (len > COMMENT_LENGTH)
	{
		ft_printf("Champion comment too long '%zu' (Max length 2048)\n", len);
		free(d->file);
		d->file = NULL;
		free_data(d, data, h);
		exit(EXIT_FAILURE);
	}
	return (i);
}

static int		check_start(t_data *d, char *data, t_header *h)
{
	size_t		i;
	short		nm;
	short		cm;

	i = 0;
	nm = ft_strlen(NAME_CMD_STRING);
	cm = ft_strlen(COMMENT_CMD_STRING);
	while (d->file[i])
	{
		if (d->file[i] == '.' && !ft_strmcmp(&d->file[i], NAME_CMD_STRING, nm))
		{
			i = name_length(d, data, h, i);
			i = comment_length(d, data, h, i + 1);
			break ;
		}
		else if (d->file[i] == '.'
				&& !ft_strmcmp(&d->file[i], COMMENT_CMD_STRING, cm))
		{
			i = comment_length(d, data, h, i);
			i = name_length(d, data, h, i + 1);
			break ;
		}
		i++;
	}
	return (0);
}

int				name_comment_length(t_data *d, char *data, t_header *h, int fd)
{
	d->file = file_build(fd);
	check_start(d, data, h);
	free(d->file);
	d->file = NULL;
	return (0);
}
