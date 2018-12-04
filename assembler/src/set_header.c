/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:31:29 by esouza            #+#    #+#             */
/*   Updated: 2018/12/04 12:07:56 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int			ft_strmcmp(char *s1, char *s2, size_t len)
{
	while (--len && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int			parse_name(t_header *h, char **tab, int frst)
{
	int			i;
	int			j;
	int			quotes;

	i = ft_strlen(NAME_CMD_STRING);
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
	t_var			var;

	var.i = ft_strlen(COMMENT_CMD_STRING);
	var.j = 0;
	while (tab[sec][var.i] == ' ' || tab[sec][var.i] == '\t')
		var.i++;
	(tab[sec][var.i] != '\"') ? err_dots(sec, var.i, tab, h) : var.i++;
	var.quotes = 1;
	while (tab[sec] && tab[sec][var.i] && var.j <= COMMENT_LENGTH)
	{
		(tab[sec][var.i] == '\"') ? var.quotes++ : var.quotes;
		if (var.quotes == 2)
			break ;
		h->comment[var.j++] = tab[sec][var.i++];
		if (tab[sec] && tab[sec][var.i] == '\0')
		{
			sec++;
			var.i = 0;
			h->comment[var.j++] = '\n';
		}
	}
	if (var.quotes < 2 || (var.quotes == 2 && check_end(tab, sec, var.i)))
		err_dots(sec, var.i, tab, h);
	return (sec);
}

static int			name_comment(t_header *h, char **tab, int frst, int sec)
{
	int			position;

	position = 0;
	if (ft_strmcmp(tab[frst], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		parse_name(h, tab, frst);
		if (ft_strmcmp(tab[sec], COMMENT_CMD_STRING,
					ft_strlen(COMMENT_CMD_STRING)) != 0)
			err_dots(sec, sec, tab, h);
		position = parse_comment(h, tab, sec);
	}
	else if (ft_strmcmp(tab[frst], COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		parse_comment(h, tab, frst);
		if (ft_strmcmp(tab[sec], NAME_CMD_STRING,
					ft_strlen(NAME_CMD_STRING)) != 0)
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
	short		frst;
	short		second;

	idx = 0;
	start_dot = 0;
	frst = -1;
	second = 0;
	while (tab[idx])
	{
		if (tab[idx][0] == '.')
		{
			start_dot++;
			frst = (frst < 0) ? idx : frst;
			if (frst != -1 && second == 0)
				second = idx;
			(start_dot > 2) ? err_dots(idx, 1, tab, h) : 0;
		}
		idx++;
	}
	(start_dot < 2) ? err_dots(1, 0, tab, h) : 0;
	return (name_comment(h, tab, frst, second));
}

int					set_header(char **tab, t_header *header)
{
	int			position;

	position = 0;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + T_IND);
	ft_bzero(header->comment, COMMENT_LENGTH + T_IND);
	header->magic = swap_uint32(COREWAR_EXEC_MAGIC);
	position = parse_name_comment(header, tab);
	return (position);
}
