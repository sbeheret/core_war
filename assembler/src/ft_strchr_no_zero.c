/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_no_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:59:00 by dshults           #+#    #+#             */
/*   Updated: 2018/10/28 18:00:24 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	locate character in string
**
**	locates the first occurrence of c (converted to a char)
**	in the string pointed to by s without '\0'.
*/

char	*ft_strchr_no_zero(const char *s, int c)
{
	int i;

	i = 0;
	if (!c)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
