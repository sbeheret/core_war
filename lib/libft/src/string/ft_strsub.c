/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:33:39 by rfibigr           #+#    #+#             */
/*   Updated: 2017/11/25 11:34:53 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*sn;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(sn = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		sn[i] = s[start + i];
		i++;
	}
	sn[i] = '\0';
	return (sn);
}
