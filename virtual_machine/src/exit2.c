/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:14:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 15:52:37 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_exit_toomanychamp(void)
{
	ft_printf("Error : Too many champions\n");
	exit(0);
}

void	ft_exit_magicnumber(char *file)
{
	ft_printf("Error : File \"%s\" has an invalid magic_number\n", file);
	exit(0);
}

void	ft_exit_header(char *file)
{
	ft_printf("Error : File \"%s\" has an invalid header\n", file);
	exit(0);
}

void	ft_exit_parameter(char *argument, char *file)
{
	if (file == NULL)
		ft_printf("Error : Argument %s must be followed by a valid number\n"
		, argument);
	else
	{
		ft_printf("Error : Argument %s in file \"%s\" ", argument, file);
		ft_printf("must be followed by a valid number\n");
	}
	exit(0);
}

void	ft_exit_playernumber(char *file)
{
	ft_printf("Error : Player number in file \"%s\" is already use\n", file);
	exit(0);
}
