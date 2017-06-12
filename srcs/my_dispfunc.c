/*
** my_dispfunc.c for my_dispfunc.c in /home/ibanez_j/CPE_2016_BSQ/include
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Dec 12 11:21:46 2016 Jean-Alexandre IBANEZ
** Last update Mon Dec 12 11:22:53 2016 Jean-Alexandre IBANEZ
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
