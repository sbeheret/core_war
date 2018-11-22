/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:03 by esouza            #+#    #+#             */
/*   Updated: 2018/11/20 13:17:14 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

#define RIGHTS 06666

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "libft.h"
#include "op.h"

#define YES printf("yes\n");

/*
**	args[0] is op_code
**	the rest is it's arguments
*/

typedef struct			s_labels
{
	char				*name;
	int					op_nb;
	char 				**args;
    int				    position;
    int                 args_start_line;
	int					bytes;
	struct s_labels		*next;
}						t_labels;

typedef struct			s_data
{
	char				**tab;
    t_labels			*first_label;
	t_labels			*last_label;
	t_op				*op;
}						t_data;


int			main(int argc, char **argv);
void			set_header(t_header *header);
unsigned int		hexatoi(const char *ptr);
char			*strjoinappend(char *s1, char *s2);
void			get_data(int fd);

void		get_labels(t_data *d);
void		free_labels(t_data *d);
void        show_labels(t_labels *l);
void    	add_bytes(t_data *d);

t_op		*get_op_tab(void);
int			find_op_nb(char *s);

#endif
