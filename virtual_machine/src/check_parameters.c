/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:12:42 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/22 17:34:50 by rfibigr          ###   ########.fr       */
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
	i = 1;
	while (argv[i])
	{
		ft_check_champion(argv[i]);
		i++;
	}
}

void	ft_check_champion(char *file)
{
	int				binary_len;
	unsigned char	*binary;

	binary_len = 0;
	binary = read_champion(file, &binary_len);
}

unsigned char	*read_champion(char *file, int *binary_len)
{
	int				fd;
	int				rd;
	int				i;
	unsigned char	*binary;

	binary_len = 0;
	if (!(binary = (unsigned char *)malloc(BUFF_SIZE)))
		ft_exit_malloc();
	if (((fd = open(file, O_RDONLY)) == -1))
		ft_exit_nofile(file);
	i = 0;
	while ((rd = read(fd, binary, BUFF_SIZE)) > 0)
	{
		if (rd == -1)
			ft_exit_nofile(file);
		binary_len += rd;
		if (!(binary = realloc(binary, *binary_len)))
			ft_exit_malloc();
	}
	return (binary);
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
