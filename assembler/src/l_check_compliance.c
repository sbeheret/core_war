/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_check_compliance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:42 by dshults           #+#    #+#             */
/*   Updated: 2018/12/08 12:29:49 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	reg(char c)
{
	if (c == 'r')
		return (1);
	return (0);
}

static int	dir(char c)
{
	if (c == DIRECT_CHAR)
		return (1);
	return (0);
}

static int	ind(char c)
{
	if (c == 'r' || c == DIRECT_CHAR)
		return (0);
	return (1);
}

static int	combos(t_data *d, t_labels *l, int a)
{
	if (d->op[l->op_nb - 1].params_types[a] == T_REG + T_DIR)
	{
		if (!reg(l->args[a][0]) && !dir(l->args[a][0]))
			return (0);
	}
	else if (d->op[l->op_nb - 1].params_types[a] == T_REG + T_IND)
	{
		if (!reg(l->args[a][0]) && !ind(l->args[a][0]))
			return (0);
	}
	else if (d->op[l->op_nb - 1].params_types[a] == T_DIR + T_IND)
	{
		if (!dir(l->args[a][0]) && !ind(l->args[a][0]))
			return (0);
	}
	return (1);
}

int			compliance_check(t_data *d, t_labels *l)
{
	int		a;
	int		ret;

	while (l)
	{
		a = 0;
		while (a < d->op[l->op_nb - 1].params_nb && l->op_nb != 0)
		{
			ret = 0;
			if (d->op[l->op_nb - 1].params_types[a] == T_REG)
				ret = reg(l->args[a][0]);
			else if (d->op[l->op_nb - 1].params_types[a] == T_DIR)
				ret = dir(l->args[a][0]);
			else if (d->op[l->op_nb - 1].params_types[a] == T_IND)
				ret = ind(l->args[a][0]);
			else if (combos(d, l, a))
				ret = 1;
			if (!ret)
				return (error_arg_type(l->args[a], l->op_code));
			a++;
		}
		l = l->next;
	}
	return (1);
}
