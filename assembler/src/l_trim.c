/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_trim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:43:05 by dshults           #+#    #+#             */
/*   Updated: 2018/12/02 17:59:30 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void    skip_spaces(char const *s, int *i)
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
		else if (s[i] == LABEL_CHAR || s[i] == DIRECT_CHAR ||
			ft_strchr_no_zero(LABEL_CHARS, s[i]))
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
				ft_printf("\033[31mLine [%s] has a bad placement of ", s);
				ft_printf("separator char [%c]\033[0;m\n", SEPARATOR_CHAR);
				return (0);
			}
		}
		else
			i++;
	}
	return (1);
}

void		trim_spaces(char **tab)
{
	int		y;
	char	*tmp;

	y = 0;
	while (tab[y])
	{
		tmp = tab[y];
		tab[y] = ft_strtrim(tab[y]);
		free(tmp);
        tmp = NULL;
		y++;
	}
}
