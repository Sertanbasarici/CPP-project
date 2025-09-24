NAME = main
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

.o:.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re