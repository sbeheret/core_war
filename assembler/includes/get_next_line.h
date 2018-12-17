/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:12:43 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/15 10:44:45 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

# define BUFF_SIZE 4096

typedef struct	s_struct
{
	char		str[BUFF_SIZE + 1];
	int			len;
}				t_struct;

int				get_next_line(const int fd, char **line);
int				ft_strcut(char **line, int linelen, char *str, int *strlen);
int				ft_read_to_space(int fd, char **buff);
char			*ft_memcat(char *buff, size_t bufflen, char *sread, size_t rd);

#endif
