/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:22:23 by rfibigr           #+#    #+#             */
/*   Updated: 2017/11/26 11:38:33 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (!(str = (void *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (i < size)
		str[i++] = 0;
	return (str);
}
