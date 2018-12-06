/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_direct_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:23:42 by esouza            #+#    #+#             */
/*   Updated: 2018/12/06 15:40:12 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			write_direct_four(t_labels *head, int idx, int fd2)
{
	int len = ft_strlen(&head->args[idx][1]);
	long int nb = ft_atoi(&head->args[idx][1]);
	unsigned int hex32;
	hex32 = nb & 0xFFFFFFFF;
	printf(">> %lu len \t%d\n", sizeof(hex32), len);
	ft_putchar_fd(hex32, fd2);
	return (0);
}
