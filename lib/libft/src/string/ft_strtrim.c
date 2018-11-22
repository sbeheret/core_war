/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:14:19 by rfibigr           #+#    #+#             */
/*   Updated: 2017/11/25 17:56:21 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_before(char const *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == ',' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	return (i);
}

static int		ft_count_after(char const *s)
{
	int i;
	int len;

	len = ft_strlen(s);
	i = len - 1;
	while ((s[i] == ' ' || s[i] == ',' || s[i] == '\t' ||
				s[i] == '\n') && i >= 0)
		i--;
	return (len - 1 - i);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	i_before;
	size_t	i_after;
	char	*str;

	if (!s)
		return (NULL);
	i_after = ft_count_after(s);
	i_before = ft_count_before(s);
	i = i_before;
	if (i_before == ft_strlen(s))
	{
		str = ft_strnew(0);
		return (str);
	}
	len = ft_strlen(s) - i_after - i_before;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (s[i] && (i < (ft_strlen(s) - i_after)))
	{
		str[i - i_before] = s[i];
		i++;
	}
	return (str);
}
