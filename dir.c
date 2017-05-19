/*
** dir.c for dir.c in /Users/taing_k/Desktop/octo/taing_k
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Fri Jan 22 16:06:05 2016 TAING Kevin
** Last update Fri Jan 22 16:06:06 2016 TAING Kevin
*/

#include "libmy.h"

void		mapList(char *path)
{
	DIR     *d;
	struct dirent *dir;

	if ((d = opendir(path)) != NULL)
	{
    	while ((dir = readdir(d)) != NULL)
    	{
    		if (dir->d_name[0] != '.')
    		{
	    		my_putchar('\t');
	    		my_putstr(dir->d_name);
	    		my_putchar('\n');
	    	}
    	}
    	closedir(d);
    }
}

int			nbFiles(char *path)
{
	DIR     *d;
	struct dirent *dir;
	int		i;

	i = 0;
	if ((d = opendir(path)) != NULL)
	{
    	while ((dir = readdir(d)) != NULL)
    	{
    		if (dir->d_name[0] != '.')
				i++;
    	}
    	closedir(d);
    }
    return (i);
}

char		*getFile(char *path, int n)
{
	DIR     *d;
	struct dirent *dir;
	int		i;

	i = 0;
	if ((d = opendir(path)) != NULL)
	{
    	while ((dir = readdir(d)) != NULL)
    	{
    		if (dir->d_name[0] != '.')
				i++;
			if (i == n)
				return (dir->d_name);
    	}
    	closedir(d);
    }
    return (NULL);
}
