/*
** full_buffer.c for full_buffer.c in /home/ibanez_j/CPE_2016_BSQ
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sun Dec 11 17:02:34 2016 Jean-Alexandre IBANEZ
** Last update Tue Dec 13 16:32:55 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int	nb_column(char *filename)
{
  int	compt;
  char	*buffer;
  int	fd;

  fd = open(filename, O_RDONLY);
  compt = 0;
  buffer = malloc(sizeof(char) * 2);
  buffer[0] = 'r';
  while (buffer[0] != '\n')
    {
      read(fd, buffer, 1);
      compt = compt + 1;
    }
  read(fd, buffer, 1);
  compt = 0;
  while (buffer[0] != '\n')
    {
      read(fd, buffer, 1);
      compt = compt + 1;
    }
  close(fd);
  free(buffer);
  compt = compt - 1;
  return (compt);
}

int	nb_line(char *filename)
{
  int	compt;
  char	buffer[1];
  int	fd;

  fd = open(filename, O_RDONLY);
  compt = 1;
  while (read(fd, buffer, 1) != 0)
    {
      if (buffer[0] == '\n')
	compt = compt + 1;
    }
  close(fd);
  return (compt - 2);
}

int	size_nb(char *filename)
{
  char	buffer[1];
  int	fd;
  int	compt;

  fd = open(filename, O_RDONLY);
  buffer[0] = 'e';
  compt = 0;
  while (buffer[0] != '\n')
    {
      compt = compt + 1;
      read(fd, buffer, 1);
    }
  return (compt);
}

char	*alloc_buffer(int col_line)
{
  char	*buffer;
  int	i;

  i = 0;
  buffer = malloc(sizeof(char) * col_line + 1);
  while (i < col_line + 1)
    {
      buffer[i] = 0;
      i = i + 1;
    }
  return (buffer);
}

char	*full_buffer(char *filename, t_line *line)
{
  int	col_line;
  int	fd;
  int	i;
  char	*buffer;

  i = 0;
  col_line = (line->line + 1) * (line->col + 2) - 1;
  fd = open(filename, O_RDONLY);
  buffer = alloc_buffer(col_line);
  while (i < col_line)
    {
      buffer[i] = 0;
      i = i + 1;
    }
  i = 0;
  while (i < size_nb(filename))
    {
      read(fd, buffer, 1);
      i = i + 1;
    }
  read(fd, buffer, col_line);
  close(fd);
  return (buffer);
}
