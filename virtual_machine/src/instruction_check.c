/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:49:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/11 15:48:24 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// t_reg = 1
// t_dir = 2
// t_ind = 4
//
// t_dir | t_reg = 3
// t_dir | t_ind = 6
// t_reg | t_ind = 5
//
// t_dir | t_ind | t_reg = 7
//
// si reg il faut = (1 || 3 || 5 || 7)  != 2 && != 6
// si dir il faut = (2 || 3 || 7 )		!= 1 && != 4 && !=5 && 6
// si ind il faut = (4 || 5 || 6 || 7)


// verfier si nombre de parametre est le bon 					OK
// verfier si type parametre									OK
// verfier si parametre correct suivant le type					OK

// si incorrect,
// PC = actuel + 2

// si correct
// instruction

int		ft_get_ind(t_vm *vm, t_processus *processus, int arg)
{
	int				address;
	short			argument;
	(void)*vm;

	argument = (short)(*processus).action.args[arg];
	address = circular((*processus).action.pc + (argument % IDX_MOD));
	return(address);
}

int		ft_get_lind(t_vm *vm, t_processus *processus, int arg)
{
	int				address;
	int				argument;

	argument = (*processus).action.args[arg];
	address = circular((*processus).action.pc + (short)argument);
	return(ft_octet_to_int2((*vm).ram, REG_SIZE, address));
}
