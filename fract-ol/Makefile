SRCS	= ${wildcard SRCS/*.c}

NAME	= fractol

OBJ		= ${SRCS:.c=.o}

CC		= gcc

#CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address

%.o: %.c
	$(CC) -Wall -Wextra  -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)