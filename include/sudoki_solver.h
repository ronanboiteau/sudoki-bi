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
