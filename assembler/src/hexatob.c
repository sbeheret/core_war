/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexatob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:36:00 by esouza            #+#    #+#             */
/*   Updated: 2018/12/05 13:56:19 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned int hexatob(const char *ptr)
{
	unsigned int value;
	char ch;

	ch = *ptr;
	value = 0;

	while (ch == ' ' || ch == '\t')
		ch = *(++ptr);
	while (*ptr)
	{
		if (ch >= '0' && ch <= '9')
			value = (value << 4) + (ch - '0');
		else if (ch >= 'A' && ch <= 'F')
			value = (value << 4) + (ch - 'A' + 10);
		else if (ch >= 'a' && ch <= 'f')
			value = (value << 4) + (ch - 'a' + 10);
		else
			return value;
		ch = *(++ptr);
	}
	return (value);
}
