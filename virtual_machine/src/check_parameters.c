/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:12:42 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/22 11:18:19 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_parameters(int argc, char **argv)
{
	int		i;

	if (argc < 2)
	{
		ft_printf("Usage : [..]");
		exit(0);
	}
	if (argc > 5)
	{
		ft_printf("Error : Too many champions");
		exit(0);
	}
	i = 0;
	while (argv[i])
	{
		// ft_check_champion(argv[i]);
		i++;
	}
}

void	ft_check_champion(char *file)
{
	(void)file;
	// int				fd;
	// int				read;
	// unsigned char	*binary;
	//
	// if (((fd = open(file, O_RDONLY)) == -1))
	// 	ft_exit_nofile(file);
	// if (((read = open(file, )) == -1))
	// 	ft_exit_nofile(file);
	//

}





	// Check length parameter < CHAMP_MAX_SIZE
	// Magic number
	// .Name 128 bytes + 1 (\n?)
	// padding 4 bytes
	// padding 4 size_number
	// .comment 2048 + 1 (\n?)
	// padding 12 bytes
	// programmes 662 bytes

	// Check arguments



	//Error: File bigzork.cor is too small to be a champion
	//Error: File Untitled.cor has an invalid header
