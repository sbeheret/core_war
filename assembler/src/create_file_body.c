/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:49:39 by esouza            #+#    #+#             */
/*   Updated: 2018/12/07 11:43:06 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			create_file_body(t_data *d, int fd2)
{
	t_labels		*head;

	head = d->first_label;
	while (head)
	{
		get_opcode(head, fd2);
		if (d->op[head->op_nb - 1].encoded_byte)
			get_octet_codage(head, fd2);
		first_arg(d, head, fd2);
		second_arg(d, head, fd2);
		third_arg(head, fd2);
		head = head->next;
	}

	return (fd2);
}
