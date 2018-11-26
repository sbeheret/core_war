/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:12:42 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/26 10:57:25 by sbeheret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* CHECK_PARAMETER
** Verifier les parametres du programme
** Creer les champions avec les parametres
**		- Nom
**		- Commentaires
**		- Programme binaire
**		- Numero du joueur
*/

void	check_parameters(int argc, char **argv, t_vm *vm)
{
//	./corewar [-dump nbr_cycles] [[-n number] champion1.cor]
	if (argc < 2)
		ft_exit_usage();
	ft_read_argument(argv, vm);
	print_struct_vm(*vm);
	// 	ft_exit_toomanychamp();
}

/*
** FONCTION READ_ARGUMENT
** Lire les arguments
** Sauvegarder les parametre -dump
** Creer pour chaque champion la structure processus avec :
** 		le nom du fichier
** 		le numero du joueur
*/

void	ft_read_argument(char **argv, t_vm *vm)
{
	// voir importance du parseur
	// ou fonctionnement similaire au corewar zaz
	argv += 1;
	while (*argv)
	{
		ft_printf("start while *argv = %s\n", *argv);
		if (!(ft_strcmp(*argv, "-dump")))
		{
			ft_printf("-dump *argv = %s\n", *argv);
			argv += 1;
			(*vm).flag_dump = 1;
			if (!(*argv))
				ft_exit_usage();
			// Voir si besoin de plus de verification
			(*vm).dump_cycle = ft_atoi(*argv);
			argv += 1;
		}
		ft_printf("before create champ *argv = %s\n", *argv);
		create_champion(&argv, (*vm).champion);
		(*vm).nb_champion++;
		ft_printf("after create champ *argv = %s\n", *argv);
	}
}

/*
** FONCTION CREATE_CHAMPION
** Creer le fichier binaire
** Lire le fichier binaire du champion et verifier que le fichier est valide
**		- Bon header
**		- Bonne size
** Si fichier valide, ecire les informations Name / Commentaires
*/

void	create_champion(char ***argv, t_champion *champion)
{
	t_champion	*new_elem;

	new_elem = new_champion();
	if (!(ft_strcmp(**argv, "-n")))
	{
		ft_printf("- N **argv = %s\n", *argv);
		*argv += 1;
		if (!(**argv))
			ft_exit_usage();
		new_elem->p_number = ft_atoi(**argv);
		argv += 1;
	}
	ft_printf("**argv = %s\n", **argv);
	if (!(**argv))
		ft_exit_usage();
	new_elem->file = **argv;
	*argv += 1;
	new_elem->binary = ft_read_champion(new_elem->file, &new_elem->binary_len);
	check_binary(new_elem);
 	ft_push_back_chmp(&champion, new_elem);
}

unsigned char	*ft_read_champion(char *file, size_t *binary_len)
{
	int				fd;
	int				rd;
	int				i;
	unsigned char	*binary;

	if (!(binary = (unsigned char *)malloc(BUFF_SIZE)))
		ft_exit_malloc();
	if (((fd = open(file, O_RDONLY)) == -1))
		ft_exit_nofile(file);
	i = 0;
	while ((rd = read(fd, binary, BUFF_SIZE)) > 0)
	{
		if (rd == -1)
			ft_exit_nofile(file);
		*binary_len += rd;
		if (!(binary = realloc(binary, *binary_len)))
			ft_exit_malloc();
	}
	return (binary);
}

void	check_binary(t_champion *champion)
{
	(void)processus;
	ft_printf("======= check_binary =========\n");
	// PROG_NAME_LENGTH			(128)
	// COMMENT_LENGTH			(2048)
	// COREWAR_EXEC_MAGIC		0xea83f3
	// CHAMP_MAX_SIZE			(MEM_SIZE / 6)
	// MEM_SIZE					(4 * 1024)

	//4		compare COREWAR_EXEC_MAGIC
	//128	save name for the next PROG_NAME_LENGTH octet
	//4		verify octect padding
	//4		save programm length
	//2048	save comment for the next COMMENT_LENGTH
	//4		verify 4 octect padding
	//662		verify programm length is true


	// if (*binary_len < 2092)
	// 	ft_exit_toosmall(file);
}
	//Error: File Untitled.cor has an invalid header
