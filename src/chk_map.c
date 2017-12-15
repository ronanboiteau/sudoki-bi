#include "my.h"

static int	_chk_line(char *line)
{
  int		idx;
  int		count;
  int		nbr;

  nbr = 1;
  while (nbr <= 9)
    {
      count = 0;
      idx = 0;
      while (line[idx])
	{
	  if (line[idx] - '0' == nbr)
	    count++;
	  idx++;
	}
      if (count > 1)
	return (1);
      nbr++;
    }
  return (0);
}

static int	_chk_col(char **map, int col)
{
  int		count;
  int		nbr;
  int		idx;

  nbr = 1;
  while (nbr <= 9)
    {
      count = 0;
      idx = 0;
      while (map[idx])
	{
	  if (map[idx][col] - '0' == nbr)
	    count++;
	  idx++;
	}
      if (count > 1)
	return (1);
      nbr++;
    }
  return (0);
}

static int	_chk_square(char **map, int line, int col, int nbr)
{
  int		count;
  int		idx_line;
  int		idx_col;

  while (nbr <= 9)
    {
      count = 0;
      idx_line = line;
      while (idx_line - line < 3)
	{
	  idx_col = col;
	  while (idx_col - col < 3)
	    {
	      if (map[idx_line][idx_col] - '0' == nbr)
		count++;
	      idx_col++;
	    }
	  idx_line++;
	}
      if (count > 1)
	return (1);
      nbr++;
    }
  return (0);
}

int		_chk_map(char **map)
{
  int		idx;

  idx = 0;
  while (map[idx])
    {
      if (_chk_line(map[idx]) == 1)
	return (1);
      idx++;
    }
  idx = 0;
  while (map[0][idx])
    {
      if (_chk_col(map, idx) == 1)
  	return (1);
      idx++;
    }
  if (_chk_square(map, 0, 0, 1) + _chk_square(map, 0, 3, 1) +
      _chk_square(map, 0, 6, 1) + _chk_square(map, 3, 0, 1) +
      _chk_square(map, 3, 3, 1) + _chk_square(map, 3, 6, 1) +
      _chk_square(map, 6, 0, 1) + _chk_square(map, 6, 3, 1) +
      _chk_square(map, 6, 6, 1) > 0)
    return (1);
  return (0);
}
