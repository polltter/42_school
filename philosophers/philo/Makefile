SRCS	= ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard SRCS/*/*/*.c}

NAME	= philo

OBJ		= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -pthread -g #-fsanitize=thread

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

p:
	./philo 5 800 200 200 7

r: all clean p

re: fclean all