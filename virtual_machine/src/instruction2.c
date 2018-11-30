/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/29 18:19:22 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_and(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// recuperer 3 parameteres / parametre 3 un registre
	// le carry

	// registre 3 = param1 & param2
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}

void	ft_or(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// recuperer 3 parameteres / parametre 3 un registre
	// le carry

	// registre 3 = param1 | param2
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}

void	ft_xor(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// recuperer 3 parameteres / parametre 3 un registre
	// le carry

	// registre 3 = param1 |xor param2
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}

void	ft_zjump(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// recuperer l'index
	// changer la valeur de PC si carry = 1, sinon PC + 1
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}

void	ft_ldi(t_vm *vm, t_processus *processus)
{
	(void)processus;
	// recuerer 2 index et un registre
	// additionne les deux premier et traite comme une adresse
	// lire une valeur de la taille d'un registre (4 octets) et la stocker dans 3 params
	ft_printf("nb_champ = %d", (*vm).nb_champs);

}
