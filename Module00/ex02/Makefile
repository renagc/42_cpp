NAME = tests

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

SRC = Account.cpp tests.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

log:
	./$(NAME) | cut -c 19- > tests_without_timestamp.log && cut -c 19- 19920104_091532.log > template_without_timestamp.log
diff:
	@if diff "template_without_timestamp.log" "tests_without_timestamp.log"; then \
		echo "Files are the same."; \
	else \
		echo "Files are different."; \
	fi
clean:
	rm -rf $(OBJ)
	rm -rf template_without_timestamp.log tests_without_timestamp.log

fclean:clean
	rm -rf $(NAME)

re: fclean all