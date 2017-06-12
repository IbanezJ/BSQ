/*
** bsq.c for bsq.c in /home/ibanez_j/CPE_2016_BSQ
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Dec 12 18:58:52 2016 Jean-Alexandre IBANEZ
** Last update Sat Dec 17 10:55:22 2016 Jean-Alexandre IBANEZ
*/

#include "my.h"

int	minimum(int a, int b, int c)
{
  int	x;

  x = a;
  if (x > b)
    x = b;
  if (x > c)
    x = c;
  return (x);
}

int	**set_line_column(int **matrix, t_line *line)
{
  int	**second;
  int	x;
  int	y;

  second = tab(line);
  x = 0;
  y = 0;
  while (x <= line->line)
    {
      second[x][0] = matrix[x][0];
      x = x + 1;
    }
  while (y <= line->col)
    {
      second[0][y] = matrix[0][y];
      y = y + 1;
    }
  return (second);
}

int	**set_matrix(int **matrix, int **second, t_line *line)
{
  int	x;
  int	y;

  x = 1;
  y = 1;
  while (x <= line->line)
    {
      while (y <= line->col)
	{
	  if (matrix[x][y] == 1)
	    second[x][y] = minimum(second[x][y - 1],
				   second[x - 1][y],
				   second[x - 1][y - 1]) + 1;
	  else
	    second[x][y] = 0;
	  y = y + 1;
	}
      y = 1;
      x = x + 1;
    }
  return (second);
}

t_max	disp_result(int **matrix, t_line *line)
{
  int	x;
  int	y;
  t_max	max;

  max.max_matrix = matrix[0][0];
  max.max_x = 0;
  max.max_y = 0;
  x = 0;
  y = 0;
  while (x <= line->line)
    {
      while (y <= line->col)
	{
	  if (max.max_matrix < matrix[x][y])
	    {
	      max.max_matrix = matrix[x][y];
	      max.max_x = x;
	      max.max_y = y;
	    }
	  y = y + 1;
	}
      y = 0;
      x = x + 1;
    }
  return (max);
}

char	**final(t_max max, char **array)
{
  int	y;
  int	x_tmp;
  int	y_tmp;

  y = max.max_y;
  x_tmp = max.max_x + 1 - max.max_matrix;
  y_tmp = max.max_y + 1 - max.max_matrix;
  while (max.max_x >= x_tmp)
    {
      while (max.max_y >= y_tmp)
	{
	  array[max.max_x][max.max_y] = 'x';
	  max.max_y = max.max_y - 1;
	}
      max.max_y = y;
      max.max_x = max.max_x - 1;
    }
  return (array);
}
