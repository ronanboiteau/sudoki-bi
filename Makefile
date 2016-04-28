##
## Makefile for sudoki-bi in /home/boitea_r
## 
## Made by Ronan Boiteau
## Login   <boitea_r@epitech.net>
## 
## Started on  Fri Feb 26 20:02:55 2016 Ronan Boiteau
## Last update Fri Apr 29 00:35:39 2016 Ronan Boiteau
##

NAME	 = sudoki-bi

IDIR	 = include/

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my

CC	 = gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

SDIR	 = src/
SRCS	 = $(SDIR)chk_file.c				\
	   $(SDIR)chk_map.c				\
	   $(SDIR)how_many.c				\
	   $(SDIR)main.c				\
	   $(SDIR)handle_borders.c			\
	   $(SDIR)solver.c				\
	   $(SDIR)tools_string.c

OBJS	 = $(SRCS:.c=.o)

RM	 = rm -f


all: $(LIB) $(NAME)

$(LIB):
	cd $(LDIR) && $(MAKE)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L lib -l $(LNAME)

clean:
	$(RM) $(OBJS)
	cd $(LDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd $(LDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
