NAME	 = sudoki-bi

IDIR	 = include/
IDIR_MY	 = lib/my/include/

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my/

CC	 = gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

SRCS_DIR	= src/
SRCS_FILES	= chk_file.c		\
		  chk_map.c		\
		  how_many.c		\
		  main.c		\
		  handle_borders.c	\
		  solver.c		\
		  tools_string.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	 = $(SRCS:.c=.o)

RM	 = rm -f


all: $(LIB) $(NAME)

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L $(LDIR) -l $(LNAME)

clean:
	$(RM) $(OBJS)
	make -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re
