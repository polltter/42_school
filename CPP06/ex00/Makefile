NAME = scalar
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = ScalarConverter.cpp main.cpp

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm $(NAME)

re: clean all

.PHONY: all re clean fclean