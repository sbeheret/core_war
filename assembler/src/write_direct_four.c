/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_direct_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:23:42 by esouza            #+#    #+#             */
/*   Updated: 2018/12/06 17:28:17 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

 static void    ft_int_to_octet(int fd2, int value)
{
	char c;

	c = value >> 24;
	write(fd2, &c, 1);
	c = (value & 0x00FF0000) >> 16;
	write(fd2, &c, 1);
	c = (value & 0x0000FF00) >> 8;
	write(fd2, &c, 1);
	c = value & 0x000000FF;
	write(fd2, &c, 1);
}

int			write_direct_four(t_labels *head, int idx, int fd2)
{
	long int nb;
   
	nb = ft_atoi(&head->args[idx][1]);
	ft_int_to_octet(fd2, nb);
	return (0);
}
