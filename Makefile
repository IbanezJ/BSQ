##
## Makefile for Makefile in /home/ibanez_j/CPE_2016_BSQ
## 
## Made by Jean-Alexandre IBANEZ
## Login   <ibanez_j@epitech.net>
## 
## Started on  Mon Dec 12 16:39:00 2016 Jean-Alexandre IBANEZ
## Last update Mon Jun 12 12:37:30 2017 Jean-Alexandre IBANEZ
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror -g
CLFAGS	+= -ansi -pedantic
CFLAGS	+= -I./include/

NAME	= bsq

SRCS	= 	./srcs/full_buffer.c	\
	  	./srcs/main.c		\
	  	./srcs/my_put_2darray.c	\
		./srcs/my_dispfunc.c	\
		./srcs/my_strlen.c	\
		./srcs/change_int.c	\
		./srcs/bsq.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
