/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_direct_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:23:42 by esouza            #+#    #+#             */
/*   Updated: 2018/12/18 10:56:34 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		int_to_octet(int fd2, int value)
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

void		short_to_octet(int fd2, int value)
{
	char	c;

	c = (value & 0x0000FF00) >> 8;
	write(fd2, &c, 1);
	c = value & 0x000000FF;
	write(fd2, &c, 1);
}

int			write_two_octet(t_data *d, t_labels *head, int idx, int fd2)
{
	long long		nb;
	int				i;

	i = 0;
	if (head->args[idx][1] == LABEL_CHAR || head->args[idx][ZERO] == LABEL_CHAR)
	{
		nb = bytes_till_label(d->first_label, head, idx);
		short_to_octet(fd2, nb);
		return (0);
	}
	if (head->args[idx][0] == LABEL_CHAR || head->args[idx][0] == DIRECT_CHAR)
		i++;
	if (head->args[idx][i] == LABEL_CHAR)
		i++;
	nb = long_atoi(&head->args[idx][i]);
	short_to_octet(fd2, nb);
	return (0);
}

int			write_direct_four(t_data *d, t_labels *head, int idx, int fd2)
{
	long int	nb;
	int			i;

	i = 1;
	if (head->args[idx][1] == LABEL_CHAR || head->args[idx][ZERO] == LABEL_CHAR)
	{
		nb = bytes_till_label(d->first_label, head, idx);
		int_to_octet(fd2, nb);
		return (0);
	}
	if (head->args[idx][i] == LABEL_CHAR)
		i++;
	nb = long_atoi(&head->args[idx][i]);
	int_to_octet(fd2, nb);
	return (0);
}
