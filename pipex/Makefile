SRCS	= ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard SRCS/*/*/*.c}

bonus	= ${wildcard bonus/*.c} ${wildcard bonus/*/*.c} ${wildcard bonus/*/*/*.c}

NAME	= pipex

OBJ		= ${SRCS:.c=.o}

bonus_OBJ	= ${bonus:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g  -fsanitize=address #-O3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(bonus_OBJ)
	$(CC) $(CFLAGS) $(bonus_OBJ) -o $(NAME)

clean:
	rm -rf ${OBJ} $(bonus_OBJ)

fclean: clean
	rm -rf ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader -R CheckDefine SRCS/*
	norminette -R CheckForbiddenSourceHeader -R CheckDefine bonus/*
	norminette -R CheckDefine INCS/pipex.h

re: fclean all