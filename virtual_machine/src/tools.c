/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:06:58 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/28 12:11:48 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.c"

void	print_ram(unsigned char *ram)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (!(i % 64))
		{
			ft_printf("\n");
			ft_printf("0X");
			ft_printf("%.4X : ", i);
		}
		ft_printf("%hhx", ram[i] / 16);
		ft_printf("%hhx", ram[i] % 16);
		ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

void	print_optab(void)
{
	int i = 0;
	while (i<17)
	{
		ft_printf("tab[%d]= {\"%s\", %d, {%d,%d,%d}, %d, %d, %s, %d, %d}\n",i, op_tab[i].name,op_tab[i].param_number, op_tab[i].param_type[0], op_tab[i].param_type[1], op_tab[i].param_type[2], op_tab[i].op_code, op_tab[i].cycle, op_tab[i].comment, op_tab[i].encoding_byte, op_tab[i].direct_octect);
		i++;
	}
}

void	print_memory(unsigned char *str, size_t size)
{
	size_t start;
	size_t i;

	start = 0;
	ft_printf("\n================ FT_PRINT_MEMORY =============\n");
	while (start < size)
	{
		ft_printf("%.10x :", start);
		i = start;
		while (i < start + 16 && i < size)
		{
			ft_printf("%hhx", str[i] / 16);
			ft_printf("%hhx", str[i] % 16);
			ft_putchar(' ');
			i++;
		}
		while (i < start + 16)
		{
			ft_putstr("   ");
			i++;
		}
		ft_putchar('|');
		i = start;
		while (i < start + 16 && i < size)
		{
			if (str[i] > 31 && str[i] < 127)
				ft_putchar(str[i]);
			else
				ft_putchar('.');
			i++;
		}
		ft_putchar('|');
		ft_putchar('\n');
		start += 16;
	}
	ft_printf("\n============= END FT_PRINT_MEMORY =============\n");
}

void	print_struct_vm(t_vm vm)
{
	t_champion *tmp;


	tmp = vm.champion;
	ft_printf("\n=============== STRUCT VM ===============\n");
	ft_printf("flag_dump = %d\n", vm.flag_dump);
	ft_printf("dump_cycle = %d\n", vm.dump_cycle);
	ft_printf("----------PROCESSUS LIST-----------\n");
	while (tmp)
	{
		ft_printf("-----------\n");
		ft_printf("name = %s\n",tmp->name);
		ft_printf("comment = %s\n",tmp->comment);
		ft_printf("file = %s\n",tmp->file);
		ft_printf("p_number = %#X\n",tmp->p_number);
		ft_printf("weight = %d\n",tmp->weight);
		ft_printf("-----------\n");
		tmp = tmp->next;
	}
	ft_printf("------END PROCESSUS LIST-----------\n");
	ft_printf("\n============= END STRUC VM  =============\n");

}
