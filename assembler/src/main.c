/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:01:16 by esouza            #+#    #+#             */
/*   Updated: 2018/12/13 15:31:58 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		check_args(int argc, char **argv)
{
	int		len;

	if (argc != 2)
	{
		ft_putstr("\033[44m Usage: ./asm file.s \n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 's' || argv[1][len - 2] != '.')
	{
		ft_putstr("Bad file format. Expected a '.s' file\n");
		exit(EXIT_FAILURE);
	}
}

static void		print_error_open(void)
{
	ft_putstr("\033[41m ERROR couldn't open file \n");
	exit(EXIT_FAILURE);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		fd2;

	check_args(argc, argv);
	if (((fd = open(argv[1], O_NOFOLLOW | O_RDWR)) < 1))
		print_error_open();
	fd2 = 0;
	get_data(argv, fd, fd2);
	close(fd);
	close(fd2);
	return (0);
}
