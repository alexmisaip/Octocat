/*
** menu.h for menu.h in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:07:17 2016 TAING Kevin
** Last update Fri Jan 22 16:07:18 2016 TAING Kevin
*/

#ifndef __MENU_H__
#define __MENU_H__

#include "libmy.h"
#include "struct.h"

int			menu(void);
void		start(t_maze maze, int mode);
void		printFile(char *name);
char		*changeMap(void);

#endif
