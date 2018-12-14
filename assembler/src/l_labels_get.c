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

#include "op.c"

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
//	show_labels(d);
	return (1);
}
