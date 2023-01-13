SRCS	= ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard SRCS/*/*/*.c}

NAME	= pipex

OBJ		= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g -O3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader SRCS/*
	norminette -R CheckDefine INCS/*

re: fclean all