/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:00 by dshults           #+#    #+#             */
/*   Updated: 2018/12/13 14:44:34 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			error_op_code(char *s)
{
	int	i;

	i = 0;
	ft_putstr("Bad op_code " SET);
	while (s[i] && s[i] != ' ' && s[i] != '\t')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putstr(RESET);
	ft_putchar('\n');
	return (0);
}

int			error_args(char *s)
{
	int	i;

	i = 0;
	ft_putstr("Bad argument "SET);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putstr(RESET);
	ft_putchar('\n');
	return (0);
}

int			error_arg_type(char *arg, char *op_code)
{
	int	i;

	i = 0;
	ft_printf("For "S" the argument "S" ", op_code, arg);
	ft_putstr("is of incompatible type\n");
	return (0);
}

int			error_label(char *s)
{
	int	i;

	i = 0;
	ft_putstr("Bad label "SET);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putstr(RESET);
	ft_putchar('\n');
	return (0);
}

int			error_param_nb(char *op_code, int expected, int got)
{
	ft_printf("Bad number of parameters for "S" - ", op_code);
	ft_printf("expected "I", got "I"\n", expected, got);
	return (0);
}
