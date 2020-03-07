#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 09:19:10 by cde-moul          #+#    #+#              #
#    Updated: 2019/01/10 11:15:01 by cde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strstr.c \
	ft_strrchr.c ft_strchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_isascii.c  ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c ft_print_alphabet.c ft_reverse_alphabet.c ft_div_mod.c \
	ft_div.c ft_mod.c ft_putnbr_base.c ft_lstappend.c ft_lstsize.c \
	ft_fibonacci.c ft_recursive_factorial.c ft_recursive_power.c \
	ft_char_in_str.c

OBJS =	$(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra 

all:	$(NAME)

$(NAME) : $(OBJS) 
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o		:	%.c libft.h	
	@gcc -c $(FLAGS) $< -o $@
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
