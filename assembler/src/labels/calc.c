#include "../../includes/asm.h"

static int    count(int pos, t_labels *l)
{
    int    i;
    int    bytes;

    bytes = 0;
    i = 0;
    while (i < pos)
    {
        bytes += l->bytes;
        if (i + 1 < pos)
            bytes++;
        i++;
        l = l->next;
    }
    return (bytes);
}
//add support negative numbers when l->position < current_l->position
int    calc_bytes_till_label(t_labels *first_label, t_labels *current_l, int a)
{
    t_labels *l;
    int    i;

    l = first_label;
    i = 1;
    while (l)
    {
        if (ft_strequ(l->name, current_l->args[a] + 2))
        {
            if (l->position > current_l->position)
            {
                i += count(l->position - current_l->position, current_l);
            }
        }
        l = l->next;
    }
    return (i);
}
