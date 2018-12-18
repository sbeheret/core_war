/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/17 12:01:20 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_aff(t_vm *vm, t_processus *processus)
{
	t_action		action;
	int				arg1;

	action = processus->action;
	arg1 = action.args[0];
	if (action.type[1] == REG)
	{
		if (!vm->visu)
			ft_printf("%c", processus->reg[arg1] % 256);
		return ;
	}
}
