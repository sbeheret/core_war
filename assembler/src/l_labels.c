/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_labels.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:41:23 by dshults           #+#    #+#             */
/*   Updated: 2018/12/07 12:40:51 by esouza           ###   ########.fr       */
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

static t_labels		*make_label(char **line, int len, int p)
{
	t_labels		*label;

	label = ft_memalloc(sizeof(t_labels));
	if (len > 0)
		label->name = ft_strndup(line[0], len);
	else
		label->name = 0;
	label->position = p;
	label->bytes = 1;
	return (label);
}

int				is_op_code(t_data *d, t_labels *lb, int label, int skip)
{
	int			len;

	if (!lb)
		lb = make_label(d->tab + d->y, 0, d->y - skip);
	len = find_op_code(lb, d->tab[d->y] + label, d->op);
	if (len == 0 || (len != 1 && !check_commas(d->tab[d->y] + label)))
		return (0);
	if (lb->op_nb != 0)
	{
		lb->args = ft_strsplit(d->tab[d->y] + len + label, SEPARATOR_CHAR);
		trim_spaces(lb->args);
	}
	add_to_label_list_end(d, lb);
	return (1);
}

int				is_label(t_data *d, int len, int skip)
{
	t_labels	*lb;

	if (d->tab[d->y][len + 1]
		&& d->tab[d->y][len + 1] != ' ' && d->tab[d->y][len + 1] != '\t')
		return (error_char(d->tab[d->y][len + 1]));
	lb = make_label(d->tab + d->y, len, d->y - skip);
	len++;
	if (!is_op_code(d, lb, len, skip))
		return (0);
	return (1);
}

int				get_them(t_data *d, int len, int skip)
{
	while (d->tab[d->y])
	{
		len = 0;
		while (ft_strchr_no_zero(LABEL_CHARS, d->tab[d->y][len]))
			len++;
		if (d->tab[d->y][len] == LABEL_CHAR)
		{
			if (!is_label(d, len, skip))
				return (0);
		}
		else if (d->tab[d->y][len] == ' ' || d->tab[d->y][len] == '\t')
		{
			if (!is_op_code(d, NULL, 0, skip))
				return (0);
		}
		else
		{
			if (!d->tab[d->y][len])
				ft_printf("\033[31mInvalide line [%s]\033[0;m\n", d->tab[d->y]);
			else
				error_char(d->tab[d->y][len]);
			return (0);
		}
		d->y++;
	}
	return (1);
}

int				get_labels(t_data *d)
{
	d->op = get_op_tab();
	if (!get_them(d, 0, d->y) || !general_check(d) || !compliance_check(d))
		return (0);
	add_bytes(d);
//	show_labels(d); //tmp
	return (1);
}
