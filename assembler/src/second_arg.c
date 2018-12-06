/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:34:40 by esouza            #+#    #+#             */
/*   Updated: 2018/12/06 11:43:45 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			second_arg(t_labels *head, int fd2)
{
	if (arg_len(head) < 1)
		return (1);
	else if (head->args[ONE][ZERO] == 'r')
		write_register(head, ONE, fd2);
	return (0);
}
