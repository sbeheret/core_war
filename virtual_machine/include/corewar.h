/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:34:22 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/26 17:01:25 by sbeheret         ###   ########.fr       */
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

# define BEGIN_BINARY (4 + PROG_NAME_LENGTH + 4 + COMMENT_LENGTH + 4)

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
	int					p_number;
	int					weight;
	unsigned char 		*binary;
	size_t				binary_len;
	int					start;
	struct	s_champion *next;
}						t_champion;

typedef struct			s_processus
{
	int			PC;
	int			*reg;
	int			cycles_wait;
	int			lives;
	struct s_processus	*next;
}				t_processus;

typedef	struct		s_vm
{
	int				nb_champs;
	int				flag_dump;
	int				dump_cycle;
	int				last_alive;
	int				CTD;
	int				cycles_ttx;
	int				cycles_now;
	unsigned char	*ram;
	t_champion		*champion;
	t_processus		*processus;
}					t_vm;

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
void				ft_read_argument(char **argv, t_vm *vm);
void				create_champion(char ***argv, t_champion *champion);
unsigned char		*ft_read_champion(char *file, size_t *binary_len);
void				check_binary(t_champion *champion);

/*
** --------- INITIALIZATION
*/
void				initialize_vm(int argc, char **argv, t_vm *vm);
void				initialize_processus(t_processus **pcs, int nb, int start);
void				initialize_champion(t_champion **champion);

/*
** --------- TOOLS
*/
t_champion			*new_chanpion(void);
void				ft_push_back_chmp(t_champion **begin, t_champion *to_add);

/*
** --------- TOOLS
*/
void				print_ram(unsigned char *ram);
void				print_memory(unsigned char *str, size_t size);
void				print_struct_vm(t_vm vm);

/*
** --------- EXIT
*/
void				ft_exit_malloc(void);
void				ft_exit_nofile(char *file);
void				ft_exit_toosmall(char *file);
void				ft_exit_usage(void);
void				ft_exit_toomanychamp(void);

#endif
