/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:03:50 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 15:16:10 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_struct	str[OPEN_MAX];
	char			*read;
	int				readlen;

	readlen = 0;
	read = NULL;
	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	if (str[fd].len < 0)
		return (0);
	if (!(ft_memchr(str[fd].str, '\n', str[fd].len)))
		readlen = ft_read_to_space(fd, &read);
	if (readlen == -1)
		return (-1);
	if (str[fd].len + readlen == 0)
		return (0);
	if (!(*line = ft_memcat(str[fd].str, str[fd].len, read, readlen)))
		return (-1);
	free(read);
	if (!(ft_strcut(&*line, readlen, str[fd].str, &str[fd].len)))
		return (-1);
	return (1);
}

int		ft_read_to_space(int fd, char **buff)
{
	int				rd;
	char			sread[BUFF_SIZE];
	char			*tmp;
	int				i;

	i = 0;
	while ((rd = read(fd, sread, BUFF_SIZE)) > 0)
	{
		if (rd == -1)
			return (-1);
		if (!(tmp = ft_memcat(*buff, BUFF_SIZE * i, sread, rd)))
			return (-1);
		ft_bzero(sread, BUFF_SIZE);
		free(*buff);
		if (!(*buff = ft_strnew(BUFF_SIZE * i + rd)))
			return (-1);
		ft_memcpy(*buff, tmp, BUFF_SIZE * i + rd + 1);
		free(tmp);
		if ((ft_memchr(*buff, '\n', BUFF_SIZE * i + rd)))
			return (BUFF_SIZE * i + rd);
		i++;
	}
	return (BUFF_SIZE * i + rd);
}

int		ft_strcut(char **line, int bufflen, char *str, int *strlen)
{
	char			*tmp;
	int				c_space;
	int				c_end;
	int				linelen;

	linelen = bufflen + *strlen;
	c_space = 0;
	while ((*line)[c_space] != '\n' && c_space < (linelen))
		c_space++;
	c_end = linelen - c_space;
	*strlen = c_end - 1;
	if (!(tmp = ft_strnew(c_space)))
		return (0);
	ft_memcpy(str, *line + c_space + 1, c_end);
	ft_memccpy(tmp, *line, '\n', linelen);
	free(*line);
	*line = ft_strnew(c_space);
	ft_memcpy(*line, tmp, c_space);
	free(tmp);
	return (1);
}

char	*ft_memcat(char *buff, size_t bufflen, char *sread, size_t rd)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	if (!(tmp = ft_strnew(bufflen + rd)))
		return (NULL);
	i = 0;
	while (i < bufflen)
	{
		tmp[i] = buff[i];
		i++;
	}
	j = 0;
	while (i < (bufflen + rd))
	{
		tmp[i] = sread[j];
		j++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
