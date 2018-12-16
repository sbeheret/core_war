/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:12:42 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/16 18:47:23 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** CHECK_PARAMETER
** Verifier les parametres du programme
** Creer les champions avec les parametres
**		- Nom
**		- Commentaires
**		- Programme binaire
**		- Numero du joueur
** Creer les processus avec PC et REG1
*/

void			check_parameters(int argc, char **argv, t_vm *vm)
{
	if (argc < 2)
		ft_exit_usage();
	argv += 1;
	while (*argv)
	{
		if (*argv[0] == '-' && ft_strcmp(*argv, "-n"))
			ft_option(&argv, vm);
		else
		{
			create_champion(&argv, &(*vm).champion);
			(*vm).nb_champs++;
			if ((*vm).nb_champs > 4)
				ft_exit_toomanychamp();
		}
	}
	check_multi_flag(vm);
}

void			ft_option(char ***argv, t_vm *vm)
{
	if (!(ft_strcmp(**argv, "-dump")))
	{
		*argv += 1;
		(*vm).flag_dump = 1;
		if (!(**argv))
			ft_exit_usage();
		(*vm).dump_cycle = ft_atoi_exit(**argv, "dump", NULL);
	}
	else if (!(ft_strcmp(**argv, "-v")))
		(*vm).visu = 1;
	else if (!(ft_strcmp(**argv, "-verbose")))
		(*vm).verbose = 1;
	else if (!(ft_strcmp(**argv, "-hex")))
		(*vm).flag_hex = 1;
	else if (!(ft_strcmp(**argv, "-live")))
		(*vm).flag_live = 1;
	else
		ft_exit_usage();
	*argv += 1;
}

/*
** FONCTION CREATE_CHAMPION
** Lire les arguments concernant le numero du joueur et verifier que ceux-ci
** sont valides.
** Creer le fichier binaire
** Lire le fichier binaire du champion et verifier que le fichier est valide
**		- Bon header
**		- Bonne size
** Si fichier valide, ecire les informations Name / Commentaires
*/

void			create_champion(char ***argv, t_champion **champion)
{
	t_champion	*new_elem;

	new_elem = new_champion();
	if (!(**argv))
		ft_exit_usage();
	ft_assign_pnumber(argv, champion, &new_elem);
	if (!(**argv))
		ft_exit_usage();
	new_elem->file = **argv;
	*argv += 1;
	new_elem->binary = ft_read_champion(new_elem->file, &new_elem->binary_len);
	check_binary(new_elem);
	ft_push_back_chmp(champion, new_elem);
}

void			ft_assign_pnumber(char ***argv, t_champion **champion,
	t_champion **new_elem)
{
	static int player_number = 0xFFFFFFFF;

	if (!(ft_strcmp(**argv, "-n")))
	{
		*argv += 1;
		if (!(**argv))
			ft_exit_usage();
		if (check_number(ft_atoi_exit(**argv, "-n", (*new_elem)->file),
		*champion))
			ft_exit_playernumber((*champion)->file);
		(*new_elem)->p_number = (ft_atoi(**argv));
		*argv += 1;
	}
	else
	{
		while (check_number(player_number, *champion))
			player_number--;
		(*new_elem)->p_number = player_number;
		player_number--;
	}
}

unsigned char	*ft_read_champion(char *file, size_t *binary_len)
{
	int				fd;
	int				rd;
	unsigned char	*binary;

	if (!(binary = (unsigned char *)malloc(BUFF_SIZE)))
		ft_exit_malloc();
	if (((fd = open(file, O_RDONLY)) == -1))
		ft_exit_nofile(file);
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
