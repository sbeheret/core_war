/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:14:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/18 14:06:55 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_exit_toomanychamp(t_vm *vm)
{
	ft_putendl_fd("Error : Too many champions", 2);
	ft_free_vm(vm);
	exit(0);
}

void	ft_exit_magicnumber(t_vm *vm, char *file)
{
	ft_putstr_fd("Error : File \"", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\" has an invalid magic_number\n", 2);
	ft_free_vm(vm);
	exit(0);
}

void	ft_exit_header(t_vm *vm, char *file)
{
	ft_putstr_fd("Error : File \"", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\" has an invalid header\n", 2);
	ft_free_vm(vm);
	exit(0);
}

void	ft_exit_parameter(t_vm *vm, char *argument, char *file)
{
	if (file == NULL)
	{
		ft_putstr_fd("Error : Argument \"", 2);
		ft_putstr_fd(argument, 2);
		ft_putstr_fd("\" must be followed by a valid number\n", 2);
	}
	else
	{
		ft_putstr_fd("Error : Argument \"", 2);
		ft_putstr_fd(argument, 2);
		ft_putstr_fd("\" in file \"", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\" must be followed by a valid number\n", 2);
	}
	ft_free_vm(vm);
	exit(0);
}

void	ft_exit_playernumber(t_vm *vm, char *file)
{
	ft_putstr_fd("Error : Player number in file \"", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\" is already use\n", 2);
	ft_free_vm(vm);
	exit(0);
}
