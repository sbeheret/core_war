/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:03 by esouza            #+#    #+#             */
/*   Updated: 2018/11/22 12:38:38 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

#define RIGHTS 06666
#define FILE_NAME_LENGTH 255

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "../../lib/libft/include/libft.h"
#include "op.h"

int			main(int argc, char **argv);
void			set_header(t_header *header);
unsigned int		hexatoi(const char *ptr);
char			*strjoinappend(char *s1, char *s2);
void			get_data(int fd);

#endif
