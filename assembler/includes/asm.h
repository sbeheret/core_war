/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:03 by esouza            #+#    #+#             */
/*   Updated: 2018/12/05 13:54:03 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

#define RIGHTS 06666
#define FILE_NAME_LENGTH 255

/*
** dshults defines
*/

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

# define YES printf("YES\n"); //tmp

/*
 * ****************************************************************************
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "libft.h"
#include "op.h"

/*
 *******************************************************************************
 */

typedef struct	s_op
{
	char		name[5];
	int			params_nb;
	char		params_types[3];
	int			id;
	int			cycles;
	char		description[50];
	int			encoded_byte;
	int			dir_as_ind;
}				t_op;

typedef struct			s_labels
{
	char				*name;
	char				*op_code;
	int					op_nb;
	char 				**args;
	int				    position;
	int					bytes;
	struct s_labels		*next;
}						t_labels;

typedef struct			s_data
{
	char				**tab;
	int					y;
	t_labels			*first_label;
	t_labels			*last_label;
	t_op				*op;
	size_t				total_bytes;
}						t_data;

typedef struct			s_var
{
	int					i;
	int					j;
	int					quotes;
}						t_var;

/*
 *******************************************************************************
 */

int							main(int argc, char **argv);
int							set_header(char **tab, t_header *header);
unsigned int				hexatoi(const char *ptr);
char						*strjoinappend(char *s1, char *s2);
void						get_data(char **argv, int fd, int fd2);
int32_t						swap_uint32(uint32_t val);
void						err_dots(int idx, int err, char **tab, t_header *h);
int							check_end(char **tab, int col, int row);
int							create_file_body(t_data *d, int fd2);
int							get_opcode(t_labels *head, int fd2);
int							get_octet_codage(t_labels *head, int fd2);
int							binary_char_to_int(char *s);

/*
 *******************************************************************************
 */

/*
**	FREE
*/

void			free_trim(char *line, char *trim);
void			free_data(t_data *d, char *data, t_header *header);

/*
**	LABELS
*/
void 		trim_spaces(char **tab);
int			check_commas(char *s);

int			get_labels(t_data *d);
void    	check_label(char *s);
int	    	general_check(t_data *d);
int	    	compliance_check(t_data *d);
void 	  	add_bytes(t_data *d);

t_op		*get_op_tab(void);
int			find_op_nb(char *s);
int    		find_op_code(t_labels *l, char *s, t_op *op);

int    		bytes_till_label(t_labels *first_label, t_labels *current, int arg);

/*
**	ERRORS
*/

int    	error_char(char c);
int   	error_op_code(char *s);
int    	error_args(char *s);
int    	error_arg_type(char *s, char *op_code);
int    	error_label(char *s);
int    	error_param_nb(char *op_code, int expected, int got);

/*
**	EXTRAS
*/

void		print_tab(t_data *d, int i);
void        show_labels(t_data *d);
char		*ft_strchr_no_zero(const char *s, int c);
char		*ft_strndup(const char *s, size_t n);
char		*str_trim(char const *s);

#endif
