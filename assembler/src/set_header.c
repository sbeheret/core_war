/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:31:29 by esouza            #+#    #+#             */
/*   Updated: 2018/12/18 14:04:59 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			parse_name(t_header *h, char **tab, int frst)
{
	t_var			var;

	var.i = ft_strlen(NAME_CMD_STRING);
	var.j = 0;
	while (tab[frst][var.i] == ' ' || tab[frst][var.i] == '\t')
		var.i++;
	(tab[frst][var.i] != '\"') ? err_dots(frst, var.i, tab, h) : var.i++;
	var.quotes = 1;
	while (tab[frst][var.i] && var.j <= PROG_NAME_LENGTH)
	{
		(tab[frst][var.i] == '\"') ? var.quotes++ : var.quotes;
		if (var.quotes == 2)
			break ;
		if (tab[frst][var.i])
			h->prog_name[var.j++] = tab[frst][var.i++];
		if (tab[frst][var.i] == '\0')
		{
			frst++;
			var.i = 0;
		}
	}
	if (var.quotes < 2 || (var.quotes == 2 && check_end(tab, frst, var.i)))
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
	while (tab[sec] && var.j <= COMMENT_LENGTH)
	{
		(tab[sec][var.i] == '\"') ? var.quotes++ : var.quotes;
		if (var.quotes == 2)
			break ;
		if (tab[sec][var.i])
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
	second = -1;
	while (tab[idx])
	{
		if (tab[idx][0] == '.')
		{
			start_dot++;
			frst = (frst < 0) ? idx : frst;
			if (frst != -1 && second < 0 && start_dot > 1)
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
