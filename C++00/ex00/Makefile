C++ = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = megaphone.cpp

TARGET = megaphone

OBJS = $(SOURCES:.cpp=.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(C++) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	@$(C++) $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)

fclean:
	@rm -fr $(OBJS) $(TARGET)

re: fclean all

.PHONY: all clean fclean re