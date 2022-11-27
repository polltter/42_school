SRCS	= ${wildcard *.c} ${wildcard SOURCES/*/*.c}

OBJS	=${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

dg:
		@${CC} -Wall -Werror -Wextra -g  ${SRCS} -o ${NAME}

clean:
		@rm -rf ${OBJS}

fclean: clean
		@rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re