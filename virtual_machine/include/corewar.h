/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:34:22 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/23 13:36:06 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

/*
** -----------------------------------------------------------------------------
** ---------------------------------- DEFINE -----------------------------------
** -----------------------------------------------------------------------------
*/



/*
** -----------------------------------------------------------------------------
** --------------------------------- INCLUDE -----------------------------------
** -----------------------------------------------------------------------------
*/
# include "libft.h"
# include "op.h"

/*
** -----------------------------------------------------------------------------
** -------------------------------- TYPE_DEF------------------------------------
** -----------------------------------------------------------------------------
*/
typedef	struct			s_processus
{
	char				*name;
	char				*comment;
	char				*file;
	int					p_number;
	int					weight;
	unsigned char 		*binary;
	size_t				binary_len;
	unsigned char		*adress_start;
	struct	s_processus *next;
}						t_processus;

typedef	struct		s_vm
{
	int				flag_dump;
	int				dump_cycle;
	unsigned char	*ram;
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
** --------- CHECK_PARAMETER
*/
void				check_parameters(int argc, char **argv, t_vm *vm);
void				ft_read_argument(char **argv, t_vm *vm);
void				create_champion(char ***argv, t_processus *processus);
unsigned char		*ft_read_champion(char *file, size_t *binary_len);
void				check_binary(t_processus *processus);

/*
** --------- INITIALIZATION
*/
void				initialize_vm(int argc, char **argv, t_vm *vm);
void				initialize_processus(t_processus **processus);

/*
** --------- TOOLS
*/
t_processus			*create_processus(void);
void				ft_push_back(t_processus **begin, t_processus *to_add);

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
