/*
** solver.c for sudoki-bi in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Feb 26 21:06:12 2016 Ronan Boiteau
** Last update Sun Feb 28 21:16:23 2016 Ronan Boiteau
*/

#include "my.h"
#include "sudoki_chk.h"
#include "sudoki_solver.h"
#include <stdlib.h>

static int	find_j(int pos)
{
  int		j;
  int		i;

  i = (pos / 9);
  j = pos - (i * 9);
  return (j);
}

static int	do_the_sudoku(char **grid, int pos)
{
  t_idx		idx;
  char		j;

  if (pos == 81)
    return (1);
  idx.x = pos / 9;
  idx.y = find_j(pos);
  if (grid[idx.x][idx.y] != '0')
    return (do_the_sudoku(grid, (pos + 1)));
  j = '1';
  while (j <= '9')
    {
      if ((count_line(grid[idx.x], j) == 0) && (count_col(grid, j, idx.y) == 0)
	  && (count_square(grid, j, idx.x, idx.y) == 0))
	{
	  grid[idx.x][idx.y] = j;
	  if (do_the_sudoku(grid, (pos + 1)) == 1)
	    return (1);
	}
      ++j;
    }
  grid[idx.x][idx.y] = '0';
  return (0);
}

char		**_solve_sudoku(char **map)
{
  char		**map_clean;
  int		line;
  int		col;

  map_clean = _remove_borders(map);
  if (_chk_map(map_clean) == 1)
    return (_get_invalid_map(map, map_clean));
  do_the_sudoku(map_clean, 0);
  line = 0;
  while (map_clean[line])
    {
      col = 0;
      while (map_clean[line][col])
	{
	  if (map_clean[line][col] == '0')
	    return (_get_invalid_map(map, map_clean));
	  col++;
	}
      line++;
    }
  map = _get_raw_map(map, map_clean);
  my_free_2d_tab(map_clean);
  return (map);
}
