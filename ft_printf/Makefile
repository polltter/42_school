# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 17:51:42 by mvenanci          #+#    #+#              #
#    Updated: 2022/10/18 17:55:32 by mvenanci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= find_params.c \
		ft_printf_numbers.c \
		ft_printf.c \
		helper_nbrs.c \
		ft_print_chars.c \
		print_x.c \
		print_p.c \
		ft_split_mod.c

SRCSF	=  ft_atoi.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_striteri.c \
		ft_bzero.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strdup.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_strmapi.c \
		ft_split.c \
		ft_toupper.c 

SRCSD	=$(addprefix libft/, $(SRCSF))

LIBFT	= libft/libft.a

OBJS	= ${SRCS:.c=.o}

OBJSD	= ${SRCSF:.c=.o}

CC	= gcc

CFLAGS 	= -Wall -Werror -Wextra

RM		= rm -rf

LIBC	= ar rcs

INCS	= ft_printf.h


${NAME}: libft.a
	cp ${LIBFT} .
	mv libft.a $(NAME)
	${CC} ${CFLAGS} -c ${SRCS} ${INCS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

test:	libft.a
	@${CC} ${CFLAGS} -c ${SRCS} test.c ${INCS}
	@${CC} ${CFLAGS} ${OBJS} test.o -L. ${LIBFT} -o a.out
	@./a.out | cat -e
	

clean:
	${RM} ${OBJS} ${OBJSD} 

libft.a:
	cd libft && ${MAKE} all

lib_fclean:
	cd libft && ${MAKE} fclean

fclean: clean lib_fclean
	${RM} ${NAME}
	
.PHONY: all, clean, fclean, re