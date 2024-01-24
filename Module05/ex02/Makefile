NAME = ex02

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -I$(INC) -std=c++98 #-fsanitize=address -g

INC = inc/

SRC = src/main.cpp \
	  src/Bureaucrat.cpp \
	  src/AForm.cpp \
	  src/ShrubberyCreationForm.cpp \
	  src/RobotomyRequestForm.cpp \
	  src/PresidentialPardonForm.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all
