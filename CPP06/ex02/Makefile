NAME = base
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g #-std=c++98
SRC = Base.cpp main.cpp

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm $(NAME)

re: clean all

.PHONY: all re clean fclean