/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:27:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/31 16:43:34 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	int counter;

	counter = 0;
	if (begin_list == NULL)
		return (0);
	while (begin_list)
	{
		begin_list = begin_list->next;
		counter++;
	}
	return (counter);
}
