CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME  = bureaucrats
SRC_DIR := src
INCLUDES_DIR := includes
INCLUDES := $(INCLUDES_DIR)/Bureaucrat.hpp \
$(INCLUDES_DIR)/Intern.hpp \
$(INCLUDES_DIR)/AForm.hpp \
$(INCLUDES_DIR)/ShrubberyCreationForm.hpp \
$(INCLUDES_DIR)/RobotomyRequestForm.hpp \
$(INCLUDES_DIR)/PresidentialPardonForm.hpp
SRCS := $(SRC_DIR)/main.cpp \
$(SRC_DIR)/Bureaucrat.cpp \
$(SRC_DIR)/Intern.cpp \
$(SRC_DIR)/AForm.cpp \
$(SRC_DIR)/ShrubberyCreationForm.cpp \
$(SRC_DIR)/RobotomyRequestForm.cpp \
$(SRC_DIR)/PresidentialPardonForm.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)
LDFLAGS :=

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

%.o: %.cpp $(INCLUDES) Makefile
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all
