SRCS	= ${wildcard *.c} ${wildcard SOURCES/*/*.c}

OBJS	=${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		@rm -rf ${OBJS}

fclean: clean
		@rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re