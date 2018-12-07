/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:34:40 by esouza            #+#    #+#             */
/*   Updated: 2018/12/07 11:49:03 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			second_arg(t_data *d, t_labels *head, int fd2)
{
	if (arg_len(head) < 1)
		return (1);
	else if (head->args[ONE][ZERO] == 'r')
		write_register(head, ONE, fd2);
	else if (head->args[ONE][ZERO] == DIRECT_CHAR
			&& !d->op[head->op_nb - 1].dir_as_ind)
		write_direct_four(head, ONE, fd2);
	else if (head->args[ONE][ZERO] == DIRECT_CHAR
			&& d->op[head->op_nb - 1].dir_as_ind)
		write_two_octet(head, ONE, fd2);
	else if ((head->args[ONE][ZERO] == LABEL_CHAR)
			|| (head->args[ONE][ZERO] >= 0 && head->args[ONE][ZERO] <= 9))
		write_two_octet(head, ONE, fd2);
	return (0);
}
