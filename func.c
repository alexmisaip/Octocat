/*
** func.c for func.c in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:06:12 2016 TAING Kevin
** Last update Fri Jan 22 16:06:14 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

void	disp(t_maze maze, int mode)
{
	t_coor i;

	my_putstr("\033c");
	for (i.y = 0; i.y < maze.height; i.y++)
	{
		for (i.x = 0; i.x < maze.width; i.x++)
		{
			if (maze.tab[i.x][i.y] == '#' && ((mode != 2 && mode != 3) || (mode == 3 && isOctoNear(maze, i))))
				my_putstr("\033[44m  \033[0m");
			else if (maze.tab[i.x][i.y] == '8')
				my_putstr("\033[33m88\033[0m");
			else if (maze.tab[i.x][i.y] == 'E')
				my_putstr("\033[42m  \033[0m");
			else if (maze.tab[i.x][i.y] == 'D' && (mode == 2 || (mode == 3 && !isOctoNear(maze, i))))
				my_putstr("\033[31;1mXX\033[0m");
			else if (maze.tab[i.x][i.y] == 'D' && ((mode != 2 && mode != 3) || (mode == 3 && isOctoNear(maze, i))))
				my_putstr("\033[44;31;1mXX\033[0m");
			else if (maze.tab[i.x][i.y] == 'W')
				my_putstr("\033[32;1m:D\033[0m");
			else if (maze.tab[i.x][i.y] == ' ' || mode == 2 || (mode == 3 && !isOctoNear(maze, i)))
				my_putstr("  ");
		}
		my_putchar('\n');
	}
}

int			width(char *file)
{
	char	c;
	int		f;
	int		i;
	int		ok;
	int		max;

	f = open(file, O_RDONLY, S_IREAD);
	i = 0;
	ok = 1;
	max = 0;
	while (read(f, &c, 1) && ok)
	{
		if (c == '\n')
		{
			if (i > max)
				max = i;
			i = 0;
		}
		else
			i++;
	}
	close(f);
	return (max);
}

int			height(char *file)
{
	char	c;
	int 	f;
	int 	i;

	f = open(file, O_RDONLY, S_IREAD);
	i = 0;
	while (read(f, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	close(f);
	return (i);
}

char		**readFile(char *file)
{
	int		f;
	int		i;
	int		j;
	char	c;
	t_maze	maze;

	if (!(f = open(file, O_RDONLY, S_IREAD)))
		my_putstr("Cannot open file.\n");
	maze.tab = allocMap(width(file), height(file));
	j = 0;
	i = 0;
	while (read(f, &c, 1))
	{
		if (c == '\n')
		{
			i = 0;
			j++;
		}
		else
			maze.tab[i++][j] = (c == 'S' ? '8' : c);
	}
	close(f);
	return (maze.tab);
}

void		emptyBuffer(char c)
{
	while (c != '\n' && c != EOF)
		c = getchar();
}
