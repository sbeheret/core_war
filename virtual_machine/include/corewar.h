/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:34:22 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 18:22:55 by rfibigr          ###   ########.fr       */
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
# include <ncurses.h>

/*
** -----------------------------------------------------------------------------
** ---------------------------------- DEFINE -----------------------------------
** -----------------------------------------------------------------------------
*/
# define BEGIN_BINARY (4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)
# define REG 1
# define DIR 2
# define IND 3
# define ARG1 0
# define ARG2 1
# define ARG3 2

/*
** -----------------------------------------------------------------------------
** -------------------------------- TYPE_DEF------------------------------------
** -----------------------------------------------------------------------------
*/
typedef struct			s_champion
{
	char				*name;
	int					display_name;
	char				*comment;
	char				*file;
	unsigned int		p_number;
	size_t				weight;
	unsigned char		*binary;
	size_t				binary_len;
	int					start;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_action
{
	int					pc;
	int					op_code;
	int					args[4];
	int					nb_arg;
	int					type[4];
	int					size_read;
}						t_action;

typedef struct			s_processus
{
	int					processus_number;
	int					pc;
	int					last_pc;
	int					color;
	int					carry;
	int					*reg;
	int					cycles_wait;
	int					lives;
	int					flag_execute;
	t_action			action;
	struct s_processus	*next;
}						t_processus;

typedef	struct			s_vm
{
	int					nb_champs;
	unsigned int		last_alive;
	unsigned int		sleep;
	int					ctd;
	int					cycles_ttx;
	int					cycles_now;
	unsigned char		*ram;
	t_champion			*champion;
	t_processus			*processus;
	int					flag_dump;
	int					dump_cycle;
	int					visu;
	int					verbose;
	int					flag_live;
	int					flag_hex;
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
	int					direct_octet;
}						t_op;

typedef	void			(*t_instruction)(t_vm *, t_processus *);
/*
** -----------------------------------------------------------------------------
** ---------------------------- FONCTION PROTOTYPE -----------------------------
** -----------------------------------------------------------------------------
*/

/*
** --------- LOAD_IN_RAM
*/
void					load_champs(t_vm *vm);

/*
** --------- PROCESSUS
*/
void					make_list_process(t_champion **ch, t_processus **pcs);
void					push_front_pcs(t_processus **pcs, t_processus *nw);

/*
** --------- WHERE_START
*/
void					start_champions(t_champion **champ, int nb_champs);
void					give_start(t_champion *champ, int nb_champs);

/*
** --------- CHECK_PARAMETER
*/
void					check_parameters(int argc, char **argv, t_vm *vm);
void					create_champion(char ***argv, t_champion **champion);
void					create_process(t_champion **champ, t_processus **pcs);
void					ft_assign_pnumber(char ***argv, t_champion **champion,
		t_champion **new_elem);
unsigned char			*ft_read_champion(char *file, size_t *binary_len);
void					check_binary(t_champion *champion);
void					check_padding(unsigned char **binary, char *file);
int						check_number(unsigned int	num, t_champion *champion);
void					ft_option(char ***argv, t_vm *vm);
void					check_multi_flag(t_vm *vm);

/*
** --------- INITIALIZATION
*/
void					initialize_vm(t_vm *vm);
void					initialize_processus(t_processus **pcs, int nb,
		int start, int color);
void					initialize_champion(t_champion **champion);
void					initialize_action(t_processus *processus);

/*
** --------- LIBS
*/
t_champion				*new_champion(void);
t_processus				*new_processus(int p_number, int start, int color);
void					ft_push_back_chmp(t_champion **bg, t_champion *to_add);
void					push_front_pcs(t_processus **pcs, t_processus *nw);
int						ft_atoi_exit(char *s, char *parameter, char *file);

/*
** --------- RUN VM
*/
void					run_vm(t_vm *vm);
void					run_instruction(t_vm *vm, t_processus *processus,
		int op_code);
int						kill_processus(t_vm *vm);
void					delete_element(t_processus **previous,
		t_processus **tmp, t_vm *vm);
void					declare_winner(t_vm *vm);
void					execute_instruction(t_vm *vm);
void					get_instruction(t_vm *vm);
void					execute_cycle(t_vm *vm);

/*
** --------- GET_ACTION
*/
void					get_op_code(t_vm *vm, t_processus *pcs);
void					get_action(t_vm *vm, t_processus *pcs);
void					args_action(unsigned char *ram, int pc, t_action *n);
void					trad_encoding_byte(t_action *n, int enc_byte, int val);
int						get_content_value(unsigned char *m, t_processus *p,
						int type, int address);
int						get_long_content_value(unsigned char *m,
		t_processus *p, int type, int address);
/*
** --------- CONVERT
*/
void					ft_int_to_octet(unsigned char *b, int value, int id);
int						ft_octet_to_int(unsigned char **binary, int nb_octect);
int						ft_octet_to_int2(unsigned char *binary, int nb_octect,
		int index);
char					*ft_octet_to_char(unsigned char **binary,
		size_t lenght_max);
int						circular(int i);

/*
** --------- INSTRUCTION
*/
void					ft_live(t_vm *vm, t_processus *processus);
void					ft_ld(t_vm *vm, t_processus *processus);
void					ft_st(t_vm *vm, t_processus *processus);
void					ft_add(t_vm *vm, t_processus *processus);
void					ft_sub(t_vm *vm, t_processus *processus);
void					ft_and(t_vm *vm, t_processus *processus);
void					ft_or(t_vm *vm, t_processus *processus);
void					ft_xor(t_vm *vm, t_processus *processus);
void					ft_zjump(t_vm *vm, t_processus *processus);
void					ft_ldi(t_vm *vm, t_processus *processus);
void					ft_sti(t_vm *vm, t_processus *processus);
void					ft_fork(t_vm *vm, t_processus *processus);
void					ft_lld(t_vm *vm, t_processus *processus);
void					ft_lldi(t_vm *vm, t_processus *processus);
void					ft_lfork(t_vm *vm, t_processus *processus);
void					ft_aff(t_vm *vm, t_processus *processus);

/*
** --------- CHECK INSTRUCTION ARG
*/
int						instruction_check(t_processus *processus);
int						ft_get_ind(t_vm *vm, t_processus *processus, int arg);
int						ft_get_lind(t_vm *vm, t_processus *processus, int arg);

/*
** --------- PRINT FUNCTION / MEMORY
*/
void					introduce_contestant(t_champion *champion, int fl_hx);
void					print_ram(unsigned char *ram);
void					print_memory(unsigned char *str, size_t size);
void					print_processus(t_processus *pcs);
void					print_action(t_action action);

/*
** ---------PRINT INSTRUCTION
*/
void					ft_print_live(int processus, unsigned int champion);
void					ft_print_ld(t_processus *processus, int arg1,
		int arg2);
void					ft_print_st(t_processus *processus, int arg1,
		int arg2);
void					ft_print_add(t_processus *processus, int arg1,
		int arg2, int arg3);
void					ft_print_sub(t_processus *processus,
		int arg1, int arg2, int arg3);
void					ft_print_and(t_processus *processus, int arg1,
		int arg2, int arg3);
void					ft_print_or(t_processus *processus, int arg1,
		int arg2, int arg3);
void					ft_print_xor(t_processus *processus, int arg1,
		int arg2, int arg3);
void					ft_print_zjump(t_processus *processus, int jump);
void					ft_print_ldi(t_processus *processus, int arg1,
		int arg2, int arg3);
void					ft_print_sti(t_processus *processus, int arg1,
		int arg2, int arg3);
void					ft_print_fork(t_processus *processus, int arg);
void					ft_print_lld(t_processus *processus, int arg1,
		int arg2);
void					ft_print_lldi(t_processus *processus, int arg1,
		int arg2, int arg3);
void					ft_print_lfork(t_processus *processus, int arg);

/*
** --------- EXIT
*/
void					ft_exit_malloc(void);
void					ft_exit_nofile(char *file);
void					ft_exit_toosmall(char *file);
void					ft_exit_toobig(char *file);
void					ft_exit_usage(void);
void					ft_exit_toomanychamp(void);
void					ft_exit_magicnumber(char *file);
void					ft_exit_header(char *file);
void					ft_exit_parameter(char *argument, char *file);
void					ft_exit_playernumber(char *file);
void					ft_exit_dump(t_vm *vm);
void					ft_exit_visu(t_vm *vm);
void					ft_exit_nochamp(char *file);

/*
** --------- FREE
*/
void					ft_free_vm(t_vm *vm);
void					ft_free_champion(t_champion **champion);
void					ft_free_processus(t_processus **processus);

/*
** --------- NCURSES
*/

void					init_ncurses(void);
void					print_ram_curses(t_vm *vm);
void					print_ram_nocolor(unsigned char *ram, int i);
int						print_ram_color(unsigned char *ram, int i, int c,
		int size);
void					update_pc_visu(unsigned char *ram, t_processus *pcs);
void					update_lives(unsigned int nb, t_vm *vm,
		t_champion *chmps);
void					update_cycles(t_vm *vm, int a);
void					write_in_ram(unsigned char *ram, t_processus *pcs,
		int id);
void					init_data_visu(t_vm *vm);
void					ncurses_input(t_vm *vm);
void					remove_dead_pcs(unsigned char *ram, t_processus *pcs);
void					winner_ncurses(char *name, int nb, int i);

#endif
