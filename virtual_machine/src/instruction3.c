/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/29 18:19:54 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sti(t_vm *vm, t_processus *processus)
{
	(void)processus;
	//recupere 3 parametre
	// additionne les deux premier et traite comme une adresse
	//
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}

void	ft_fork(t_vm *vm, t_processus *processus)
{
	(void)processus;
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}

void	ft_lld(t_vm *vm, t_processus *processus)
{
	(void)processus;
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}

void	ft_lldi(t_vm *vm, t_processus *processus)
{
	(void)processus;
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}

void	ft_lfork(t_vm *vm, t_processus *processus)
{
	(void)processus;
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}
