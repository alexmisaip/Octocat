/*
** move2.c for move2.c in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:07:47 2016 TAING Kevin
** Last update Fri Jan 22 16:07:48 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

void		move(t_maze maze, char c, int mode)
{
	if (c == 'w' || c == 'W')
		moveUp(maze, mode);
	else if (c == 's' || c == 'S')
		moveDown(maze, mode);
	else if (c == 'a' || c == 'A')
		moveLeft(maze, mode);
	else if (c == 'd' || c == 'D')
		moveRight(maze, mode);
}

void		cchangePos(char **tab, t_coor Pos1, t_coor Pos2, int mode)
{
	if (tab[Pos1.x][Pos1.y] == '8')
	{
		tab[Pos2.x][Pos2.y] = '8';
		tab[Pos1.x][Pos1.y] = (mode == 1 ? ' ' : (mode == 2 ? '#' : 'E'));
	}
}
