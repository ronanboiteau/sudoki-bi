/*
** tools_string.c for sudoki-bi in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Feb 28 03:31:15 2016 Ronan Boiteau
** Last update Sun Feb 28 03:31:15 2016 Ronan Boiteau
*/

#include "my.h"

t_uint		my_strlen_u(char *str)
{
  t_uint	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}
