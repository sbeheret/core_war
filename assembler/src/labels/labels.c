#include "../../includes/asm.h"
#include "../../includes/op.h"

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
	if (len > 0 && l == 0)
		label->args = ft_strsplit(line[l] + len + 1, ' ');
	else
		label->args = ft_strsplit(line[l], ' ');
	trim_spaces_commas_comments(label->args);
	label->op_nb = find_op_nb(label->args[0]);
	label->args_start_line = l;
	label->position = y;
	return (label);
}

int	find_tokens_line(char **tab, int y, int x)
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

void		get_labels(t_data *d)
{
	int	y;
	int	len;
	int l;
	int	skip;

	y = 2;
	skip = y;
	d->op = get_op_tab();
	while (d->tab[y])
	{
		len = 0;
		while (ft_strchr(LABEL_CHARS, d->tab[y][len]))
            len++;
		if (d->tab[y][len] == LABEL_CHAR)
		{
			l = find_tokens_line(d->tab, y, len + 1);
        	add_to_label_list_end(d, make_label(d->tab + y, len, y - skip, l - y));
			y = l;
		}
		else if (d->tab[y][0] == COMMENT_CHAR ||
			ft_strstr(d->tab[y], NAME_CMD_STRING) ||
			ft_strstr(d->tab[y], COMMENT_CMD_STRING))
			skip++;
		else
			add_to_label_list_end(d, make_label(d->tab + y, 0, y - skip, 0));
		y++;
	}
	add_bytes(d);
	show_labels(d->first_label); //tmp
}

void show_labels(t_labels *l) //tmp
{
    t_labels *tmp;
	int		i;

    tmp = l;
	ft_putstr("\n\tLABELS\n\n");
    while (tmp)
    {
		i = 0;
        printf("NAME:\t\t%s\
		\nop_code:\t%s\
		\nop_nb:\t\t%i\
		\nargs:", tmp->name, tmp->args[i], tmp->op_nb);
		i++;
		while (tmp->args[i])
		{
	        printf("\t\t%s\n", tmp->args[i]);
			i++;
		}
        printf("position:\t%i\
		\nargs_line:\t%i\
		\nbytes:\t\t%i\n\n\n",\
		tmp->position, tmp->args_start_line, tmp->bytes);
		tmp = tmp->next;
    }
}
