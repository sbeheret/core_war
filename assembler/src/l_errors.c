#include "../includes/asm.h"

void    error_char(char c)
{
    ft_printf("\033[31mBad char %c\033[0;m\n", c);
    //free_all
    exit (0);
}

void    error_arg(char *s)
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
    //free_all
    exit (0);
}
