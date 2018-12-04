/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:41:40 by dshults           #+#    #+#             */
/*   Updated: 2018/12/02 15:41:43 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int    label_error(t_labels *l, char *to_check)
{
	int    i;

	i = 0;
	if (to_check[i] == DIRECT_CHAR)
		i++;
	if (to_check[i] == LABEL_CHAR)
		i++;
	while (l)
	{
		if (l->name && !ft_strcmp(l->name, to_check + i))
			return (0);
		l = l->next;
	}
	return (1);
}

/*
 * **  arguments are digits-only
 * **  register is between 1 and REG_NUMBER(16)
 * */

static int   args_error(char **s, int *y)
{
	int    x;

	while (s[*y])
	{
		x = 0;
		if (s[*y][x] == 'r' && (ft_atoi(s[*y] + 1) > REG_NUMBER || s[*y][1] == '0'))
			return (error_args(s[*y]) - 2);
		if (s[*y][x] == DIRECT_CHAR || s[*y][x] == 'r')
			x++;
		if (s[*y][x] == LABEL_CHAR)
			return (*y);
		while (s[*y][x])
		{
			if (s[*y][x] == '-' && s[*y][x + 1] != '-')
				x++;
			if (!ft_isdigit(s[*y][x]))
				return (error_args(s[*y]) - 2);
			x++;
		}
		(*y)++;
	}
	return (-1);
}

static int    args_nb_check(t_labels *l, t_op *op)
{
	int    i;

	while (l)
	{
		i = 0;
		if (l->op_nb == 0)
		{
			l = l->next;
			continue;
		}
		while (l->args[i])
			i++;
		if (i != op[l->op_nb - 1].params_nb)
			return (error_param_nb(l->op_code, op[l->op_nb - 1].params_nb, i));
		l = l->next;
	}
	return (1);
}

int    general_check(t_data *d)
{
	int         a;
	int			y;
	t_labels    *l;

	l = d->first_label;
	y = 0;
	if (!args_nb_check(d->first_label, d->op))
		return (0);
	while (l)
	{
		if (l->op_nb == 0)
		{
			l = l->next;
			continue;
		}
		a = args_error(l->args, &y);
		if (a == -2)
			return (0);
		else if (a >= 0)
		{
			if (label_error(d->first_label, l->args[a]))
				return (error_label(l->args[a]));
			else
			{
				y++;
				continue;
			}
		}
		l = l->next;
		y = 0;
	}
	return (1);
}
