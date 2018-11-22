#include "../includes/asm.h"

int    add_args_bytes(char **s)
{
    int    i;
    int    bytes;

    i = 0;
    bytes = 0;
    while (s[i])
    {
        if (s[i][0] == DIRECT_CHAR)
            bytes += 4;
        else
            bytes += 2;
        i++;
    }
    return (bytes);
}

void    add_bytes(t_data *d)
{
    t_labels    *l;

    l = d->first_label;
    ft_printf("op_tab %s\n", d->op[1].name);
    while (l)
    {
        l->bytes = d->op[l->op_nb].bytes;
        if (l->op_nb == 1 || l->op_nb == 9 ||
            l->op_nb == 12 || l->op_nb == 15) //live zjmp fork lfork
            l->bytes += DIR_SIZE; //T_DIR
        else if (l->op_nb == 2) //ld
        {//T_IND | T_DIR, T_REG
            if (l->args[1][0] == DIRECT_CHAR)
                l->bytes += DIR_SIZE + 1;
            else
                l->bytes += IND_SIZE + 1;
        }
        else if (l->op_nb == 3) //st
        {//T_REG, T_IND | T_REG
            if (l->args[2][0] == 'r')
                l->bytes += 1 + 1;
            else
                l->bytes += 1 + IND_SIZE;
        }
        else if (l->op_nb == 4 || l->op_nb == 5) //add sub
            l->bytes += 1 + 1 + 1; //T_REG, T_REG, T_REG
        else if (l->op_nb == 6 || l->op_nb == 7 || l->op_nb == 8) //and or xor
        {//T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG
            if (l->args[1][0] == 'r')
                l->bytes += 1;
            else if (l->args[1][0] == DIRECT_CHAR)
                l->bytes += DIR_SIZE;
            else
                l->bytes += IND_SIZE;
            if (l->args[2][0] == 'r')
                l->bytes += 1;
            else if (l->args[2][0] == DIRECT_CHAR)
                l->bytes += DIR_SIZE;
            else
                l->bytes += IND_SIZE;
            l->bytes += 1;
        }   //-> add diff for lldi
        else if (l->op_nb == 10 || l->op_nb == 14) //ldi lldi  dir is treated as ind
        {//T_REG| T_IND | T_DIR, T_DIR | T_REG, T_REG
            if (l->args[1][0] == 'r')
                l->bytes += 1;
            else
                l->bytes += IND_SIZE;
            if (l->args[2][0] == 'r')
                l->bytes += 1;
            else
                l->bytes += IND_SIZE;
            l->bytes += 1;
        }
        else if (l->op_nb == 11) //sti  dir is treated as ind
        {//T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG
            l->bytes += 1;
            if (l->args[2][0] == 'r')
                l->bytes += 1;
            else
                l->bytes += IND_SIZE;
            if (l->args[3][0] == 'r')
                l->bytes += 1;
            else
                l->bytes += IND_SIZE;
        }
        else if (l->op_nb == 13) //lld
        {//T_DIR | T_IND, T_REG
            if (l->args[2][0] == DIRECT_CHAR)
                l->bytes += DIR_SIZE + 1;
            else
                l->bytes += IND_SIZE + 1;
        }
        else if (l->op_nb == 16) //aff   T_REG
            l->bytes += 1;
        l = l->next;
    }
}
