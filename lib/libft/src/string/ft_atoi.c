/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:33:53 by rfibigr           #+#    #+#             */
/*   Updated: 2017/11/25 17:10:24 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_calcul(const char *s, int i, int neg)
{
	int nbr;
	int counter;

	counter = 0;
	nbr = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + s[i] - '0';
		if (counter > 11 && neg == 1 && (s[i - counter] != '0'))
			return (0);
		if (counter > 11 && neg == 0 && (s[i - counter] != '0'))
			return (-1);
		counter++;
		i++;
	}
	return (nbr);
}

int				ft_atoi(const char *s)
{
	int i;
	int	nbr;
	int neg;

	i = 0;
	neg = 0;
	nbr = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
			s[i] == '\r' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i - 1] == '-')
		neg = 1;
	if (s[i] >= '0' && s[i] <= '9')
		nbr = ft_calcul(s, i, neg);
	if (neg == 1)
		nbr = -nbr;
	return (nbr);
}
