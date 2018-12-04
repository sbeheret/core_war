/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:42 by dshults           #+#    #+#             */
/*   Updated: 2018/12/02 15:42:44 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int    reg(char c)
{
	if (c == 'r')
		return (1);
	return (0);
}

static int    dir(char c)
{
	if (c == DIRECT_CHAR)
		return (1);
	return (0);
}

static int    ind(char c)
{
	if (c == 'r' || c == DIRECT_CHAR)
		return (0);
	return (1);
}

int    compliance_check(t_data *d)
{
	t_labels    *l;
	int         i;

	l = d->first_label;
	while (l)
	{
		if (l->op_nb == 0)
		{
			l = l->next;
			continue;
		}
		i = 0;
		while (i < d->op[l->op_nb - 1].params_nb)
		{
			if (d->op[l->op_nb - 1].params_types[i] == T_REG)
			{
				if (!reg(l->args[i][0]))
					return (error_arg_type(l->args[i], l->op_code));
			}
			else if (d->op[l->op_nb - 1].params_types[i] == T_DIR)
			{
				if (!dir(l->args[i][0]))
					return (error_arg_type(l->args[i], l->op_code));
			}
			else if (d->op[l->op_nb - 1].params_types[i] == T_IND)
			{
				if (!ind(l->args[i][0]))
					return (error_arg_type(l->args[i], l->op_code));
			}
			else if (d->op[l->op_nb - 1].params_types[i] == T_REG + T_DIR)
			{
				if (!reg(l->args[i][0]) && !dir(l->args[i][0]))
					return (error_arg_type(l->args[i], l->op_code));
			}
			else if (d->op[l->op_nb - 1].params_types[i] == T_REG + T_IND)
			{
				if (!reg(l->args[i][0]) && !ind(l->args[i][0]))
					return (error_arg_type(l->args[i], l->op_code));
			}
			else if (d->op[l->op_nb - 1].params_types[i] == T_DIR + T_IND)
			{
				if (!dir(l->args[i][0]) && !ind(l->args[i][0]))
					return (error_arg_type(l->args[i], l->op_code));
			}
			i++;
		}
		l = l->next;
	}
	return (1);
}
