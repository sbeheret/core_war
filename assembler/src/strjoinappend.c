/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoinappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:08:42 by esouza            #+#    #+#             */
/*   Updated: 2018/12/13 15:20:04 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*ft_getresult(char *s1, char *s2, char *array)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		array[i] = s2[k];
		i++;
		k++;
	}
	array[i++] = '\n';
	array[i] = '\0';
	free(s1);
	return (array);
}

void		trim_backwards(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != COMMENT_CHAR && s[i] != ';')
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\t'))
		i--;
	s[i + 1] = '\0';
}

char		*strjoinappend(char *s1, char *s2)
{
	int		len;
	char	*array;

	if (s1 && s2)
	{
		if (ft_strchr(s2, COMMENT_CHAR) || ft_strchr(s2, ';'))
			trim_backwards(s2);
		len = ((ft_strlen((char *)s1)) + (ft_strlen((char *)s2)) + 2);
		if (!(array = (char *)malloc(sizeof(*array) * len)))
			return (NULL);
		return (ft_getresult(s1, s2, array));
	}
	return (NULL);
}
