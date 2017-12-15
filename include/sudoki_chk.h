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
