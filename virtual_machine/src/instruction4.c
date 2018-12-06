/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/30 17:07:05 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_aff(t_vm *vm, t_processus *processus)
{
	(void)vm;
	t_action		action;
	int				arg1;

	action = processus->action;
	arg1 = action.args[0];
	if (arg1 < 1 || arg1 > 16)
		return;
	if (action.type[1] == REG && arg1 > 1 && arg1 < 16)
	{
		ft_printf("%c", processus->reg[arg1] % 256);
		return;
	}
}
