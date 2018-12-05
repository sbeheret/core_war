/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_labels.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:41:23 by dshults           #+#    #+#             */
/*   Updated: 2018/12/05 13:28:59 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/asm.h"

static void			add_to_label_list_end(t_data *d, t_labels *label)
{
	if (!d->first_label)
	{
		d->first_label = label;
		d->last_label = d->first_label;
	}
	else
	{
		d->last_label->next = label;
		d->last_label = d->last_label->next;
	}
}

static t_labels		*make_label(char **line, int len, int y)
{
	t_labels		*label;

	label = ft_memalloc(sizeof(t_labels));
	if (len > 0)
		label->name = ft_strndup(line[0], len);
	else
		label->name = 0;
	label->position = y;
	label->bytes = 1;
	return (label);
}

int				is_label(t_data *d, int *y, int len, int skip)
{
	int			l;
	t_labels	*lb;

	if (d->tab[*y][len + 1] && d->tab[*y][len + 1] != ' ' && d->tab[*y][len + 1] != '\t')
		return (error_char(d->tab[*y][len + 1]));
	l = *y;
	lb = make_label(d->tab + *y, len, *y - skip);
	if (len > 0 && l - *y == 0)
	{
		len++;
		skip = len;
		len += find_op_code(lb, d->tab[l] + len, d->op);
		if (len - skip == 0 || (len - skip != 1 && !check_commas(d->tab[l] + skip)))
			return (0);
	}
	else
	{
		len = find_op_code(lb, d->tab[l], d->op);
		if (len == 0 || (len != 1 && !check_commas(d->tab[l])))
			return (0);
	}
	if (lb->op_nb != 0)
	{
		lb->args = ft_strsplit(d->tab[l] + len, SEPARATOR_CHAR);
		trim_spaces(lb->args);
	}
	add_to_label_list_end(d, lb);
	*y = l;
	return (1);
}

int				is_op_code(t_data *d, int y, int len, int skip)
{
	t_labels	*lb;

	lb = make_label(d->tab + y, 0, y - skip);
	len = find_op_code(lb, d->tab[y], d->op);
	if (len == 0 || !check_commas(d->tab[y])) // || len == 1 ?
		return (0);
	lb->args = ft_strsplit(d->tab[y] + len, SEPARATOR_CHAR);
	trim_spaces(lb->args);
	add_to_label_list_end(d, lb);
	return (1);
}

int				get_labels(t_data *d, int y)
{
	int		len;
	int		skip;

	skip = y;
	d->op = get_op_tab();
	while (d->tab[y])
	{
		len = 0;
		while (ft_strchr_no_zero(LABEL_CHARS, d->tab[y][len]))
			len++;
		if (d->tab[y][len] == LABEL_CHAR)
		{
			if (!is_label(d, &y, len, skip))
				return (0);
		}
		else if (d->tab[y][0] == COMMENT_CHAR
			|| ft_strstr(d->tab[y], NAME_CMD_STRING)
			|| ft_strstr(d->tab[y], COMMENT_CMD_STRING))
			skip++;
		else if (d->tab[y][len] == ' ' || d->tab[y][len] == '\t')
		{
			if (!is_op_code(d, y, len, skip))
				return (0);
		}
		else
		{
			if (!d->tab[y][len])
				ft_printf("\033[31mInvalide line [%s]\033[0;m\n", d->tab[y]);
			else
				error_char(d->tab[y][len]);
			return (0);
		}
		y++;
	}
	if (!general_check(d) || !compliance_check(d))
		return (0);
	add_bytes(d);
	show_labels(d); //tmp
	return (1);
}
