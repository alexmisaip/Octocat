/*
** func2.c for func2.c in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:06:28 2016 TAING Kevin
** Last update Fri Jan 22 16:06:30 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

int		isDead(t_maze maze)
{
	int	i;
	int	j;

	for (i = 0; i < maze.width; i++)
		for (j = 0; j < maze.height; j++)
			if (maze.tab[i][j] == '8')
				return (0);
	for (i = 0; i < maze.width; i++)
		for (j = 0; j < maze.height; j++)
			if (maze.tab[i][j] == 'D')
				return (-1);
	return (1);
}

int		isOctoNear(t_maze maze, t_coor pos)
{
	int	x;
	int	y;

	for (x = -1; x <= 1; x++)
		for (y = -1; y <= 1; y++)
			if (pos.x + x >= 0 && pos.x + x < maze.width &&
				pos.y + y >= 0 && pos.y + y < maze.height &&
				maze.tab[pos.x + x][pos.y + y] == '8')
				return (1);
	return (0);
}

char		**allocMap(int w, int h)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(w * sizeof(char*));
	for (i = 0; i < w; i++)
		tab[i] = malloc(h * sizeof(char));
	return (tab);
}

int			readNumber(int min)
{
	char	*str;
	char	c;
	int		i;
	int		nb;

	str = malloc(sizeof(char) * 4);
	nb = 0;
	while (nb < min || nb > 99)
	{
		i = 0;
		while ((c = getchar()) != '\n' && i < 3)
			str[i++] = c;
		str[i] = '\0';
		if (c != '\n')
			emptyBuffer(0);
		nb = my_getnbr(str);
		if (nb < min || nb > 99)
		{
			my_putstr("Enter a number between ");
			my_put_nbr(min);
			my_putstr(" and 99 : ");
		}
	}
	free(str);
	return (nb);
}

char	*nbToStr(int n)
{
	int		i;
	int		j;
	int		m;
	char	*str;

	str = malloc(sizeof(char) * 11);
	i = 1;
	j = 0;
	if (n < 0)
		str[j++] = '-';
	n = (n < 0 ? n : -n);
	m = n;
	while (m <= -10)
	{
		i *= 10;
		m /= 10;
	}
	while (i)
	{
		str[j++] = (n / -i + '0');
		n %= i;
		i /= 10;
	}
	str[j] = '\0';
	return (str);
}
