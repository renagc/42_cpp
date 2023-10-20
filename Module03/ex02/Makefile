NAME = fragtrap

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all