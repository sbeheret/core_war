/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:03 by esouza            #+#    #+#             */
/*   Updated: 2018/12/18 09:26:57 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define RIGHTS 06666
# define FILE_NAME_LENGTH 255

/*
**	output highlighting defines
*/

# define SET "\e[7m"
# define RESET "\e[0m"
# define S "\e[7m%s\e[0m"
# define C "\e[7m%c\e[0m"
# define I "\e[7m%i\e[0m"

# define ZERO 0
# define ONE 1
# define TWO 2

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef struct			s_op
{
	char				name[5];
	int					params_nb;
	char				params_types[3];
	int					id;
	int					cycles;
	char				description[50];
	int					encoded_byte;
	int					dir_as_ind;
}						t_op;

typedef struct			s_labels
{
	char				*name;
	char				*op_code;
	int					op_nb;
	char				**args;
	int					position;
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
	char				*file;
	size_t				total_bytes;
}						t_data;

typedef struct			s_var
{
	int					i;
	int					j;
	int					quotes;
}						t_var;

int						main(int argc, char **argv);
int						set_header(char **tab, t_header *header);
unsigned int			hexatoi(const char *ptr);
char					*strjoinappend(char *s1, char *s2);
int						ft_strmcmp(char *s1, char *s2, size_t len);
void					get_data(char **argv, int fd, int fd2);
int32_t					swap_uint32(uint32_t val);
int						binary_char_to_int(char *s);
void					int_to_octet(int fd2, int value);
void					short_to_octet(int fd2, int value);
void					err_dots(int idx, int err, char **tab, t_header *h);
int						check_end(char **tab, int col, int row);
int						create_file_body(t_data *d, int fd2);
int						get_octet_codage(t_labels *head, int fd2);
int						arg_len(t_labels *head);
int						first_arg(t_data *d, t_labels *head, int fd2, int arnb);
int						second_arg(t_data *d, t_labels *head, int fd2,
		int arnb);
int						third_arg(t_data *d, t_labels *head, int fd2, int arnb);
int						write_register(t_labels *head, int idx, int fd2);
int						write_direct_four(t_data *d, t_labels *head,
		int idx, int fd2);
int						write_two_octet(t_data *d, t_labels *head, int idx,
		int fd2);
int						name_comment_length(t_data *d, char *data,
		t_header *header, int fd);
char					*ft_str_trim(char const *s);
long long				long_atoi(const char *str);
unsigned long			unsigned_long_atoi(const char *str);

/*
**	FREE
*/

void					free_trim(char *line, char *trim);
void					free_data(t_data *d, char *data, t_header *header);

/*
**	LABELS
*/

int						get_labels(t_data *d);
t_labels				*make_label(char **line, int len, int p);
void					add_to_label_list_end(t_data *d, t_labels *label);

int						find_op_code(t_labels *l, char *s, t_op *op);
int						op_l(t_labels *lb, char *str, int i, t_op *op);

int						check_commas(char *s);
int						general_check(t_data *d);
int						compliance_check(t_data *d, t_labels *l);
void					add_bytes(t_data *d, t_labels *l, int a);

int						bytes_till_label(t_labels *first_label,
		t_labels *current, int arg);

/*
**	ERRORS
*/

int						error_op_code(char *s);
int						error_args(char *s);
int						error_arg_type(char *s, char *op_code);
int						error_label(char *s);
int						error_param_nb(char *op_code, int expected, int got);

/*
**	EXTRAS
*/

char					*ft_strchr_no_zero(const char *s, int c);
char					*ft_strndup(const char *s, size_t n);
char					*str_trim(char const *s);
void					trim_spaces(char **tab);

#endif
