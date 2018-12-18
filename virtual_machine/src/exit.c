/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:14:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/18 14:25:04 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_exit_malloc(void)
{
	ft_putendl_fd("malloc fail", 2);
	exit(1);
}

void	ft_exit_nofile(t_vm *vm, char *file)
{
	ft_putstr_fd("Error : Couldn't open file \"", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\"\n", 2);
	ft_free_vm(vm);
	exit(1);
}

void	ft_exit_toosmall(t_vm *vm, char *file)
{
	ft_putstr_fd("Error : File \"", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\" is too small to be a champion\n", 2);
	ft_free_vm(vm);
	exit(1);
}

void	ft_exit_toobig(t_vm *vm, char *file)
{
	ft_putstr_fd("Error : File \"", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\" is too big to be a champion\n", 2);
	ft_free_vm(vm);
	exit(1);
}

void	ft_exit_usage(t_vm *vm)
{
	ft_putstr_fd("Usage: ./corewar [-dump N | -v N | -visu | -hex ]]", 2);
	ft_putstr_fd("[[-n N]] <champion1.cor>] <...>\n\n", 2);
	ft_putstr_fd("    -n N      : Change player number in ram\n", 2);
	ft_putstr_fd("#### TEXT OUTPUT MODE#################################\n", 2);
	ft_putstr_fd("    -dump N   : Dumps memory after N cycles then exits\n", 2);
	ft_putstr_fd("    -p        : Print processus state (use with -dump)\n", 2);
	ft_putstr_fd("    -v N      : Can be add together to enable multiple\n", 2);
	ft_putstr_fd("          	 - 1 : Show lives\n", 2);
	ft_putstr_fd("          	 - 2 : Show cycles\n", 2);
	ft_putstr_fd("          	 - 4 : Show operations\n", 2);
	ft_putstr_fd("          	 - 8 : Show deaths\n", 2);
	ft_putstr_fd("          	 -16 : Show PC movements\n", 2);
	ft_putstr_fd("#### CHAMPION OUTPUT MODE ############################\n", 2);
	ft_putstr_fd("    -hex      : Hexdump champion before starting\n", 2);
	ft_putstr_fd("#### NCURSES OUTPUT MODE #############################\n", 2);
	ft_putstr_fd("    -visu     : Ncurses output mode\n", 2);
	ft_putstr_fd("######################################################\n", 2);
	ft_free_vm(vm);
	exit(0);
}
