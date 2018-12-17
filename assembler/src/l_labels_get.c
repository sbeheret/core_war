/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_labels_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:41:23 by dshults           #+#    #+#             */
/*   Updated: 2018/12/14 15:02:02 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17] =
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
	{{0}, 0, {0}, 0, 0, {0}, 0, 0}
};

static int	is_op_code(t_data *d, t_labels *lb, int label, int skip)
{
	int			len;

	if (!lb)
		lb = make_label(d->tab + d->y, 0, d->y - skip);
	len = find_op_code(lb, d->tab[d->y] + label, d->op);
	if (len == 0 || (len != 1 && !check_commas(d->tab[d->y] + label)))
		return (0);
	if (lb->op_nb != 0)
	{
		lb->args = ft_strsplit(d->tab[d->y] + len + label, SEPARATOR_CHAR);
		trim_spaces(lb->args);
	}
	add_to_label_list_end(d, lb);
	return (1);
}

static int	is_label(t_data *d, int len, int skip)
{
	t_labels	*lb;

	if (d->tab[d->y][len + 1]
		&& d->tab[d->y][len + 1] != ' ' && d->tab[d->y][len + 1] != '\t')
	{
		ft_printf("Line "S" has a bad char "C"\n",\
			d->tab[d->y], d->tab[d->y][len + 1]);
		return (0);
	}
	lb = make_label(d->tab + d->y, len, d->y - skip);
	len++;
	if (!is_op_code(d, lb, len, skip))
		return (0);
	return (1);
}

static int	get_all(t_data *d, int len, int skip, int ret)
{
	while (d->tab[d->y])
	{
		len = 0;
		while (ft_strchr_no_zero(LABEL_CHARS, d->tab[d->y][len]))
			len++;
		if (d->tab[d->y][len] == LABEL_CHAR)
			ret = is_label(d, len, skip);
		else if (d->tab[d->y][len] == ' ' || d->tab[d->y][len] == '\t'
				|| d->tab[d->y][len] == DIRECT_CHAR)
			ret = is_op_code(d, NULL, 0, skip);
		else
		{
			if (!d->tab[d->y][len])
				ft_printf("Invalide line "S"\n", d->tab[d->y]);
			else
				ft_printf("Line "S" has a bad char "C"\n",\
					d->tab[d->y], d->tab[d->y][len]);
			ret = 0;
		}
		if (!ret)
			return (0);
		d->y++;
	}
	return (1);
}

int			get_labels(t_data *d)
{
	d->op = g_op_tab;
	if (!get_all(d, 0, d->y, 0)
		|| !general_check(d)
		|| !compliance_check(d, d->first_label))
		return (0);
	add_bytes(d, d->first_label, 0);
	return (1);
}
