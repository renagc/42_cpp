NAME = brain

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -I$(INC) -std=c++98 #-fsanitize=address -g

INC = inc/

SRC =	src/AAnimal.cpp	src/Cat.cpp	src/Brain.cpp	src/Dog.cpp src/main.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all
