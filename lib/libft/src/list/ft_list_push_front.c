/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:37:31 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 16:48:31 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin, void const *content)
{
	t_list	*to_add;

	to_add = ft_lstnew(content);
	if (*begin == NULL)
		*begin = to_add;
	else
	{
		to_add->next = *begin;
		*begin = to_add;
	}
}
