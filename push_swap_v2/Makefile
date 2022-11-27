SRCS	= ${wildcard *.c} ${wildcard SOURCES/*/*.c}

CHECKER_SRCS	= ${wildcard checker_folder/*.c} ${wildcard checker_folder/*/*.c} /home/miguel/Documents/42_school/push_swap_v2/checker_folder/checker_moves.c \
					${wildcard /home/miguel/Documents/42_school/push_swap_v2/SOURCES/libft/*.c} \
					${wildcard /home/miguel/Documents/42_school/push_swap_v2/SOURCES/ft_printf/*.c} \
					/home/miguel/Documents/42_school/push_swap_v2/SOURCES/sort/split.c \
					/home/miguel/Documents/42_school/push_swap_v2/SOURCES/sort/p_swap_utils.c

OBJS	=${SRCS:.c=.o}

CHECKER_OBJS	=${CHECKER_SRCS:.c=.o}

NAME	= push_swap

CHECKER_NAME	= checker

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

dg:
		@${CC} -Wall -Werror -Wextra -g  ${SRCS} -o ${NAME}

${CHECKER_NAME}: ${CHECKER_OBJS}
		@${CC} ${CFLAGS} ${CHECKER_OBJS} -o ${CHECKER_NAME}
		
clean:
		@rm -rf ${OBJS}

clean_checker:
		@rm -rf ${CHECKER_OBJS}

fclean: clean
		@rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re