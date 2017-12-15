#include "my.h"

t_uint		my_strlen_u(char *str)
{
  t_uint	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}
