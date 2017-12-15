int	count_square(char **grid, char value, int x, int y)
{
  int	i;
  int	j;
  int	v;
  int	k;

  v = 0;
  k = 0;
  i = x - (x % 3);
  j = y - (y % 3);
  while ((i + v) < (i + 3))
    {
      while ((j + k) < (j + 3))
	{
	  if (grid[i + v][j + k] == value)
	    return (1);
	  ++k;
	}
      k = 0;
      ++v;
    }
  return (0);
}

int	count_col(char **grid, char value, int col)
{
  int	i;
  int	occurence;

  i = 0;
  occurence = 0;
  while (i < 9)
    {
      if (grid[i][col] == value)
	return (1);
      ++i;
    }
  return (occurence);
}

int	count_line(char *line, char value)
{
  int	i;
  int	occurence;

  i = 0;
  occurence = 0;
  while (i < 9)
    {
      if (line[i] == value)
	return (1);
      ++i;
    }
  return (occurence);
}
