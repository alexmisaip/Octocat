/*
** create.c for create.c in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:05:20 2016 TAING Kevin
** Last update Fri Jan 22 16:05:46 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

void		createMap(void)
{
	t_maze	maze;

	my_putstr("Choose the width and the height of your maze :\n");
	my_putstr("width : ");
	maze.width = readNumber(4);
	my_putstr("height : ");
	maze.height = readNumber(4);
	maze.tab = allocMap(maze.width, maze.height);
	fillMap(maze);
	editMap(maze);
	free(maze.tab);
}

void		fillMap(t_maze maze)
{
	int		i;
	int		j;

	for (i = 0; i < maze.width; i++)
		for (j = 0; j < maze.height; j++)
			maze.tab[i][j] = '#';
	maze.tab[0][0] = '8';
}

void		saveMap(t_maze maze)
{
	int		file;
	int		i;
	int		j;
	char	*name;

	name = nbToStr(nbFiles("maps/") + 1);
	i = my_strlen(name);
	my_strcpy(name + i, " - custom");
	file = open(my_strcat(my_strdup("maps/"), name),
		O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
	for (i = 0; i < maze.height; i++)
	{
		for (j = 0; j < maze.width; j++)
		{
			if (maze.tab[j][i] == '8')
				maze.tab[j][i] = 'S';
			write(file, &maze.tab[j][i], 1);
		}
		write(file, "\n", 1);
	}
	free(name);
}

void		editMap(t_maze maze)
{
	char	c;
	int		mode;

	c = 0;
	mode = 1;
	while (c != 'c' && c != 'x' && c != 'C' && c != 'X')
	{
		disp(maze, 0);
		emptyBuffer(c = getchar());
		if (c == 'z' || c == 'Z')
			mode = (mode == 3 ? 1 : mode + 1);
		move(maze, c, mode);
	}
	if (c == 'x' || c == 'X')
		saveMap(maze);
}
