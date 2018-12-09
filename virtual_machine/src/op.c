/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <zaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2018/12/07 16:39:41 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

/*
** tab[0]= {"live", 1, {2,0,0}, 1, 10, alive, 0, 0}
** tab[1]= {"ld", 2, {6,1,0}, 2, 5, load, 1, 0}
** tab[2]= {"st", 2, {1,5,0}, 3, 5, store, 1, 0}
** tab[3]= {"add", 3, {1,1,1}, 4, 10, addition, 1, 0}
** tab[4]= {"sub", 3, {1,1,1}, 5, 10, soustraction, 1, 0}
** tab[5]= {"and", 3, {7,7,1}, 6, 6, et (and  r1, r2, r3   r1&r2 -> r3, 1, 0}
** tab[6]= {"or", 3, {7,7,1}, 7, 6, ou  (or   r1, r2, r3   r1 | r2 -> r3, 1, 0}
** tab[7]= {"xor", 3, {7,7,1}, 8, 6, ou (xor  r1, r2, r3   r1^r2 -> r3, 1, 0}
** tab[8]= {"zjmp", 1, {2,0,0}, 9, 20, jump if zero, 0, 1}
** tab[9]= {"ldi", 3, {7,3,1}, 10, 25, load index, 1, 1}
** tab[10]= {"sti", 3, {1,7,3}, 11, 25, store index, 1, 1}
** tab[11]= {"fork", 1, {2,0,0}, 12, 800, fork, 0, 1}
** tab[12]= {"lld", 2, {6,1,0}, 13, 10, long load, 1, 0}
** tab[13]= {"lldi", 3, {7,3,1}, 14, 50, long load index, 1, 1}
** tab[14]= {"lfork", 1, {2,0,0}, 15, 1000, long fork, 0, 1}
** tab[15]= {"aff", 1, {1,0,0}, 16, 2, aff, 1, 0}
** tab[16]= {"(null)", 0, {0,0,0}, 0, 0, (null), 0, 0}
*/
