/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:06 by esouza            #+#    #+#             */
/*   Updated: 2018/12/06 12:21:46 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			arg_len(t_labels *head)
{
	int		len;

	len = 0;
	if (head->args[len] == NULL)
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

int			first_arg(t_labels *head, int fd2)
{
	if (arg_len(head) < 0)
		return (1);
	else if (head->args[ZERO][ZERO] == 'r')
		write_register(head, ZERO, fd2);
	else if (head->args[ZERO][ZERO] == DIRECT_CHAR)
		write_direct_four(head, ZERO, fd2);
	return (0);
}
