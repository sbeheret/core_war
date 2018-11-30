/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:03 by esouza            #+#    #+#             */
/*   Updated: 2018/11/30 12:30:56 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

#define RIGHTS 06666
#define FILE_NAME_LENGTH 255

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "libft.h"
#include "op.h"

typedef struct				s_label
{
	char					label[FILE_NAME_LENGTH];
	size_t					line_nb;
	size_t					bytes;
	struct s_label			*next;
}							t_label;

int							main(int argc, char **argv);
int							set_header(char **tab, t_header *header);
unsigned int				hexatoi(const char *ptr);
char						*strjoinappend(char *s1, char *s2);
int							get_data(char **argv, int fd, int fd2);
int32_t						swap_uint32(uint32_t val);
void						err_dots(int idx, int err, char **tab, t_header *h);
int							check_end(char **tab, int col, int row);
#endif
