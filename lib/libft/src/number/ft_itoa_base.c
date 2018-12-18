/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:59:46 by sbeheret          #+#    #+#             */
/*   Updated: 2018/12/16 17:33:48 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_nb(char *base, int *b)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	*b = i;
	if (i == 10)
		return (20);
	else if (i == 8)
		return (22);
	else if (i == 16)
		return (17);
	else if (i == 2)
		return (64);
	return (29);
}

static int		ft_absolute(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char			*ft_itoa_base(long long int nb, char *base)
{
	int		len;
	int		b;
	char	*str;
	int		mod;
	int		i;

	len = len_nb(base, &b);
	i = len - 1;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	ft_bzero(str, len + 1);
	if (nb == 0)
		str[i--] = '0';
	while (nb != 0)
	{
		mod = nb % b;
		nb = nb / b;
		str[i] = base[ft_absolute(mod)];
		i--;
	}
	i++;
	b = ft_strlen(&str[i]);
	ft_memmove(str, &str[i], b);
	ft_bzero(&str[b], len - b);
	return (str);
}
