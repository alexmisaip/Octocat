/*
** struct.h for struct.h in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:07:55 2016 TAING Kevin
** Last update Fri Jan 22 16:07:56 2016 TAING Kevin
*/

#ifndef __STRUCT_H__
#define __STRUCT_H__

#include "libmy.h"
#include "struct.h"

typedef struct	s_coor
{
	int			x;
	int			y;
}				t_coor;

typedef struct  s_maze
{
	char		**tab;
	int			width;
	int			height;
}				t_maze;

#endif
