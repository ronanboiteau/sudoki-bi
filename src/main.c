#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "sudoki_chk.h"
#include "sudoki_solver.h"

static void	_print_map(char **map)
{
  int		idx;

  idx = 0;
  while (map[idx])
    {
      my_printf("%s\n", map[idx]);
      idx++;
    }
  return ;
}

static char	*_chk_input(char *input)
{
  if (_chk_nbr_lines(input) == 1 || _chk_nbr_columns(input) == 1 ||
      _chk_separators(input) == 1 || _chk_spaces(input, 1, 0) == 1 ||
      _chk_digits(input, 1, 0) == 1)
    return (NULL);
  return (input);
}

static char	*_get_input(void)
{
  char		*input;
  char		*buf;
  int		idx;

  if ((buf = malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  if ((input = malloc(sizeof(char) * (BUFF_SIZE + 2))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  if ((idx = read(STDIN, input, BUFF_SIZE)) <= 0)
    my_exit(EXIT_FAILURE, "MAP ERROR\n");
  input[idx] = '\0';
  while ((idx = read(STDIN, buf, BUFF_SIZE)) > 0)
    {
      buf[idx] = '\0';
      input = my_realloc(input, BUFF_SIZE);
      input = my_strncat(input, buf, BUFF_SIZE);
    }
  idx = my_strlen(input);
  if (idx > 0 && input[idx - 1] && input[idx - 1] != '\n')
    input[idx++] = '\n';
  input[idx] = '\0';
  free(buf);
  return (input);
}

static char	**_get_next_map(char *input, int *idx_input)
{
  char		**map;
  int		idx;

  if (input[*idx_input] == '\0')
    return (NULL);
  if ((map = malloc(sizeof(char *) * (11 + 2))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  idx = 0;
  while (idx < 11)
    {
      if ((map[idx] = malloc(sizeof(char) * (20 + 1))) == NULL)
	my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
      map[idx] = my_strncpy(map[idx], input + *idx_input, 20);
      *idx_input += 21;
      idx++;
    }
  map[idx] = NULL;
  return (map);
}

int		main(void)
{
  char		*input;
  char		**map;
  int		nbr_map;
  int		idx_input;

  if ((input = _get_input()) == NULL)
    my_exit(EXIT_FAILURE, "MAP ERROR\n");
  if ((input = _chk_input(input)) == NULL)
    my_exit(EXIT_FAILURE, "MAP ERROR\n");
  idx_input = 0;
  nbr_map = 1;
  while ((map = _get_next_map(input, &idx_input)) != NULL)
    {
      if (nbr_map > 1)
  	my_printf("####################\n");
      map = _solve_sudoku(map);
      _print_map(map);
      my_free_2d_tab(map);
      nbr_map++;
    }
  free(input);
  return (EXIT_SUCCESS);
}
