/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/30 10:36:35 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_vm *vm, t_processus *processus)
{
	// adresse du nom du programme dans la ram
	// ecrire dans processus lives
	//		pour ca il me faut le processus
	// ecrire dans VM last_alive
	// (printf (champion name))

	// t_action action;
	//
	// action = (*vm).processus->action;j
	// (*vm).last_alive =

	processus->lives++;
	ft_printf("ft_ld = %d", (*vm).nb_champs);
}

void	ft_ld(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// les deux parametre dans actions
	// le carry

	// registre [x] = param1
	ft_printf("ft_ld = %d", (*vm).nb_champs);

}

void	ft_st(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// les deux parametre dans actions

	// param 2 = registre [x]
	ft_printf("ft_st = %d", (*vm).nb_champs);

}

void	ft_add(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// recuperer 3 registres
	// le carry

	// registre 3 =registre 1 + registre 2
	ft_printf("ft_add = %d", (*vm).nb_champs);

}

void	ft_sub(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// recuperer 3 registres
	// le carry

	// registre 3 =registre 1 - registre 2
	ft_printf("ft_sub = %d", (*vm).nb_champs);

}
