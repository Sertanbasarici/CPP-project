CXX = g++ 

FLAGS = -Wall -Wextra -Werror -std=c++98

file = *_shrubbery

SOURCES = main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

TARGET = main

OBJS = $(SOURCES:.cpp=.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS) $(file)

fclean:
	@rm -fr $(OBJS) $(TARGET) $(file)

re: fclean all

.PHONY: all clean fclean re
