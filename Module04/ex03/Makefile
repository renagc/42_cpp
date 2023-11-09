NAME = materia

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -I$(INC) -std=c++98 #-fsanitize=address -g

INC = inc/

SRC =	src/AMateria.cpp	src/LinkedList.cpp	src/Character.cpp	src/MateriaSource.cpp	src/Cure.cpp	src/Ice.cpp	src/Node.cpp src/main.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all
