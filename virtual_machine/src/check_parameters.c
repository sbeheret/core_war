/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:12:42 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/22 18:47:52 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_parameters(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		ft_exit_usage();
	if (argc > 5)
		ft_exit_toomanychamp();
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
	ft_printf("binary = |%s|\nbinary_len = %d\n", binary, binary_len);
	check_binary(binary, binary_len);

	//save str and size in struct ?

}

unsigned char	*read_champion(char *file, int *binary_len)
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
	// FREE ?
	if (*binary_len < 2092)
		ft_exit_toosmall(file);
	return (binary);
}

void	check_binary(unsigned char *binary, int binary_len)
{
	// PROG_NAME_LENGTH			(128)
	// COMMENT_LENGTH			(2048)
	// COREWAR_EXEC_MAGIC		0xea83f3
	// CHAMP_MAX_SIZE			(MEM_SIZE / 6)
	// MEM_SIZE					(4 * 1024)
	int	i;

	i = 0;
	//4		compare COREWAR_EXEC_MAGIC
	//128	save name for the next PROG_NAME_LENGTH octet
	//4		verify octect padding
	//4		save programm length
	//2048	save comment for the next COMMENT_LENGTH
	//4		verify 4 octect padding
	//662		verify programm length is true
}
	//Error: File Untitled.cor has an invalid header
