/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:52:03 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/16 14:38:49 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_content_value(unsigned char *ram, t_processus *pcs, int type,
		int address)
{
	if (type == 1)
		return (pcs->reg[address]);
	else if (type == 3)
	{
		address = circular(pcs->action.pc + (address % IDX_MOD));
		return (ft_octet_to_int2(ram, REG_SIZE, address));
	}
	else
		return (address);
}

int		get_long_content_value(unsigned char *ram, t_processus *pcs, int type,
		int address)
{
	if (type == 1)
		return (pcs->reg[address]);
	else if (type == 3)
	{
		address = circular(pcs->action.pc + address);
		return (ft_octet_to_int2(ram, REG_SIZE, address));
	}
	else
		return (address);
}
