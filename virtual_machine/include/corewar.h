/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:34:22 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/27 19:21:38 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

/*
** -----------------------------------------------------------------------------
** --------------------------------- INCLUDE -----------------------------------
** -----------------------------------------------------------------------------
*/
# include "libft.h"
# include "op.h"

/*
** -----------------------------------------------------------------------------
** ---------------------------------- DEFINE -----------------------------------
** -----------------------------------------------------------------------------
*/

# define BEGIN_BINARY (4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)

/*
** -----------------------------------------------------------------------------
** -------------------------------- TYPE_DEF------------------------------------
** -----------------------------------------------------------------------------
*/
typedef	struct			s_champion
{
	char				*name;
	char				*comment;
	char				*file;
//		Avons nous besoin du commentaire ?
	unsigned int		p_number;
	size_t				weight;
	unsigned char 		*binary;
	size_t				binary_len;
	int					start;
	struct	s_champion *next;
}						t_champion;

typedef struct			s_processus
{
	int					PC;
	int					*reg;
	int					cycles_wait;
	int					lives;
	struct s_processus	*next;
}						t_processus;

typedef	struct			s_vm
{
	int					nb_champs;
	int					flag_dump;
	int					dump_cycle;
	int					last_alive;
	int					CTD;
	int					cycles_ttx;
	int					cycles_now;
	unsigned char		*ram;
	t_champion			*champion;
	t_processus			*processus;
}						t_vm;

typedef	struct			s_op
{
	char				*name;
	int					param_number;
	int					param_type[3];
	int					op_code;
	int					cycle;
	char				*comment;
	int					encoding_byte;
	int					direct_octect;
}						t_op;


/*
** -----------------------------------------------------------------------------
** ---------------------------- FONCTION PROTOTYPE -----------------------------
** -----------------------------------------------------------------------------
*/

/*
** --------- COREWAR
*/

/*
** --------- LOAD_IN_RAM
*/
void				load_champs(t_vm *vm);

/*
** --------- PROCESSUS
*/
void				make_list_process(t_champion **cham, t_processus **pcs);
void				push_front_pcs(t_processus **pcs, t_processus *nw);
t_processus			*new_processus(int p_nb, int start);


/*
** --------- WHERE_START
*/
void				start_champions(t_champion **champ, int nb_champs);
int					give_start(t_champion *champ, int nb_champs);

/*
** --------- CHECK_PARAMETER
*/
void				check_parameters(int argc, char **argv, t_vm *vm);
void				create_champion(char ***argv, t_champion **champion);
void				ft_assign_pnumber(char ***argv, t_champion **champion, t_champion **new_elem);
unsigned char		*ft_read_champion(char *file, size_t *binary_len);
void				check_binary(t_champion *champion);
void				check_padding(unsigned char **binary, char *file);
int					check_number(unsigned int	number, t_champion *champion);

/*
** --------- INITIALIZATION
*/
void				initialize_vm(t_vm *vm);
void				initialize_processus(t_processus **pcs, int nb, int start);
void				initialize_champion(t_champion **champion);

/*
** --------- TOOLS
*/
t_champion			*new_champion(void);
void				ft_push_back_chmp(t_champion **begin, t_champion *to_add);
int					ft_atoi_exit(char *s, char *parameter, char *file);

/*
** --------- TOOLS
*/
void				print_ram(unsigned char *ram);
void				print_memory(unsigned char *str, size_t size);
void				print_struct_vm(t_vm vm);

/*
** --------- CONVERT
*/
int					ft_octet_to_int(unsigned char **c);
char				*ft_octet_to_char(unsigned char **binary, size_t lenght_max);

/*
** --------- EXIT
*/
void				ft_exit_malloc(void);
void				ft_exit_nofile(char *file);
void				ft_exit_toosmall(char *file);
void				ft_exit_toobig(char *file);
void				ft_exit_usage(void);
void				ft_exit_toomanychamp(void);
void				ft_exit_magicnumber(char *file);
void				ft_exit_header(char *file);
void				ft_exit_parameter(char *argument, char *file);
void				ft_exit_playernumber(char *file);

/*
** --------- FREE
*/
void				ft_free_vm(t_vm *vm);
void				ft_free_champion(t_champion **champion);
void				ft_free_processus(t_processus **processus);

#endif
