/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 14:24:38 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_live(int processus, unsigned int champion)
{
	ft_printf("P% 5d | live %d\n", processus, champion);
}

void	ft_print_ld(t_processus *processus, int arg1, int arg2)
{
	ft_printf("P% 5d | ld %d r%d\n", processus->processus_number
	, arg1, arg2);
}

void	ft_print_st(t_processus *processus, int arg1, int arg2)
{
	ft_printf("P% 5d | st r%d ", processus->processus_number, arg1);
	ft_printf("%hd\n", arg2);
}

void	ft_print_add(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P% 5d | add r%d r%d r%d\n",
	processus->processus_number, arg1, arg2, arg3);
}

void	ft_print_sub(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P% 5d | sub r%d r%d r%d\n",
	processus->processus_number, arg1, arg2, arg3);
}
