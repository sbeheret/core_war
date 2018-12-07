/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:16:24 by esouza            #+#    #+#             */
/*   Updated: 2018/12/07 09:49:51 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		op_codenb2(t_labels *head)
{
	if (ft_strcmp(head->op_code, "sti") == 0)
		return (11);
	else if (ft_strcmp(head->op_code, "fork") == 0)
		return (12);
	else if (ft_strcmp(head->op_code, "lld") == 0)
		return (13);
	else if (ft_strcmp(head->op_code, "lldi") == 0)
		return (14);
	else if (ft_strcmp(head->op_code, "lfork") == 0)
		return (15);
	else if (ft_strcmp(head->op_code, "aff") == 0)
		return (16);
	return (0);

}

static int		op_codenb(t_labels *head)
{
	if (ft_strcmp(head->op_code, "live") == 0)
		return (1);
	else if (ft_strcmp(head->op_code, "ld") == 0)
		return (2);
	else if (ft_strcmp(head->op_code, "st") == 0)
		return (3);
	else if (ft_strcmp(head->op_code, "add") == 0)
		return (4);
	else if (ft_strcmp(head->op_code, "sub") == 0)
		return (5);
	else if (ft_strcmp(head->op_code, "and") == 0)
		return (6);
	else if (ft_strcmp(head->op_code, "or") == 0)
		return (7);
	else if (ft_strcmp(head->op_code, "xor") == 0)
		return (8);
	else if (ft_strcmp(head->op_code, "zjmp") == 0)
		return (9);
	else if (ft_strcmp(head->op_code, "ldi") == 0)
		return (10);
	else
		return (op_codenb2(head));
	return (0);
}

int				get_opcode(t_labels *head, int fd2)
{
	if (head->op_code == NULL)
		return (1);
	ft_putchar_fd((unsigned char)op_codenb(head), fd2);
	return (0);
}
