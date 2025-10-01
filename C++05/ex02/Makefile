CXX = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

TARGET = main

OBJS = $(SOURCES:.cpp=.o)

FILE = *_shrubbery

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)

fclean:
	@rm -fr $(OBJS) $(TARGET) $(FILE)

re: fclean all

.PHONY: all clean fclean re
