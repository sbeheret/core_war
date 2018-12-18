/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:06 by esouza            #+#    #+#             */
/*   Updated: 2018/12/18 10:56:39 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			arg_len(t_labels *head)
{
	int		len;

	len = 0;
	if (!head->args || head->args[len] == NULL)
		return (-1);
	while (head->args[len])
		len++;
	return (len - 1);
}

int			write_register(t_labels *head, int idx, int fd2)
{
	ft_putchar_fd((unsigned char)ft_atoi(&head->args[idx][1]), fd2);
	return (0);
}

int			third_arg(t_data *d, t_labels *head, int fd2, int arnb)
{
	if (arnb < 2)
		return (1);
	else if (head->args[TWO][ZERO] == 'r')
		write_register(head, TWO, fd2);
	else if (head->args[TWO][ZERO] == DIRECT_CHAR
			&& !d->op[head->op_nb - 1].dir_as_ind)
		write_direct_four(d, head, TWO, fd2);
	else if (head->args[TWO][ZERO] == DIRECT_CHAR
			&& d->op[head->op_nb - 1].dir_as_ind)
		write_two_octet(d, head, TWO, fd2);
	else if ((head->args[TWO][ZERO] == LABEL_CHAR)
			|| (head->args[TWO][ZERO] >= '0' && head->args[TWO][ZERO] <= '9'))
		write_two_octet(d, head, TWO, fd2);
	else if ((head->args[TWO][ZERO] == '-')
			&& (head->args[TWO][ONE] >= '0' && head->args[TWO][ONE] <= '9'))
		write_two_octet(d, head, TWO, fd2);
	return (0);
}

int			second_arg(t_data *d, t_labels *head, int fd2, int arnb)
{
	if (arnb < 1)
		return (1);
	else if (head->args[ONE][ZERO] == 'r')
		write_register(head, ONE, fd2);
	else if (head->args[ONE][ZERO] == DIRECT_CHAR
			&& !d->op[head->op_nb - 1].dir_as_ind)
		write_direct_four(d, head, ONE, fd2);
	else if (head->args[ONE][ZERO] == DIRECT_CHAR
			&& d->op[head->op_nb - 1].dir_as_ind)
		write_two_octet(d, head, ONE, fd2);
	else if ((head->args[ONE][ZERO] == LABEL_CHAR)
			|| (head->args[ONE][ZERO] >= '0' && head->args[ONE][ZERO] <= '9'))
		write_two_octet(d, head, ONE, fd2);
	else if ((head->args[ONE][ZERO] == '-')
			&& (head->args[ONE][ONE] >= '0' && head->args[ONE][ONE] <= '9'))
		write_two_octet(d, head, ONE, fd2);
	return (0);
}

int			first_arg(t_data *d, t_labels *head, int fd2, int arnb)
{
	if (arnb < 0)
		return (1);
	else if (head->args[ZERO][ZERO] == 'r')
		write_register(head, ZERO, fd2);
	else if (head->args[ZERO][ZERO] == DIRECT_CHAR
			&& !d->op[head->op_nb - 1].dir_as_ind)
		write_direct_four(d, head, ZERO, fd2);
	else if (head->args[ZERO][ZERO] == DIRECT_CHAR
			&& d->op[head->op_nb - 1].dir_as_ind)
		write_two_octet(d, head, ZERO, fd2);
	else if ((head->args[ZERO][ZERO] == LABEL_CHAR)
			|| (head->args[ZERO][ZERO] >= '0' && head->args[ZERO][ZERO] <= '9'))
		write_two_octet(d, head, ZERO, fd2);
	else if ((head->args[ZERO][ZERO] == '-')
			&& (head->args[ZERO][ONE] >= '0' && head->args[ZERO][ONE] <= '9'))
		write_two_octet(d, head, ZERO, fd2);
	return (0);
}
