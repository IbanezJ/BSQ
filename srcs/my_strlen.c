/*
** my_strlen.c for my_strlen.c in /home/ibanez_j/CPE_2016_BSQ/include
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Dec 12 16:15:26 2016 Jean-Alexandre IBANEZ
** Last update Mon Dec 12 16:16:00 2016 Jean-Alexandre IBANEZ
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
