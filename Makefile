# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 15:57:30 by cde-moul          #+#    #+#              #
#    Updated: 2019/01/14 10:42:17 by cde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = check.c	read.c	main.c check_part2.c game.c plateau.c  printtab.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror 

INC		=	-I libft

LIB		=	-Llibft/ -lft

all		: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	gcc $(FLAGS) $(INC) $(LIB) $(OBJS) -o $(NAME)

%.o		:	%.c fillit.h
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean	:
	rm -rf $(OBJS)
	make clean -C ./libft

fclean	: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a

re		: fclean all
