CXX = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp Form.cpp Bureaucrat.cpp

TARGET = main

OBJS = $(SOURCES:.cpp=.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)

fclean:
	@rm -fr $(OBJS) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
