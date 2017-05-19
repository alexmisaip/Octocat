/*
** libmy.h for libmy.h in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:06:43 2016 TAING Kevin
** Last update Fri Jan 22 16:06:44 2016 TAING Kevin
*/

#ifndef __LIBMY_H__
#define __LIBMY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>

#include "move.h"
#include "func.h"
#include "menu.h"
#include "create.h"

void    my_putchar(char c);
int     my_isneg(int n);
void    my_put_nbr(int nb);
void    my_swap(int *a, int *b);
void    my_putstr(char *str);
int     my_strlen(char *str);
int     my_getnbr(char *str);
char    *my_strcpy(char *dest, char *src);
char    *my_strncpy(char *dest, char *src, int n);
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strcat(char *str1, char *str2);
char    *my_strncat(char *str1, char *str2, int n);
char    *my_strstr(char *str, char *to_find);
char    *my_strdup(char *str);
char    **my_str_to_wordtab(char *str);

#endif
