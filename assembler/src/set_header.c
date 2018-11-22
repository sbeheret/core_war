/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:31:29 by esouza            #+#    #+#             */
/*   Updated: 2018/11/22 14:33:24 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

void			set_header(t_header *header)
{
	int	i;

	i = 0;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(header->comment, COMMENT_LENGTH + 1);
	header->magic = COREWAR_EXEC_MAGIC;
	while ( i < PROG_NAME_LENGTH)
		header->prog_name[i++] = 'A';
	i = 0;
	while ( i < COMMENT_LENGTH)
		header->comment[i++] = 'B';
//	printf("%s\n", header->prog_name);
}
