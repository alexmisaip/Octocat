/*
** move.h for move.h in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:07:38 2016 TAING Kevin
** Last update Fri Jan 22 16:07:39 2016 TAING Kevin
*/

#ifndef __MOVE_H__
#define __MOVE_H__

#include "libmy.h"
#include "struct.h"

void	move(t_maze maze, char c, int mode);
void	moveUp(t_maze maze, int create);
void	moveDown(t_maze maze, int create);
void	moveLeft(t_maze maze, int create);
void	moveRight(t_maze maze, int create);

void	changePos(char **tab, t_coor oldPos, t_coor newPos);
void	cchangePos(char **tab, t_coor Pos1, t_coor Pos2, int mode);

#endif
