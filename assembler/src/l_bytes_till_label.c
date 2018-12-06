/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_calc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:30 by dshults           #+#    #+#             */
/*   Updated: 2018/12/02 15:54:38 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int    count(int pos, t_labels *l)
{
	int    i;
	int    bytes;

	bytes = 0;
	i = 0;
	while (i < pos)
	{
		bytes += l->bytes;
		i++;
		l = l->next;
	}
	return (bytes);
}

static int    rew_count(t_labels *f, int cp, int lp)
{
	int    bytes;

	bytes = 0;
	while (f && f->position < lp)
		f = f->next;
	while (f && f->position < cp)
	{
		bytes -= f->bytes;
		f = f->next;
	}
	return (bytes);
}

/*
**	first_label		starting point in the linked list
**	current 		start calculating from this label
**	arg				argument number that contains the label call
**
**	EXAMPLE
**
**	 label comes after the call (consecutive order, result is positive number):
**				and %:live, r1, r2
**		live:	live %1
**
**	 |	bytes_till_label(d->first_label, current, 0)
**	 |		==	8 (8 in hex)
**
**
**	 label is before the call (reverse order, result is negative number):
**		live:	live %1
**				and %:live, r1, r2
**
**	 |	bytes_till_label(d->first_label, current, 0)
**	 |		==	(-8 converted to unsigned int) 4294967291 (fffffffb in hex)
**
*/

int    bytes_till_label(t_labels *first_label, t_labels *current, int arg)
{
	t_labels *l;
	int		i;
	int		skip_chars;

	l = first_label;
	i = 0;
	if (current->args[arg][0] == LABEL_CHAR)
		skip_chars = 1;
	else
		skip_chars = 2;
	while (l)
	{
		if (ft_strequ(l->name, current->args[arg] + skip_chars))
		{
			if (l->position > current->position)
				i += count(l->position - current->position, current);
			else
				i += (unsigned int)rew_count(first_label,
						current->position, l->position);
		}
		l = l->next;
	}
	return (i);
}
