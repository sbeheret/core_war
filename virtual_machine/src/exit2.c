/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:14:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/13 15:24:20 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

void	ft_exit_parameter(char *argument, char *file)
{
	if (file == NULL)
		ft_printf("Error : Argument %s must be followed by a valid number"
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
	ft_printf("Error : Player number in file \"%s\" is already use", file);
	exit(0);
}
