/*
** main.c for main.c in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:06:56 2016 TAING Kevin
** Last update Fri Jan 22 16:06:57 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

int			main(void)
{
	t_maze	maze;
	char	*fileName;
	int		i;
	int		choice;

	fileName = "maps/1 - Easy";
	while ((choice = menu()) != 7)
	{
		maze.tab = readFile(fileName);
		maze.width = width(fileName);
		maze.height = height(fileName);
		if (choice >= 0 && choice <= 3)
			start(maze, choice);
		else if (choice == 4)
		{
			printFile("ReadMe.txt");
			emptyBuffer(getchar());
		}
		else if (choice == 5)
			fileName = changeMap();
		else if (choice == 6)
			createMap();
		else if (choice == -1)
		{
			my_putstr("Please enter a valid option.\n");
			sleep(1);
		}
	}
	for (i = 0; i < maze.width; i++)
		free(maze.tab[i]);
	free(maze.tab);
	return (0);
}
