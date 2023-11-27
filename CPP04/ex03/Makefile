NAME = animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = AMateria.cpp Character.cpp ICharacter.cpp Ice.cpp Cure.cpp main.cpp \
		IMateriaSource.cpp MateriaSource.cpp lists.cpp

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm $(NAME)

re: clean all

.PHONY: all re clean fclean