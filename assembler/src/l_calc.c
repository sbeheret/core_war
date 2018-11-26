#include "../includes/asm.h"

static int    count(int pos, t_labels *l)
{
    int    i;
    int    bytes;

    bytes = 0;
    i = 0;
    while (i < pos)
    {
        bytes += l->bytes;
        i++;
        l = l->next;
    }
    return (bytes);
}

static int    rew_count(t_labels *f, int cp, int lp)
{
    int    bytes;

    bytes = 0;
    while (f && f->position < lp)
        f = f->next;
    while (f && f->position < cp)
    {
        bytes -= f->bytes;
        f = f->next;
    }
    return (bytes);
}

int    calc_bytes_till_label(t_labels *first_label, t_labels *current_l, int a)
{
    t_labels *l;
    int    i;

    l = first_label;
    i = 0;
    while (l)
    {
        if (ft_strequ(l->name, current_l->args[a] + 2))
        {
            if (l->position > current_l->position)
                i += count(l->position - current_l->position, current_l);
            else
                i += (unsigned int)rew_count(first_label,
                    current_l->position, l->position);
        }
        l = l->next;
    }
    return (i);
}
