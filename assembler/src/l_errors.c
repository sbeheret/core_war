#include "../includes/asm.h"

int    error_char(char c)
{
    ft_printf("\033[31mBad char %c\033[0;m\n", c);
    return (0);
}

int    error_op_code(char *s)
{
    int    i;

    i = 0;
    ft_putstr("\033[31mBad op_code ");
    while (s[i] && s[i] != ' ')
    {
        ft_putchar(s[i]);
        i++;
    }
    ft_putstr("\033[0;m");
    ft_putchar('\n');
    return (0);
}

int    error_args(char *s)
{
    int    i;

    i = 0;
    ft_putstr("\033[31mBad argument ");
    while (s[i] && s[i] != ' ')
    {
        ft_putchar(s[i]);
        i++;
    }
    ft_putstr("\033[0;m");
    ft_putchar('\n');
    return (0);
}

int    error_arg_type(char *arg, char *op_code)
{
    int    i;

    i = 0;
    ft_printf("\033[31mFor [%s] the argument [%s] ", op_code, arg);
    ft_putstr("is of incompatible type\033[0;m\n");
    return (0);
}

int    error_label(char *s)
{
    int    i;

    i = 0;
    ft_putstr("\033[31mBad label ");
    while (s[i] && s[i] != ' ')
    {
        ft_putchar(s[i]);
        i++;
    }
    ft_putstr("\033[0;m");
    ft_putchar('\n');
    return (0);
}

int    error_param_nb(char *op_code, int expected, int got)
{
    ft_printf("\033[31mBad number of parameters for %s - ", op_code);
    ft_printf("expected %i, got %i\033[0;m\n", expected, got);
    return (0);
}
