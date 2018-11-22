/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:03:59 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/23 13:46:25 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	int		len_s1;
	int		i;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len = (len_s1 + ft_strlen(s2));
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = 0;
		while (i < len)
		{
			if (i < len_s1)
				str[i] = s1[i];
			else
				str[i] = s2[i - len_s1];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
