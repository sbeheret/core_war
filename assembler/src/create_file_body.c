/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:49:39 by esouza            #+#    #+#             */
/*   Updated: 2018/12/14 15:16:08 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_iswhitespace(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0);
}

char		*ft_str_trim(char const *s)
{
	size_t	n;

	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	n = ft_strlen(s);
	while (n > 0 && ft_iswhitespace(s[n - 1]))
		n--;
	return (ft_strsub(s, 0, n));
}

int						ft_strmcmp(char *s1, char *s2, size_t len)
{
	while (--len && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int						create_file_body(t_data *d, int fd2)
{
	t_labels		*head;
	int				arnb;

	head = d->first_label;
	while (head)
	{
		arnb = arg_len(head);
		if (head->op_code != NULL)
		{
			ft_putchar_fd((unsigned char)head->op_nb, fd2);
			if (d->op[head->op_nb - 1].encoded_byte)
				get_octet_codage(head, fd2);
			first_arg(d, head, fd2, arnb);
			second_arg(d, head, fd2, arnb);
			third_arg(d, head, fd2, arnb);
		}
		head = head->next;
	}
	return (fd2);
}
