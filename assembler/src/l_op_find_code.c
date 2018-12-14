/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_op_find_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:50 by dshults           #+#    #+#             */
/*   Updated: 2018/12/09 18:36:34 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	s(t_labels *lb, char *str, int i, t_op *op)
{
	if (ft_strnequ(str + i, "sti", 3))
	{
		lb->op_code = op[10].name;
		lb->op_nb = op[10].id;
		return (i + 3);
	}
	else if (ft_strnequ(str + i, "st", 2))
	{
		lb->op_code = op[2].name;
		lb->op_nb = op[2].id;
		return (i + 2);
	}
	else if (ft_strnequ(str + i, "sub", 3))
	{
		lb->op_code = op[4].name;
		lb->op_nb = op[4].id;
		return (i + 3);
	}
	error_op_code(str + i);
	return (0);
}

static int	a(t_labels *lb, char *str, int i, t_op *op)
{
	if (ft_strnequ(str + i, "add", 3))
	{
		lb->op_code = op[3].name;
		lb->op_nb = op[3].id;
		return (i + 3);
	}
	else if (ft_strnequ(str + i, "and", 3))
	{
		lb->op_code = op[5].name;
		lb->op_nb = op[5].id;
		return (i + 3);
	}
	else if (ft_strnequ(str + i, "aff", 3))
	{
		lb->op_code = op[15].name;
		lb->op_nb = op[15].id;
		return (i + 3);
	}
	error_op_code(str + i);
	return (0);
}

static int	f_o(t_labels *lb, char *str, int i, t_op *op)
{
	if (str[i] == 'f')
	{
		if (ft_strnequ(str + i, "fork", 4))
		{
			lb->op_code = op[11].name;
			lb->op_nb = op[11].id;
			return (i + 4);
		}
	}
	else if (str[i] == 'o')
	{
		if (ft_strnequ(str + i, "or", 2))
		{
			lb->op_code = op[6].name;
			lb->op_nb = op[6].id;
			return (i + 2);
		}
	}
	error_op_code(str + i);
	return (0);
}

static int	x_z(t_labels *lb, char *str, int i, t_op *op)
{
	if (str[i] == 'x')
	{
		if (ft_strnequ(str + i, "xor", 3))
		{
			lb->op_code = op[7].name;
			lb->op_nb = op[7].id;
			return (i + 3);
		}
	}
	else if (str[i] == 'z')
	{
		if (ft_strnequ(str + i, "zjmp", 4))
		{
			lb->op_code = op[8].name;
			lb->op_nb = op[8].id;
			return (i + 4);
		}
	}
	error_op_code(str + i);
	return (0);
}

int			find_op_code(t_labels *lb, char *str, t_op *op)
{
	int	i;

	i = 0;
	if (!str || !str[0])
	{
		lb->bytes = 0;
		return (1);
	}
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == 'l')
		return (op_l(lb, str, i, op));
	else if (str[i] == 's')
		return (s(lb, str, i, op));
	else if (str[i] == 'a')
		return (a(lb, str, i, op));
	else if (str[i] == 'f' || str[i] == 'o')
		return (f_o(lb, str, i, op));
	else if (str[i] == 'x' || str[i] == 'z')
		return (x_z(lb, str, i, op));
	error_op_code(str + i);
	return (0);
}
