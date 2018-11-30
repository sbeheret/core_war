#include "../includes/asm.h"

static void		add_to_label_list_end(t_data *d, t_labels *label)
{
	if (!d->first_label)
	{
		d->first_label = label;
		d->last_label = d->first_label;
	}
	else
	{
		d->last_label->next = label;
		d->last_label = d->last_label->next;
	}
}

static t_labels	*make_label(char **line, int len, int y, int l)
{
	t_labels		*label;

	label = ft_memalloc(sizeof(t_labels));
	if (len > 0)
    	label->name = strndup(line[0], len);
	else
		label->name = 0;
	label->args_start_line = l;
	label->position = y;
	label->bytes = 1;
	return (label);
}

int	find_args_line(char **tab, int y, int x)
{
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] != ' ' && ft_isprint(tab[y][x]))
				return (y);
			x++;
		}
		x = 0;
		y++;
	}
	return (y);
}

void		is_label(t_data *d, int *y, int len, int skip)
{
	int			l;
	t_labels	*lb;

	if (d->tab[*y][len + 1] && d->tab[*y][len + 1] != ' ' && d->tab[*y][len + 1] != '\t')
		error_char(d->tab[*y][len + 1]);
	l = find_args_line(d->tab, *y, len + 1);
	lb = make_label(d->tab + *y, len, *y - skip, l - *y);
	if (len > 0 && l - *y == 0)
	{
		len++;
		len += find_op_code(lb, d->tab[l] + len, d->op);
		lb->args = ft_strsplit(d->tab[l] + len, SEPARATOR_CHAR);
		trim_spaces(lb->args);
	}
	else
	{
		len = find_op_code(lb, d->tab[l], d->op);
		lb->args = ft_strsplit(d->tab[l] + len, SEPARATOR_CHAR);
		trim_spaces(lb->args);
	}
	add_to_label_list_end(d, lb);
	*y = l;
}

void	is_op_code(t_data *d, int y, int len, int skip)
{
	t_labels	*lb;

	lb = make_label(d->tab + y, 0, y - skip, 0);
	len = find_op_code(lb, d->tab[y], d->op);
	lb->args = ft_strsplit(d->tab[y] + len, SEPARATOR_CHAR);
	trim_spaces(lb->args);
	add_to_label_list_end(d, lb);
}

void		get_labels(t_data *d, int y)
{
	int	len;
	int	skip;

	skip = y;
	d->op = get_op_tab();
	while (d->tab[y])
	{
		len = 0;
		while (ft_strchr(LABEL_CHARS, d->tab[y][len]))
            len++;
		if (d->tab[y][len] == LABEL_CHAR)
			is_label(d, &y, len, skip);
		else if (d->tab[y][0] == COMMENT_CHAR ||
			ft_strstr(d->tab[y], NAME_CMD_STRING) ||
			ft_strstr(d->tab[y], COMMENT_CMD_STRING))
			skip++;
		else if (d->tab[y][len] == ' ')
			is_op_code(d, y, len, skip);
		else
			error_char(d->tab[y][len]);
		y++;
	}
	general_check(d);
	compliance_check(d);
	add_bytes(d);
	//printf("param %i\n", (int)d->op[5].params_types[0]);
	//printf("\nuntil label (in hex): %x\n",\
	//calc_bytes_till_label(d->first_label, d->first_label, 1));
	show_labels(d); //tmp
}

void	show_op_param_types(t_op *op) //tmp
{
	int	i;
	int	n;

	i = 0;
	while (op[i].id < 17)
	{
		n = 0;
		printf("%s :\t", op[i].name);
		while (n < op[i].params_nb)
		{
			printf("%i ", op[i].params_types[n]);
			n++;
		}
		printf("\n");
		i++;
	}
}

void show_labels(t_data *d) //tmp
{
    t_labels *tmp;
	int		i;

    tmp = d->first_label;
	ft_putstr("\n\tLABELS\n\n");
    while (tmp)
    {
		i = 0;
        printf("NAME:\t\t%s\
		\nop_code:\t%s\
		\nop_nb:\t\t%i\
		\nargs:", tmp->name, tmp->op_code, tmp->op_nb);
		while (tmp->args[i])
		{
	        printf("\t\t%s\n", tmp->args[i]);
			i++;
		}
        printf("position:\t%i\
		\nencoded_byte:\t%i\
		\nbytes:\t\t%i\n\n\n",\
		tmp->position, d->op[tmp->op_nb - 1].encoded_byte, tmp->bytes);
		tmp = tmp->next;
    }
	//show_op_param_types(d->op);
}
