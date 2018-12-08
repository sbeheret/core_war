/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_op_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:50 by dshults           #+#    #+#             */
/*   Updated: 2018/12/08 12:36:38 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		op_l(t_labels *lb, char *str, int i, t_op *op)
{
	if (ft_strnequ(str + i, "live", 4)
		&& (str[i + 4] == ' ' || str[i + 4] == '\t'))
	{
		lb->op_code = op[0].name;
		lb->op_nb = op[0].id;
		return (i + 4);
	}
	else if (ft_strnequ(str + i, "ld", 2)
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		lb->op_code = op[1].name;
		lb->op_nb = op[1].id;
		return (i + 2);
	}
	else if (ft_strnequ(str + i, "ldi", 3)
		&& (str[i + 3] == ' ' || str[i + 3] == '\t'))
	{
		lb->op_code = op[9].name;
		lb->op_nb = op[9].id;
		return (i + 3);
	}
	else if (ft_strnequ(str + i, "lld", 3)
		&& (str[i + 3] == ' ' || str[i + 3] == '\t'))
	{
		lb->op_code = op[12].name;
		lb->op_nb = op[12].id;
		return (i + 3);
	}
	else if (ft_strnequ(str + i, "lldi", 4)
		&& (str[i + 4] == ' ' || str[i + 4] == '\t'))
	{
		lb->op_code = op[13].name;
		lb->op_nb = op[13].id;
		return (i + 4);
	}
	else if (ft_strnequ(str + i, "lfork", 5)
		&& (str[i + 5] == ' ' || str[i + 5] == '\t'))
	{
		lb->op_code = op[14].name;
		lb->op_nb = op[14].id;
		return (i + 5);
	}
	error_op_code(str + i);
	return (0);
}
