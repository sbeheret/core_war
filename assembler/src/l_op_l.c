/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_op_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:50 by dshults           #+#    #+#             */
/*   Updated: 2018/12/09 18:46:05 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	lld_lldi_lfork(t_labels *lb, char *str, int i, t_op *op)
{
	if (ft_strnequ(str + i, "lldi", 4))
	{
		lb->op_code = op[13].name;
		lb->op_nb = op[13].id;
		return (i + 4);
	}
	else if (ft_strnequ(str + i, "lld", 3))
	{
		lb->op_code = op[12].name;
		lb->op_nb = op[12].id;
		return (i + 3);
	}
	else if (ft_strnequ(str + i, "lfork", 5))
	{
		lb->op_code = op[14].name;
		lb->op_nb = op[14].id;
		return (i + 5);
	}
	error_op_code(str + i);
	return (0);
}

int			op_l(t_labels *lb, char *str, int i, t_op *op)
{
	if (ft_strnequ(str + i, "live", 4))
	{
		lb->op_code = op[0].name;
		lb->op_nb = op[0].id;
		return (i + 4);
	}
	else if (ft_strnequ(str + i, "ldi", 3))
	{
		lb->op_code = op[9].name;
		lb->op_nb = op[9].id;
		return (i + 3);
	}
	else if (ft_strnequ(str + i, "ld", 2))
	{
		lb->op_code = op[1].name;
		lb->op_nb = op[1].id;
		return (i + 2);
	}
	return (lld_lldi_lfork(lb, str, i, op));
}
