NAME = Fixed
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp
OBJ =  $(SRC:.cpp=.o)

$(NAME): ${OBJ}
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm ${OBJ}

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all re clean fclean