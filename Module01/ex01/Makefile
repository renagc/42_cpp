NAME = hordeofZombies

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -I$(INC) -std=c++98 #-fsanitize=address -g

INC = inc/

SRC = src/main.cpp src/Zombie.cpp src/zombieHorde.cpp 

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all
