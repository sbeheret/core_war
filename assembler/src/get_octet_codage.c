/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_octet_codage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:39:13 by esouza            #+#    #+#             */
/*   Updated: 2018/12/08 11:54:20 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		indirect(char b[], int *bit)
{
	b[*bit] = '1';
	(*bit)++;
	b[*bit] = '1';
	(*bit)++;
}

static void		direct(char b[], int *bit)
{
	b[*bit] = '1';
	(*bit)++;
	b[*bit] = '0';
	(*bit)++;
}

static void		aregister(char b[], int *bit)
{
	b[*bit] = '0';
	(*bit)++;
	b[*bit] = '1';
	(*bit)++;
}

static void		write_buff(t_labels *head, char b[])
{
	int			i;
	int			bit;

	i = 0;
	bit = 0;
	if (head->args)
	{
		while (head->args[i])
		{
			if (head->args[i][0] == DIRECT_CHAR)
				direct(b, &bit);
			else if (head->args[i][0] == 'r')
				aregister(b, &bit);
			else
				indirect(b, &bit);
			i++;
		}
	}
}

int				get_octet_codage(t_labels *head, int fd2)
{
	char	b[9];
	int		i;

	i = 0;
	while (i < 8)
	{
		b[i] = '0';
		i++;
	}
	b[i] = '\0';
	write_buff(head, b);
	ft_putchar_fd((unsigned char)binary_char_to_int(b), fd2);
	return (fd2);
}
