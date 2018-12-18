/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:21:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/18 14:06:56 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_exit_visu(t_vm *vm)
{
	ft_free_vm(vm);
	exit(0);
}

void	ft_exit_dump(t_vm *vm)
{
	size_t i;

	i = 0;
	if (vm->flag_processus == 1)
		print_processus(vm->processus);
	while (i < MEM_SIZE)
	{
		if (!(i % 64))
		{
			ft_printf("\n");
			ft_printf("0X");
			ft_printf("%.4X : ", i);
		}
		ft_printf("%hhx", (*vm).ram[i] / 16);
		ft_printf("%hhx", (*vm).ram[i] % 16);
		ft_printf(" ");
		i++;
	}
	ft_printf("\n");
	ft_free_vm(vm);
	exit(0);
}

void	ft_exit_nochamp(t_vm *vm, char *file)
{
	ft_putstr_fd("Error : File \"", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\" is has a champion without instruction\n", 2);
	ft_free_vm(vm);
	exit(1);
}
