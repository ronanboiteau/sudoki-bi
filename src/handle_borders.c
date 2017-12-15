#include <stdlib.h>
#include "my.h"

char		**_get_invalid_map(char **map, char **map_clean)
{
  char		**invalid_map;

  if ((invalid_map = malloc(sizeof(char *) * (11 + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  invalid_map[0] = my_strdup("|------------------|");
  invalid_map[1] = my_strdup("| X X X X X X X X X|");
  invalid_map[2] = my_strdup("| X X X X X X X X X|");
  invalid_map[3] = my_strdup("| X X X X X X X X X|");
  invalid_map[4] = my_strdup("| X X X X X X X X X|");
  invalid_map[5] = my_strdup("| X X X X X X X X X|");
  invalid_map[6] = my_strdup("| X X X X X X X X X|");
  invalid_map[7] = my_strdup("| X X X X X X X X X|");
  invalid_map[8] = my_strdup("| X X X X X X X X X|");
  invalid_map[9] = my_strdup("| X X X X X X X X X|");
  invalid_map[10] = my_strdup("|------------------|");
  invalid_map[11] = NULL;
  my_free_2d_tab(map);
  my_free_2d_tab(map_clean);
  return (invalid_map);
}

char		**_get_raw_map(char **map_raw, char **map_clean)
{
  int		line_clean;
  int		col_clean;
  int		line_raw;
  int		col_raw;

  line_raw = 1;
  col_raw = 2;
  line_clean = 0;
  while (map_clean[line_clean])
    {
      col_clean = 0;
      while (map_clean[line_clean][col_clean])
	{
	  map_raw[line_raw][col_raw] = map_clean[line_clean][col_clean];
	  col_raw += 2;
	  col_clean++;
	  if (map_raw[line_raw][col_raw] == '\0')
	    {
	      line_raw++;
	      col_raw = 2;
	    }
	}
      line_clean++;
    }
  return (map_raw);
}

static char	*_get_line_clean(char *line_clean, char *line_raw)
{
  int		idx_raw;
  int		idx_clean;

  if ((line_clean = malloc(sizeof(char) * (20 + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  idx_clean = 0;
  idx_raw = 2;
  while (line_raw[idx_raw] && line_raw[idx_raw] != '\n')
    {
      if (line_raw[idx_raw] == ' ')
	line_clean[idx_clean] = '0';
      else
	line_clean[idx_clean] = line_raw[idx_raw];
      idx_raw += 2;
      idx_clean++;
    }
  line_clean[idx_clean] = '\0';
  return (line_clean);
}

char		**_remove_borders(char **map_raw)
{
  char		**map_clean;
  int		idx_raw;
  int		idx_clean;

  if ((map_clean = malloc(sizeof(char *) * (11 + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  idx_clean = 0;
  idx_raw = 1;
  while (idx_clean < 9)
    {
      map_clean[idx_clean] = _get_line_clean(map_clean[idx_clean],
					     map_raw[idx_raw]);
      idx_clean++;
      idx_raw++;
    }
  map_clean[idx_clean] = NULL;
  return (map_clean);
}
