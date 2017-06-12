/*
** main.c for main.c in /home/ibanez_j/CPE_2016_BSQ
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sun Dec 11 17:05:54 2016 Jean-Alexandre IBANEZ
** Last update Sun Dec 18 10:59:08 2016 Jean-Alexandre IBANEZ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	disp_array(char **array, t_line *line)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (x != line->line)
    {
      write(1, array[x], line->col + 1);
      write(1, "\n", 1);
      x = x + 1;
      y = y + 1;
    }
}

int	check_error(int ac, char **av)
{
  char	buffer[1];
  int	fd;

  buffer[0] = '0';
  fd = open(av[1], O_RDONLY);
  if (ac != 2)
    return (84);
  if (read(fd, buffer, 1) == 0)
    return (84);
  return (0);
}

int	main(int ac, char **av)
{
  t_line	*line;
  char	**array;
  int	**second;
  int	**matrix;
  char	*str;

  if (check_error(ac, av) == 84)
    return (84);
  line = malloc(sizeof(t_line*));
  line->col = nb_column(av[1]);
  line->line = nb_line(av[1]);
  str = full_buffer(av[1], line);
  matrix = int_arr(str, line);
  array = array_2d(str, line);
  second = set_line_column(matrix, line);
  second = set_matrix(matrix, second, line);
  array = final(disp_result(second, line),
		array);
  disp_array(array, line);
  free_matrix(matrix, line->line);
  free(str);
  free_matrix(second, line->line);
  free_array(array, line->line);
  free(line);
  return (0);
}
