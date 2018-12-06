/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:41:30 by esouza            #+#    #+#             */
/*   Updated: 2018/12/06 11:42:34 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			third_arg(t_labels *head, int fd2)
{
	if (arg_len(head) < 2)
		return (1);
	else if (head->args[TWO][ZERO] == 'r')
		write_register(head, TWO, fd2);
	return (0);
}
