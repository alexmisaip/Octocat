/*
** menu.c for menu.c in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:07:06 2016 TAING Kevin
** Last update Fri Jan 22 16:07:08 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

int		menu(void)
{
	char	input;

	my_putstr("\033c");
	printFile("menu.txt");

	while (1)
	{
		my_putstr(" >> ");
		emptyBuffer(input = getchar());
		if (input >= 'A' && input <= 'H')
			return (input - 'A');
		else if (input >= 'a' && input <= 'h')
			return (input - 'a');
		else
			return (-1);
	}
}

void		start(t_maze maze, int mode)
{
	char	c;
	int		res;
	int		lost;

	lost = 0;
	while (!(res = isDead(maze)) && lost == 0)
	{
		disp(maze, mode);
		c = getchar();
		if (mode == 0 || mode == 2 || mode == 3)
			emptyBuffer(0);
		move(maze, c, 0);
		if (mode == 1 && !isDead(maze) && c == '\n')
			lost = 1;
		if (mode == 1)
			usleep(100000);
	}
	disp(maze, mode);
	if (res == -1)
		my_putstr("You lose...\n");
	else if (lost == 1)
		my_putstr("You are lost in the maze...\n");
	else
		my_putstr("You win !\n");
	if (mode == 1)
		emptyBuffer(0);
	sleep(2);
}

void		printFile(char *name)
{
	int		f;
	char	c;

	my_putstr("\033c");
	f = open(name, O_RDONLY, S_IREAD);
	while (read(f, &c, 1))
	{
		if (c == '\\')
		{
			read(f, &c, 1);
			if (c == '0')
				my_putstr("\033[0m");
			else if (c == 'R')
				my_putstr("\033[31m");
			else if (c == 'G')
				my_putstr("\033[32m");
			else if (c == 'Y')
				my_putstr("\033[33m");
			else if (c == 'B')
				my_putstr("\033[34m");
			else if (c == 'V')
				my_putstr("\033[35m");
			else if (c == 'C')
				my_putstr("\033[36m");
			else if (c == '\\')
				my_putstr("\\");
		}
		else
			my_putchar(c);
	}
	close(f);
}

char		*changeMap(void)
{
	int 	i;
	char	*str;

	my_putstr("\033cSelect a map :\n");
	mapList("maps/");
	my_putstr(" >> ");

	i = 0;
	while (i < 1 || i > nbFiles("maps/"))
	{
		i = readNumber(1);
		if (i < 1 || i > nbFiles("maps/"))
		{
			my_putstr("Please enter a valid option.\n");
			sleep(1);
			my_putstr(" >> ");
		}
	}
	str = getFile("maps/", i);
	return (my_strcat(my_strdup("maps/"), str));
}
