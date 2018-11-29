/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:03 by esouza            #+#    #+#             */
/*   Updated: 2018/11/28 17:38:12 by esouza           ###   ########.fr       */
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

int							main(int argc, char **argv);
int							set_header(int fd2, char **tab);
unsigned int				hexatoi(const char *ptr);
char						*strjoinappend(char *s1, char *s2);
int							get_data(int fd, int fd2);
int32_t						swap_uint32(uint32_t val);
void						err_dots(int idx, int err, char **tab, t_header *h);


#endif
