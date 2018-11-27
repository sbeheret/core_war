#include "../includes/asm.h"
//DIRECT_CHAR
//SEPARATOR_CHAR
//params_nb
//params_types T_REG T_DIR T_LAB
//REG_NUMBER

static int    l(t_labels *lb, char *str, int i, t_op *op)
{
    if (ft_strnstr(str + i, "live ", 5))
    {
        lb->op_code = op[0].name;
        lb->op_nb = op[0].id;
        return (i + 4);
    }
    else if (ft_strnstr(str + i, "ld ", 3))
    {
        lb->op_code = op[1].name;
        lb->op_nb = op[1].id;
        return (i + 2);
    }
    else if (ft_strnstr(str + i, "ldi ", 4))
    {
        lb->op_code = op[9].name;
        lb->op_nb = op[9].id;
        return (i + 3);
    }
    else if (ft_strnstr(str + i, "lld ", 4))
    {
        lb->op_code = op[12].name;
        lb->op_nb = op[12].id;
        return (i + 3);
    }
    else if (ft_strnstr(str + i, "lldi ", 5))
    {
        lb->op_code = op[13].name;
        lb->op_nb = op[13].id;
        return (i + 4);
    }
    else if (ft_strnstr(str + i, "lfork ", 6))
    {
        lb->op_code = op[14].name;
        lb->op_nb = op[14].id;
        return (i + 5);
    }
    else
        error_arg(str + i);
    return (0);
}

static int    s(t_labels *lb, char *str, int i, t_op *op)
{
    if (ft_strnstr(str + i, "st ", 3))
    {
        lb->op_code = op[2].name;
        lb->op_nb = op[2].id;
        return (i + 2);
    }
    else if (ft_strnstr(str + i, "sub ", 4))
    {
        lb->op_code = op[4].name;
        lb->op_nb = op[4].id;
        return (i + 3);
    }
    else if (ft_strnstr(str + i, "sti ", 4))
    {
        lb->op_code = op[10].name;
        lb->op_nb = op[10].id;
        return (i + 3);
    }
    else
        error_arg(str + i);
    return (0);
}

static int    a(t_labels *lb, char *str, int i, t_op *op)
{
    if (ft_strnstr(str + i, "add ", 4))
    {
        lb->op_code = op[3].name;
        lb->op_nb = op[3].id;
        return (i + 3);
    }
    else if (ft_strnstr(str + i, "and ", 4))
    {
        lb->op_code = op[5].name;
        lb->op_nb = op[5].id;
        return (i + 3);
    }
    else if (ft_strnstr(str + i, "aff ", 4))
    {
        lb->op_code = op[15].name;
        lb->op_nb = op[15].id;
        return (i + 3);
    }
    else
        error_arg(str + i);
    return (0);
}

static int    o_x_z(t_labels *lb, char *str, int i, t_op *op)
{
    if (str[i] == 'o')
    {
        if (ft_strnstr(str + i, "or ", 3))
        {
            lb->op_code = op[6].name;
            lb->op_nb = op[6].id;
            return (i + 2);
        }
        else
            error_arg(str + i);
    }
    else if (str[i] == 'x')
    {
        if (ft_strnstr(str + i, "xor ", 4))
        {
            lb->op_code = op[7].name;
            lb->op_nb = op[7].id;
            return (i + 3);
        }
        else
            error_arg(str + i);

    }
    else if (str[i] == 'z')
    {
        if (ft_strnstr(str + i, "zjmp ", 5))
        {
            lb->op_code = op[8].name;
            lb->op_nb = op[8].id;
            return (i + 4);
        }
        else
            error_arg(str + i);
    }
    return (0);
}

int    find_op_code(t_labels *lb, char *str, t_op *op)
{
    int    i;

    i = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (str[i] == 'l')
        return (l(lb, str, i, op));
    else if (str[i] == 's')
        return (s(lb, str, i, op));
    else if (str[i] == 'a')
        return (a(lb, str, i, op));
    else if (str[i] == 'o' || str[i] == 'x' || str[i] == 'z')
        return (o_x_z(lb, str, i, op));
    else
        error_arg(str + i);
    return (0);
}
