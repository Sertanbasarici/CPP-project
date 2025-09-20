NAME = main
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

OBJS  = $(SRCS:.cpp =.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJS)
%.o: %.cpp Base.hpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJS)
fclean: clean
	rm -fr $(NAME)
re: fclean all

.PHONY: all clean fclean re
