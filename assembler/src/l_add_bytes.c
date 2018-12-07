/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_add_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:58 by dshults           #+#    #+#             */
/*   Updated: 2018/12/02 15:42:59 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void    live_ld_st_add_sub_zjmp_fork_lfork(t_labels *l)
{
	if (l->op_nb == LIVE)
		l->bytes += DIR_SIZE; //T_DIR
	else if (l->op_nb == ZJMP || l->op_nb == FORK || l->op_nb == LFORK) //exceptions
		l->bytes += IND_SIZE; //T_DIR
	else if (l->op_nb == LD)
	{//T_IND | T_DIR, T_REG
		if (l->args[0][0] == DIRECT_CHAR)
			l->bytes += DIR_SIZE + 1;
		else
			l->bytes += IND_SIZE + 1;
	}
	else if (l->op_nb == ST)
	{//T_REG, T_IND | T_REG
		if (l->args[0][0] == 'r')
			l->bytes += 1 + 1;
		else
			l->bytes += 1 + IND_SIZE;
	}
	else if (l->op_nb == ADD || l->op_nb == SUB)
		l->bytes += 1 + 1 + 1; //T_REG, T_REG, T_REG
}

static void    and_or_xor_lld_aff(t_labels *l)
{
	if (l->op_nb == AND || l->op_nb == OR || l->op_nb == XOR)
	{//T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG
		if (l->args[0][0] == 'r')
			l->bytes += 1;
		else if (l->args[0][0] == DIRECT_CHAR)
			l->bytes += DIR_SIZE;
		else
			l->bytes += IND_SIZE;
		if (l->args[1][0] == 'r')
			l->bytes += 1;
		else if (l->args[1][0] == DIRECT_CHAR)
			l->bytes += DIR_SIZE;
		else
			l->bytes += IND_SIZE;
		l->bytes += 1;
	}
	else if (l->op_nb == LLD)
	{//T_DIR | T_IND, T_REG
		if (l->args[0][0] == DIRECT_CHAR)
			l->bytes += DIR_SIZE + 1;
		else
			l->bytes += IND_SIZE + 1;
	}
	else if (l->op_nb == AFF) //T_REG
		l->bytes += 1;
}
//lldi - Same as ´ldi´ but we do not use ´% IND_MOD´ with our first parameter ???????
static void    ldi_lldi_sti(t_labels *l)
{
    if (l->op_nb == LDI || l->op_nb == LLDI) //dir is treated as ind
    {//T_REG| T_IND | T_DIR, T_DIR | T_REG, T_REG
        if (l->args[0][0] == 'r')
            l->bytes += 1;
        else
            l->bytes += IND_SIZE;
        if (l->args[1][0] == 'r')
            l->bytes += 1;
        else
            l->bytes += IND_SIZE;
        l->bytes += 1;
    }
    else if (l->op_nb == STI) //dir is treated as ind
    {//T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG
        l->bytes += 1;
        if (l->args[1][0] == 'r')
            l->bytes += 1;
        else
            l->bytes += IND_SIZE;
        if (l->args[2][0] == 'r')
            l->bytes += 1;
        else
            l->bytes += IND_SIZE;
    }
}

void    add_bytes(t_data *d)
{
    t_labels    *l;

    l = d->first_label;
    while (l)
    {
		if (l->op_nb == 0)
		{
			l = l->next;
			continue;
		}
        l->bytes += d->op[l->op_nb - 1].encoded_byte;
        if ((l->op_nb >= LIVE && l->op_nb <= SUB) ||
            l->op_nb == ZJMP || l->op_nb == FORK || l->op_nb == LFORK)
            live_ld_st_add_sub_zjmp_fork_lfork(l);
        else if ((l->op_nb >= AND && l->op_nb <= XOR) ||
                l->op_nb == LLD || l->op_nb == AFF)
            and_or_xor_lld_aff(l);
        else if (l->op_nb == LDI || l->op_nb == LLDI || l->op_nb == STI)
            ldi_lldi_sti(l);
        d->total_bytes += l->bytes;
        l = l->next;
    }
}
