NAME = animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = main.cpp AAnimal.cpp Brain.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm $(NAME)

re: clean all

.PHONY: all re clean fclean