SRCS	= ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard SRCS/*/*/*.c}

NAME	= pipex

OBJ		= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g  -fsanitize=address #-O3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader CheckDefine SRCS/*
	norminette -R CheckDefine INCS/pipex.h

re: fclean all