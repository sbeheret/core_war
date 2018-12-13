/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:14:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/13 13:57:09 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_exit_malloc(void)
{
	ft_printf("malloc fail\n");
	exit(1);
}

void	ft_exit_nofile(char *file)
{
	ft_printf("Error : Couldn't open file \"%s\"\n", file);
	exit(1);
}

void	ft_exit_toosmall(char *file)
{
	ft_printf("Error : File \"%s\" is too small to be a champion\n", file);
	exit(1);
}

void	ft_exit_toobig(char *file)
{
	ft_printf("Error : File \"%s\" is too big to be a champion\n", file);
	exit(1);
}

void	ft_exit_usage(void)
{
	ft_printf("Usage : ./corewar [-dump nbr_cycles] [-verbose] [-v]");
	ft_printf("[[-n number] champion1.cor]\n");
	exit(0);
}
