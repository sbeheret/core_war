/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:41:30 by esouza            #+#    #+#             */
/*   Updated: 2018/12/07 12:35:16 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			third_arg(t_data *d, t_labels *head, int fd2)
{
	if (arg_len(head) < 2)
		return (1);
	else if (head->args[TWO][ZERO] == 'r')
		write_register(head, TWO, fd2);
	else if (head->args[TWO][ZERO] == DIRECT_CHAR
			&& !d->op[head->op_nb - 1].dir_as_ind)
		write_direct_four(d, head, TWO, fd2);
	else if (head->args[TWO][ZERO] == DIRECT_CHAR
			&& d->op[head->op_nb - 1].dir_as_ind)
		write_two_octet(d, head, ONE, fd2);
	else if ((head->args[TWO][ZERO] == LABEL_CHAR)
			|| (head->args[TWO][ZERO] >= 0 && head->args[TWO][ZERO] <= 9))
		write_two_octet(d, head, TWO, fd2);
	return (0);
}
