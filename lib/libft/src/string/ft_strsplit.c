/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:48:17 by rfibigr           #+#    #+#             */
/*   Updated: 2017/11/25 16:04:17 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countword(char const *s, char c)
{
	int	i;
	int	mot;

	i = 0;
	mot = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			mot++;
	}
	return (mot);
}

static void		forward(const char *s, char c, int *i, int *j)
{
	while (s[*i] == c)
		*i = *i + 1;
	*j = 0;
	while (s[*i] != c && s[*i])
	{
		*j = *j + 1;
		*i = *i + 1;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	word = 0;
	if (!(str = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1))))
		return (NULL);
	while (s[i] && (word < ft_countword(s, c)))
	{
		forward(s, c, &i, &j);
		str[word] = ft_strnew(j + 1);
		i = i - j;
		j = 0;
		while (s[i] != c && s[i])
			str[word][j++] = s[i++];
		word++;
	}
	str[word] = NULL;
	return (str);
}
