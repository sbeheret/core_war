/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:31:29 by esouza            #+#    #+#             */
/*   Updated: 2018/11/30 12:26:34 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			parse_name(t_header *h, char **tab, int frst)
{
	int			i;
	int			j;
	int			quotes;

	i = 5;
	j = 0;
	while (tab[frst][i] == ' ' || tab[frst][i] == '\t')
		i++;
	(tab[frst][i] != '\"') ? err_dots(frst, i, tab, h) : i++;
	quotes = 1;
	while (tab[frst][i] && j <= PROG_NAME_LENGTH)
	{
		(tab[frst][i] == '\"') ? quotes++ : quotes;
		if (quotes == 2)
			break ;
		h->prog_name[j++] = tab[frst][i++];
		if (tab[frst][i] == '\0')
		{
			frst++;
			i = 0;
		}
	}
	if (quotes < 2 || (quotes == 2 && check_end(tab, frst, i)))
		err_dots(frst, frst, tab, h);
	return (frst);
}

static int			parse_comment(t_header *h, char **tab, int sec)
{
	int			i;
	int			j;
	int			quotes;

	i = 8;
	j = 0;
	while (tab[sec][i] == ' ' || tab[sec][i] == '\t')
		i++;
	(tab[sec][i] != '\"') ? err_dots(sec, i, tab, h) : i++;
	quotes = 1;
	while (tab[sec] && tab[sec][i] && j <= COMMENT_LENGTH)
	{
		(tab[sec][i] == '\"') ? quotes++ : quotes;
		if (quotes == 2)
			break ;
		h->comment[j++] = tab[sec][i++];
		if (tab[sec] && tab[sec][i] == '\0')
		{
			sec++;
			i = 0;
			h->comment[j++] = '\n';
		}
	}
	if (quotes < 2 || (quotes == 2 && check_end(tab, sec, i)))
		err_dots(sec, i, tab, h);
	return (sec);
}

static int			name_comment(t_header *h, char **tab, int frst, int sec)
{
	int			position;

	position = 0;
	if (ft_strncmp(tab[frst], ".name", 5) == 0)
	{
		parse_name(h, tab, frst);
		if (ft_strncmp(tab[sec], ".comment", 8) != 0)
			err_dots(sec, sec, tab, h);
		position = parse_comment(h, tab, sec);
	}
	else if (ft_strncmp(tab[frst], ".comment", 8) == 0)
	{
		parse_comment(h, tab, frst);
		if (ft_strncmp(tab[sec], ".name", 5) != 0)
			err_dots(sec, sec, tab, h);
		position = parse_name(h, tab, sec);
	}
	else
		err_dots(frst, 1, tab, h);
	return (position);
}

static int			parse_name_comment(t_header *h, char **tab)
{
	int			idx;
	int			start_dot;
	short		first;
	short		second;

	idx = 0;
	start_dot = 0;
	first = -1;
	second = 0;
	while (tab[idx])
	{
		if (tab[idx][0] == '.')
		{
			start_dot++;
			first = (first < 0) ? idx : first;
			if (first != -1 && second == 0)
				second = idx;
			(start_dot > 2) ? err_dots(idx, 1, tab, h) : 0;
		}
		idx++;
	}
	(start_dot < 2) ? err_dots(1, 0, tab, h) : 0;
	return (name_comment(h, tab, first, second));
}

int					set_header(char **tab, t_header *header)
{
	int			position;

	position = 0;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	ft_bzero(header->comment, COMMENT_LENGTH);
	ft_bzero(header->pad, 4);
	ft_bzero(header->pad2, 4);
	header->magic = swap_uint32(COREWAR_EXEC_MAGIC);
	header->prog_size = swap_uint32(COREWAR_EXEC_MAGIC);
	position = parse_name_comment(header, tab);
	return (position);
}
