/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:03 by esouza            #+#    #+#             */
/*   Updated: 2018/11/23 15:33:12 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define RIGHTS 06666

# define LIVE 1
# define LD 2
# define ST 3
# define ADD 4
# define SUB 5
# define AND 6
# define OR 7
# define XOR 8
# define ZJMP 9
# define LDI 10
# define STI 11
# define FORK 12
# define LLD 13
# define LLDI 14
# define LFORK 15
# define AFF 16

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"
# include "op.h"

# define YES printf("yes\n"); //tmp

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
void 		trim_spaces_commas_comments(char **tab);
void        show_labels(t_labels *l);

void    	add_bytes(t_data *d);
t_op		*get_op_tab(void);
int			find_op_nb(char *s);

int    calc_bytes_till_label(t_labels *first_label, t_labels *current_l, int a);

#endif
