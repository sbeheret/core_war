#include "../includes/asm.h"
#include "../includes/op.h"

static void    spaces(char **tab)
{
    int	y;

    y = 0;
	while (tab[y])
	{
		tab[y] = ft_strtrim(tab[y]);
		y++;
	}
}

static void    commas(char **tab)
{
    int	y;
    int x;

    y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == SEPARATOR_CHAR)
			{
				tab[y][x] = '\0';
				break;
			}
			x++;
		}
		y++;
	}
}

static void    comments(char **tab)
{
    int	y;

    y = 0;
    while (tab[y])
	{
		if (tab[y][0] == COMMENT_CHAR)
		{
			free(tab[y]);
			tab[y] = NULL;
			y++;
			while (tab[y])
			{
				free(tab[y]);
				y++;
			}
		}
		else
			y++;
	}
}

void trim_spaces_commas_comments(char **tab)
{
    spaces(tab);
    commas(tab);
    comments(tab);
}
