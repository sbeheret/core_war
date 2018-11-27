#include "../includes/asm.h"

void trim_spaces(char **tab)
{
    int	y;

    y = 0;
	while (tab[y])
	{
		tab[y] = ft_strtrim(tab[y]);
		y++;
	}
}
