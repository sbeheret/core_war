/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:01:16 by esouza            #+#    #+#             */
/*   Updated: 2018/11/21 12:52:59 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"

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
	while (argv[1][i] != '.' && i < PROG_NAME_LENGTH)
	{
		name[i] = argv[1][i];
		i++;
	}
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
	t_header *header = malloc(sizeof(t_header));

	check_args(argc, argv);
	stocor(name, argv);
	if (((fd = open(argv[1], O_NOFOLLOW | O_RDWR)) < 1))
		print_error_open();
	fd2 = open(name, O_RDWR | O_APPEND |  O_CREAT, RIGHTS);
	set_header(header);
	write(fd2, header, sizeof(t_header) + sizeof(char) * 8);
	get_data(fd);
	close(fd);
	close(fd2);
	free(header);
	return (0);
}