/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:59:42 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 17:05:40 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_space(char *s)
{
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v' ||
			*s == '\r' || *s == '\f')
		s = s + 1;
	return (s);
}

int		ft_isinteger(char *s)
{
	long long	nbr;
	int			neg;

	neg = 1;
	nbr = 0;
	s = skip_space(s);
	if (*s == '-')
		neg = -1;
	if (*s == '-' || *s == '+')
		s = s + 1;
	if (!(*s >= '0' && *s <= '9'))
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + *s - '0';
		if ((nbr > INT_MAX && neg == 1) || -nbr < -2147483648)
			return (0);
		s = s + 1;
	}
	s = skip_space(s);
	if (*s)
		return (0);
	return (1);
}
