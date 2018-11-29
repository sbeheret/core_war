/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/29 15:12:40 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_vm *vm)
{
	ft_printf("live = %d", (*vm).nb_champs);

}

void	ft_ld(t_vm *vm)
{
	ft_printf("ft_ld = %d", (*vm).nb_champs);

}

void	ft_st(t_vm *vm)
{
	ft_printf("ft_st = %d", (*vm).nb_champs);

}

void	ft_add(t_vm *vm)
{
	ft_printf("ft_add = %d", (*vm).nb_champs);

}

void	ft_sub(t_vm *vm)
{
	ft_printf("ft_sub = %d", (*vm).nb_champs);

}
