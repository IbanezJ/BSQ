/*
** change_int.c for change_int.c in /home/ibanez_j/CPE_2016_BSQ
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Dec 12 18:35:22 2016 Jean-Alexandre IBANEZ
** Last update Tue Dec 13 17:11:22 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

int	**tab(t_line *line)
{
  int	**matrix;
  int	x;
  int	i;

  x = 0;
  i = 0;
  matrix = malloc(sizeof(int*) * (line->line + 1));
  while (i < line->line + 1)
    {
      matrix[i] = malloc(sizeof(int) * (line->col + 1));
      i = i + 1;
    }
  i = 0;
  while (i < line->line + 1)
    {
      while (x < line->col + 1)
	{
	  matrix[i][x] = 0;
	  x = x + 1;
	}
      x = 0;
      i = i + 1;
    }
  return (matrix);
}

int	**int_arr(char *str, t_line *line)
{
  int	**matrix;
  int	x;
  int	y;
  int	i;

  matrix = tab(line);
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
      if (str[i] == '.')
	matrix[x][y] = 1;
      else
	matrix[x][y] = 0;
      y = y + 1;
      i = i + 1;
    }
  return (matrix);
}

void	free_matrix(int **matrix, int line)
{
  int	i;

  i = 0;
  while (i < line + 1)
    {
      free(matrix[i]);
      i = i + 1;
    }
  free(matrix);
}
