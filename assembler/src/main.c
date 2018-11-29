/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:01:16 by esouza            #+#    #+#             */
/*   Updated: 2018/11/28 17:40:57 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		check_args(int argc, char **argv)
{
	int		len;

	if (argc != 2)
	{
		ft_putstr("\033[44m Usage: ./asm file.s \033[0;m\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 's' || argv[1][len - 2] != '.')
	{
		ft_putstr("\033[31mBad file format. Expected a '.s' file\033[0;m\n");
		exit(EXIT_FAILURE);
	}
}

static void		print_error_open(void)
{
	ft_putstr("\033[41m ERROR couldn't open file \033[0;m\n");
	exit(EXIT_FAILURE);
}

static void		stocor(char name[], char **argv)
{
	short	i;
	short	j;
	char	*p;

	i = 0;
	j = 0;
	p = ".cor";
	if (ft_strlen(argv[1]) > (FILE_NAME_LENGTH - 5))
	{
		ft_putstr("File name too long\n");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i] != '\0' && i < (FILE_NAME_LENGTH - 5))
	{
		name[i] = argv[1][i];
		i++;
	}
	i -= 2;
	while (p[j])
	{
		name[i] = p[j];
		i++;
		j++;
	}
	name[i] = '\0';
}

int				main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	name[PROG_NAME_LENGTH + 5];

	check_args(argc, argv);
	stocor(name, argv);
	if (((fd = open(argv[1], O_NOFOLLOW | O_RDWR)) < 1))
		print_error_open();
	fd2 = open(name, O_RDWR | O_APPEND |  O_CREAT, RIGHTS);
	get_data(fd, fd2);
	close(fd);
	close(fd2);
//	while (1) ;
	return (0);
}
