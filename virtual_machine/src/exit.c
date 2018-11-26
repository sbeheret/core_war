/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:14:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/26 17:15:22 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_exit_malloc(void)
{
	// use perror and errno
	ft_printf("malloc fail");
	exit(1);
}

void	ft_exit_nofile(char *file)
{
	// use perror and errno
	ft_printf("Error : Couldn't open file \"%s\"", file);
	exit(1);
}

void	ft_exit_toosmall(char *file)
{
	ft_printf("Error : File \"%s\" is too small to be a champion", file);
	exit(1);
}

void	ft_exit_toobig(char *file)
{
	ft_printf("Error : File \"%s\" is too big to be a champion", file);
	exit(1);
}

void	ft_exit_usage(void)
{
	ft_printf("Usage : ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ");
	exit(0);
}

void	ft_exit_toomanychamp(void)
{
	ft_printf("Error : Too many champions");
	exit(0);
}

void	ft_exit_magicnumber(char *file)
{
	ft_printf("Error : File \"%s\" has an invalid magic_number", file);
	exit(0);
}

void	ft_exit_header(char *file)
{
	ft_printf("Error : File \"%s\" has an invalid header", file);
	exit(0);
}
