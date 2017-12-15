#include <stdlib.h>
#include "my.h"

int		_chk_nbr_columns(char *input)
{
  int		idx;
  int		col;

  col = 0;
  idx = 0;
  while (input[idx])
    {
      col++;
      if ((col == 1 || col == 20) && input[idx] != '|')
	return (1);
      if (input[idx] == '\n')
	{
	  if (idx != 20 && col % 21 != 0)
	    return (1);
	  col = 0;
	}
      idx++;
    }
  return (0);
}

int		_chk_nbr_lines(char *input)
{
  int		idx;
  int		lines;

  lines = 0;
  idx = 0;
  while (input[idx])
    {
      if (input[idx] == '\n')
	lines++;
      idx++;
    }
  if (lines % 11 != 0)
    return (1);
  return (0);
}

int		_chk_separators(char *input)
{
  int		idx;
  int		line;
  int		col;

  line = 1;
  col = 0;
  idx = 0;
  while (input[idx])
    {
      col++;
      if (col == 1 && (line == 1 || line % 11 == 0))
	{
	  if (my_strncmp("|------------------|", input + idx, 20) != 0)
	    return (1);
	}
      if (input[idx] == '\n')
	{
	  col = 0;
	  line++;
	  if (line == 12)
	    line = 1;
	}
      idx++;
    }
  return (0);
}

int		_chk_spaces(char *input, int line, int col)
{
  int		idx;

  idx = 0;
  while (input[idx])
    {
      col++;
      if (line != 1 && line % 11 != 0)
	{
	  if (col % 2 == 0 && col % 20 != 0 && input[idx] != ' ')
	    return (1);
	}
      if (input[idx] == '\n')
	{
	  col = 0;
	  line++;
	  if (line == 12)
	    line = 1;
	}
      idx++;
    }
  return (0);
}

int		_chk_digits(char *input, int line, int col)
{
  int		idx;

  idx = 0;
  while (input[idx])
    {
      col++;
      if (line != 1 && line % 11 != 0)
	{
	  if (col != 1 && col != 21 && col % 2 == 1 &&
	      (input[idx] < '1' || input[idx] > '9') && input[idx] != ' ')
	    return (1);
	}
      if (input[idx] == '\n')
	{
	  col = 0;
	  line++;
	  if (line == 12)
	    line = 1;
	}
      idx++;
    }
  return (0);
}
