/*
** move.c for move.c in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:07:28 2016 TAING Kevin
** Last update Fri Jan 22 16:07:30 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

void		moveUp(t_maze maze, int create)
{
	t_coor	Pos1;
	t_coor	Pos2;

	for (Pos1.x = 0; Pos1.x < maze.width; Pos1.x++)
	{
		for (Pos1.y = 0; Pos1.y < maze.height; Pos1.y++)
		{
			if (maze.tab[Pos1.x][Pos1.y] == '8')
			{
				Pos2.x = Pos1.x;
				Pos2.y = Pos1.y - 1;
				if (Pos2.x >= 0 && Pos2.y >= 0 &&
					Pos2.x < maze.width && Pos2.y < maze.height)
				{
					if (create)
						cchangePos(maze.tab, Pos1, Pos2, create);
					else
						changePos(maze.tab, Pos1, Pos2);
				}
				Pos1.x = maze.width;
				Pos1.y = maze.height;
			}
		}
	}
}

void		moveDown(t_maze maze, int create)
{
	t_coor	Pos1;
	t_coor	Pos2;

	for (Pos1.x = 0; Pos1.x < maze.width; Pos1.x++)
	{
		for (Pos1.y = 0; Pos1.y < maze.height; Pos1.y++)
		{
			if (maze.tab[Pos1.x][Pos1.y] == '8')
			{
				Pos2.x = Pos1.x;
				Pos2.y = Pos1.y + 1;
				if (Pos2.x >= 0 && Pos2.y >= 0 &&
					Pos2.x < maze.width && Pos2.y < maze.height)
				{
					if (create)
						cchangePos(maze.tab, Pos1, Pos2, create);
					else
						changePos(maze.tab, Pos1, Pos2);
				}
				Pos1.x = maze.width;
				Pos1.y = maze.height;
			}
		}
	}
}

void		moveLeft(t_maze maze, int create)
{
	t_coor	Pos1;
	t_coor	Pos2;

	for (Pos1.x = 0; Pos1.x < maze.width; Pos1.x++)
	{
		for (Pos1.y = 0; Pos1.y < maze.height; Pos1.y++)
		{
			if (maze.tab[Pos1.x][Pos1.y] == '8')
			{
				Pos2.x = Pos1.x - 1;
				Pos2.y = Pos1.y;
				if (Pos2.x >= 0 && Pos2.y >= 0 &&
					Pos2.x < maze.width && Pos2.y < maze.height)
				{
					if (create)
						cchangePos(maze.tab, Pos1, Pos2, create);
					else
						changePos(maze.tab, Pos1, Pos2);
				}
				Pos1.x = maze.width;
				Pos1.y = maze.height;
			}
		}
	}
}

void		moveRight(t_maze maze, int create)
{
	t_coor	Pos1;
	t_coor	Pos2;

	for (Pos1.x = 0; Pos1.x < maze.width; Pos1.x++)
	{
		for (Pos1.y = 0; Pos1.y < maze.height; Pos1.y++)
		{
			if (maze.tab[Pos1.x][Pos1.y] == '8')
			{
				Pos2.x = Pos1.x + 1;
				Pos2.y = Pos1.y;
				if (Pos2.x >= 0 && Pos2.y >= 0 &&
					Pos2.x < maze.width && Pos2.y < maze.height)
				{
					if (create)
						cchangePos(maze.tab, Pos1, Pos2, create);
					else
						changePos(maze.tab, Pos1, Pos2);
				}
				Pos1.x = maze.width;
				Pos1.y = maze.height;
			}
		}
	}
}

void	changePos(char **tab, t_coor Pos1, t_coor Pos2)
{
	if (tab[Pos1.x][Pos1.y] == '8')
	{
		if (tab[Pos2.x][Pos2.y] == ' ')
		{
			tab[Pos1.x][Pos1.y] = ' ';
			tab[Pos2.x][Pos2.y] = '8';
		}
		else if (tab[Pos2.x][Pos2.y] == 'E')
		{
			tab[Pos1.x][Pos1.y] = ' ';
			tab[Pos2.x][Pos2.y] = 'W';
		}
		else
		{
			tab[Pos1.x][Pos1.y] = ' ';
			tab[Pos2.x][Pos2.y] = 'D';
		}
	}
}
