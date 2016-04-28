/*
** sudoki_solver.h for sudoki-bi in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Feb 26 21:00:01 2016 Ronan Boiteau
** Last update Fri Apr 29 00:33:21 2016 Ronan Boiteau
*/

#ifndef SUDOKI_SOLVER_H_
# define SUDOKI_SOLVER_H_

t_uint		my_strlen_u(char *str);
int		count_square(char **grid, char value, int x, int y);
int		count_col(char **grid, char value, int col);
int		count_line(char *line, char value);

typedef struct	s_idx
{
  int		x;
  int		y;
}		t_idx;

char		**_get_invalid_map(char **map, char **map_clean);
char		**_get_raw_map(char **map_raw, char **map_clean);
char		**_solve_sudoku(char **map);
char		**_remove_borders(char **map_raw);

#endif /* !SUDOKI_SOLVER_H_ */
