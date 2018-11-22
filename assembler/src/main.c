/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <esouza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:01:16 by esouza            #+#    #+#             */
/*   Updated: 2018/11/22 14:33:14 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

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
