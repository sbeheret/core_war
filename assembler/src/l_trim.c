/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_trim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:43:05 by dshults           #+#    #+#             */
/*   Updated: 2018/12/08 12:38:15 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		skip_spaces(char const *s, int *i)
{
	while (s[*i] == ' ' || s[*i] == '\t')
		(*i)++;
}

static int		find_args(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == SEPARATOR_CHAR)
			return (0);
		else if (s[i] == LABEL_CHAR || s[i] == DIRECT_CHAR
			|| ft_strchr_no_zero(LABEL_CHARS, s[i]))
			return (1);
		i++;
	}
	return (0);
}

int				check_commas(char *s)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	skip_spaces(s, &i);
	while (s[i])
	{
		if (s[i] == SEPARATOR_CHAR)
		{
			i++;
			if (!find_args(s, i))
			{
				ft_printf("Line "S" has a bad placement of ", s);
				ft_printf("separator char "C"\n", SEPARATOR_CHAR);
				return (0);
			}
		}
		else
			i++;
	}
	return (1);
}

void			trim_spaces(char **tab)
{
	int		y;
	char	*tmp;

	y = 0;
	while (tab[y])
	{
		tmp = tab[y];
		tab[y] = str_trim(tab[y]);
		free(tmp);
		tmp = NULL;
		y++;
	}
}

char			*str_trim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	len = (int)ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
