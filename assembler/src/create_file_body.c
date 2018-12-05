/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:49:39 by esouza            #+#    #+#             */
/*   Updated: 2018/12/05 14:29:23 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			create_file_body(t_data *d, int fd2)
{
	t_labels		*head;

	head = d->first_label;
	while (head)
	{
		printf(">>1 {%s}\n", head->args[0]);
		printf(">>2 {%s}\n", head->args[1]);
		printf(">>3 {%s}\n", head->args[2]);
		head = head->next;
	}

	return (fd2);
}
