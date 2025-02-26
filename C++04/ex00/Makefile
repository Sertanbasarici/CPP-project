CXX = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

TARGET = main

OBJS = $(SOURCE:.cpp=.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)

fclean:
	@rm -fr $(OBJS) $(TARGET)

re:fclean all

.PHONY: all clean fclean re

