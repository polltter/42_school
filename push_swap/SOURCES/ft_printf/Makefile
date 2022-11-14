# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 17:51:42 by mvenanci          #+#    #+#              #
#    Updated: 2022/11/14 13:01:13 by mvenanci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf_numbers.c \
		ft_printf.c \
		ft_print_chars.c \
		print_x.c \

OBJS	= ${SRCS:.c=.o}

OBJSD	= ${SRCSF:.c=.o}

CC	= gcc

CFLAGS 	= -Wall -Werror -Wextra

RM		= rm -rf

LIBC	= ar rcs

INCS	= ft_printf.h


${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJSD} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re