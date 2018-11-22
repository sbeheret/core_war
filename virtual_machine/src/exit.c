/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:14:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/22 15:30:42 by rfibigr          ###   ########.fr       */
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
	ft_printf("Error : Couldn't open file %s", file);
	exit(1);
}
