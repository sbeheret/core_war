/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/30 17:25:05 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sti(t_vm *vm, t_processus *processus)
{
	int		value1;
	int		value2;
	char	*str;
	int		i;

	i = -1;
	ft_printf("~~~STI~~~\n");
	if (processus->action.args[0] < 1 || processus->action.args[0] > 16)
		return ;
	if (processus->action.type[1] == 1)
		value1 = processus->reg[processus->action.args[1] - 1];
	else
		value1 = processus->action.args[1];
	if (processus->action.type[2] == 1)
		value2 = processus->reg[processus->action.args[2] - 1];
	else
		value2 = processus->action.args[2];
	str = ft_int_to_octet(processus->reg[processus->action.args[0] - 1]);
	value1 = circular(value1 + value2);
	while (++i < 4)
		vm->ram[value1 + i] = str[i];
	free(str);
	// argments 1, 2 et 3
	// 2 + 3 = adresse
	// write 1 at adresse
}

void	ft_fork(t_vm *vm, t_processus *processus)
{
	t_processus *copy;
	int	i;

	copy = new_processus(0, processus->PC % IDX_MOD);
	i = -1;
	while (++i <= 15)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;
	push_front_pcs(&(*vm).processus, copy);
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
	t_processus *copy;
	int	i;

	copy = new_processus(0, processus->PC);
	i = -1;
	while (++i <= 15)
		copy->reg[i] = processus->reg[i];
	copy->carry = processus->carry;
	push_front_pcs(&(*vm).processus, copy);
}
