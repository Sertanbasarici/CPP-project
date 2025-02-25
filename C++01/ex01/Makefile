C++ = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp Zombie.cpp zombieHorde.cpp

OBJS = $(SOURCES:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(C++) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	@$(C++) $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)

fclean:
	@rm -fr $(OBJS) $(TARGET)

re: fclean all

.PHONY: all clean fclean re