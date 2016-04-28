/*
** sudoki_chk.h for sudoki-bi in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Feb 26 20:57:58 2016 Ronan Boiteau
** Last update Sun Feb 28 15:14:04 2016 Ronan Boiteau
*/

#ifndef SUDOKI_CHK_H_
# define SUDOKI_CHK_H_

# define BUFF_SIZE (231)

int		_chk_digits(char *input, int line, int col);
int		_chk_map(char **map);
int		_chk_nbr_columns(char *input);
int		_chk_nbr_lines(char *input);
int		_chk_separators(char *input);
int		_chk_spaces(char *input, int line, int col);


#endif /* !SUDOKI_CHK_H_ */
