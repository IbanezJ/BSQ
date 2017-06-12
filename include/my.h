/*
** my.h for my.h in /home/ibanez_j/CPE_2016_BSQ
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Dec 12 09:56:14 2016 Jean-Alexandre IBANEZ
** Last update Tue Dec 13 17:57:34 2016 Jean-Alexandre IBANEZ
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_max
{
  int	max_x;
  int	max_y;
  int	max_matrix;
}		t_max;

typedef struct	s_col_line
{
  int	col;
  int	line;
}		t_line;

int	my_strlen(char *str);
char    *full_buffer(char *filename, t_line *line);
void	my_printf(char *str, ...);
char	**array_2d(char *str, t_line *line);
int     nb_line(char *filename);
int	nb_column(char *filename);
void	my_putstr(char *str);
void	my_putchar(char c);
void	my_putstr(char *str);
void    free_array(char **array, int line);
int     size_nb(char *filename);
void    disp_array(char **test, t_line *line);
int     **tab(t_line *line);
int     **int_arr(char *str, t_line *line);
void    free_matrix(int **tab, int line);
int     **set_line_column(int **matrix, t_line *line);
int     **set_matrix(int **matrix, int **second, t_line *line);
t_max    disp_result(int **matrix, t_line *line);
char    **final(t_max max, char **array);

#endif
