/*
** my_put_2darray.c for my_put_2darray.c in /home/ibanez_j/CPE_2016_BSQ
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Dec 12 10:10:01 2016 Jean-Alexandre IBANEZ
** Last update Tue Dec 13 17:57:20 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

char	**alloc(t_line *line)
{
  char	**array;
  int	i;

  i = 0;
  array = malloc(sizeof(char*) * (line->line + 1));
  while (i < line->line + 1)
    {
      array[i] = malloc(sizeof(char) * (line->col + 1));
      i = i + 1;
    }
  return (array);
}

char	**array_2d(char *str, t_line *line)
{
  char	**array;
  int	x;
  int	y;
  int	i;

  array = alloc(line);
  x = 0;
  y = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  y = 0;
	  x = x + 1;
	  i = i + 1;
	}
      array[x][y] = str[i];
      y = y + 1;
      i = i + 1;
    }
  return (array);
}

void	free_array(char **array, int line)
{
  int	i;

  i = 0;
  while (i < line + 1)
    {
      free(array[i]);
      i = i + 1;
    }
  free(array);
}
