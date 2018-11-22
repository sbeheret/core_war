/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:27:47 by rfibigr           #+#    #+#             */
/*   Updated: 2017/11/25 16:43:21 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i_dst;
	size_t	i_src;
	size_t	j;

	i_src = 0;
	i_dst = 0;
	j = 0;
	while (dest[i_dst])
		i_dst++;
	while (src[i_src])
		i_src++;
	if (i_dst > n)
		return (i_src + n);
	while (src[j] && i_dst + j < n - 1)
	{
		dest[i_dst + j] = src[j];
		j++;
	}
	dest[i_dst + j] = '\0';
	return (i_dst + i_src);
}
