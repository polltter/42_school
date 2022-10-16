# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 17:51:42 by mvenanci          #+#    #+#              #
#    Updated: 2022/10/16 14:00:53 by mvenanci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintft.a

SRCS	= find_params.c \
		ft_printf_numbers.c \
		ft_printf.c \
		helper_nbrs.c \
		ft_print_chars.c \
		print_x.c \
		print_p.c \
		ft_split_mod.c

LIBFT	= libft/libft.a

OBJS	= ${SRCS:.c=.o}

CC	= gcc

CFLAGS 	= -Wall -Werror -Wextra

RM		= rm -rf

LIBC	= ar rcs

INCS	= ft_printf.h


${NAME}:
	${CC} ${CFLAGS} -c ${SRCS} ${INCS}
	${LIBC} ${NAME} ${OBJS}

test:	libft.a
	${CC} ${CFLAGS} -c ${SRCS} test.c ${INCS}
	${CC} ${CFLAGS} ${OBJS} test.o -L. ${LIBFT} -o a.out
	./a.out | cat -e

clean:
	${RM} ${OBJS}

libft.a:
	cd libft && ${MAKE} all

lib_fclean:
	cd libft && ${MAKE} fclean

.PHONY: all, clean, fclean, re