/*
** func.h for func.h in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:06:19 2016 TAING Kevin
** Last update Fri Jan 22 16:06:20 2016 TAING Kevin
*/

#ifndef __FUNC_H__
#define __FUNC_H__

#include "libmy.h"
#include "struct.h"

void	disp(t_maze maze, int mode);
char	**readFile(char *file);
int		width(char *file);
int		height(char *file);
void	emptyBuffer(char c);
int		isDead(t_maze maze);
int		isOctoNear(t_maze maze, t_coor pos);
char	**allocMap(int w, int h);
int		readNumber(int min);
void	mapList(char *path);
int		nbFiles(char *path);
char	*getFile(char *path, int n);
char	*nbToStr(int n);

#endif
